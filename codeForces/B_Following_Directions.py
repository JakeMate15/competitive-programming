import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    s = input()[:-1]

    x, y = 0, 0
    for d in s:
        if d == 'U':
            y += 1
        elif d == 'D':
            y -= 1
        elif d == 'R':
            x += 1
        else:
            x -= 1

        if x == 1 and y == 1:
            print("YES")
            return

    print("NO") 
    

for _ in range(rint()):
    solve()