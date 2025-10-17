import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    a = rlist()

    bucket = [0] * (n + 2)
    for i in a:
        bucket[i] += 1

    for i in range(1, n + 1):
        if bucket[i] == 1:
            print("No")
            return
        elif bucket[i] > 2:
            bucket[i + 1] += bucket[i] - 2

    print("Yes")
    

for _ in range(rint()):
    solve()