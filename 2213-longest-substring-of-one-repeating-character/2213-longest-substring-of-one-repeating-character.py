from typing import List

class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        n = len(s)
        s = list(s)
        size = 4 * n
        length = [0] * size
        pre = [0] * size
        suf = [0] * size
        best = [0] * size
        lc = [''] * size
        rc = [''] * size

        def pull(node, l, r, mid):
            left, right = 2 * node, 2 * node + 1
            length[node] = length[left] + length[right]
            lc[node] = lc[left]
            rc[node] = rc[right]

            pre[node] = pre[left]
            if pre[left] == length[left] and rc[left] == lc[right]:
                pre[node] += pre[right]

            suf[node] = suf[right]
            if suf[right] == length[right] and lc[right] == rc[left]:
                suf[node] += suf[left]

            best[node] = max(best[left], best[right])
            if rc[left] == lc[right]:
                best[node] = max(best[node], suf[left] + pre[right])

        def build(node, l, r):
            if l == r:
                length[node] = pre[node] = suf[node] = best[node] = 1
                lc[node] = rc[node] = s[l]
                return
            mid = (l + r) // 2
            build(2 * node, l, mid)
            build(2 * node + 1, mid + 1, r)
            pull(node, l, r, mid)

        def update(node, l, r, idx, ch):
            if l == r:
                lc[node] = rc[node] = ch
                return
            mid = (l + r) // 2
            if idx <= mid:
                update(2 * node, l, mid, idx, ch)
            else:
                update(2 * node + 1, mid + 1, r, idx, ch)
            pull(node, l, r, mid)

        build(1, 0, n - 1)

        res = []
        for ch, idx in zip(queryCharacters, queryIndices):
            update(1, 0, n - 1, idx, ch)
            res.append(best[1])
        return res