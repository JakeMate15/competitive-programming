import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = rlist()

    arr.sort()

    n = len(arr)
    i = 0
    j = 0
    max_len = 0

    while i < n - 1:
        while j < n - 1 and arr[i + 1] + arr[i] > arr[j]:
            j += 1
        current_len = j - i
        if current_len > max_len:
            max_len = current_len
        i += 1

    print(n - max_len)
    

for _ in range(rint()):
    solve()