import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = rlist()
    arr = [arr[0]] + sorted(arr[1:])
    print("Alice" if arr[0] > arr[1] else "Bob")

for _ in range(rint()):
    solve()