#include <string.h>
#include <stdlib.h>

int minMoves(char** classroom, int classroomSize, int energy) {
    int m = classroomSize;
    int n = strlen(classroom[0]);
    int maxEnergy = energy;

    int sr = -1, sc = -1;
    int Lr[10], Lc[10];
    int numL = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char ch = classroom[i][j];
            if (ch == 'S') { sr = i; sc = j; }
            else if (ch == 'L') { Lr[numL] = i; Lc[numL] = j; numL++; }
        }
    }

    if (numL == 0) return 0;

    int fullMask = (1 << numL) - 1;
    int totalMaskStates = 1 << numL;
    int energyStates = maxEnergy + 1;

    int litterBit[20][20];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            litterBit[i][j] = -1;
    for (int k = 0; k < numL; k++)
        litterBit[Lr[k]][Lc[k]] = k;

    long long totalStates = (long long)m * n * totalMaskStates * energyStates;

    unsigned char* visited = (unsigned char*)calloc((totalStates / 8) + 1, 1);
    int* queue = (int*)malloc(sizeof(int) * (totalStates + 1));

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int initMask = (litterBit[sr][sc] != -1) ? (1 << litterBit[sr][sc]) : 0;

    #define ENC(r, c, mask, e) ((((long long)(r) * n + (c)) * totalMaskStates + (mask)) * energyStates + (e))
    #define VIS_GET(x) (visited[(x) >> 3] & (1 << ((x) & 7)))
    #define VIS_SET(x) (visited[(x) >> 3] |= (1 << ((x) & 7)))

    long long startEnc = ENC(sr, sc, initMask, maxEnergy);
    VIS_SET(startEnc);

    int head = 0, tail = 0;
    queue[tail++] = (int)startEnc;

    int moves = 0;

    while (head < tail) {
        int levelSize = tail - head;

        for (int s = 0; s < levelSize; s++) {
            long long enc = queue[head++];

            int e = enc % energyStates;
            long long t1 = enc / energyStates;
            int mask = t1 % totalMaskStates;
            long long t2 = t1 / totalMaskStates;
            int c = t2 % n;
            int r = (int)(t2 / n);

            if (mask == fullMask) {
                free(visited);
                free(queue);
                return moves;
            }

            int effEnergy = (classroom[r][c] == 'R') ? maxEnergy : e;
            if (effEnergy <= 0) continue;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;

                int newE = effEnergy - 1;
                int newMask = mask;
                if (litterBit[nr][nc] != -1) newMask |= (1 << litterBit[nr][nc]);

                long long nenc = ENC(nr, nc, newMask, newE);
                if (!VIS_GET(nenc)) {
                    VIS_SET(nenc);
                    queue[tail++] = (int)nenc;
                }
            }
        }

        moves++;
    }

    free(visited);
    free(queue);
    return -1;
}