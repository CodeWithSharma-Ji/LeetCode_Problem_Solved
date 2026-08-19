#include <stdlib.h>

int cmpRows(const void* a, const void* b) {
    int* ra = *(int**)a;
    int* rb = *(int**)b;
    if (ra[0] != rb[0]) return ra[0] - rb[0];
    return ra[1] - rb[1];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), cmpRows);

    const int LEFT  = 0x1E;
    const int MID   = 0x78;
    const int RIGHT = 0x1E0;

    long long total = 0;
    int rowsWithReservation = 0;
    int i = 0;

    while (i < reservedSeatsSize) {
        int row = reservedSeats[i][0];
        int mask = 0;
        while (i < reservedSeatsSize && reservedSeats[i][0] == row) {
            int seat = reservedSeats[i][1];
            mask |= (1 << (seat - 1));
            i++;
        }

        rowsWithReservation++;

        if ((mask & LEFT) == 0 && (mask & RIGHT) == 0) {
            total += 2;
        } else if ((mask & LEFT) == 0 || (mask & MID) == 0 || (mask & RIGHT) == 0) {
            total += 1;
        }
    }
    total += 2LL * (n - rowsWithReservation);

    return (int)total;
}