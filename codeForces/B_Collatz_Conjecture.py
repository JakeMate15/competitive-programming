import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    x, y, k = rvar()

    while x > 1:
        need = y if x % y == 0 else math.ceil(x / y) * y - x
        
        if need > k:
            print(x + k)
            return
        
        k -= need
        x += need

        while x % y == 0:
            x //= y

    print(1 + k % (y - 1))
        

for _ in range(rint()):
    solve()