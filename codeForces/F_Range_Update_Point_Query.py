import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def sum_digits(n):
    return sum(int(d) for d in str(n))

class SegmentTree:
    def __init__(self, N):
        self.N = N
        self.ST = [0] * (2 * N)

    def update(self, l, r, value=1):
        l += self.N
        r += self.N
        while l < r:
            if l & 1:
                self.ST[l] += value
                l += 1
            if r & 1:
                r -= 1
                self.ST[r] += value
            l >>= 1
            r >>= 1

    def query(self, p, a):
        v = 0
        pos = p
        p += self.N
        while p > 0:
            v += self.ST[p]
            p >>= 1
        res = a[pos]
        for _ in range(v):
            if res < 10:
                break
            res = sum_digits(res)
        return res

def solve():
    n, q = rvar()
    a = rlist()
    st = SegmentTree(n)
    for _ in range(q):
        parts = input().strip().split()
        if not parts:
            parts = input().strip().split()
        op = int(parts[0])
        if op == 1:
            l = int(parts[1])
            r = int(parts[2])
            st.update(l - 1, r)
        else:
            x = int(parts[1])
            result = st.query(x - 1, a)
            print(result)

for _ in range(rint()):
    solve()
