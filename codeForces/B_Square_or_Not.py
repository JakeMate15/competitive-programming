import sys, math

input = lambda: sys.stdin.readline()[:-1]
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    s = input()

    sq = int(math.sqrt(n))
    if sq * sq != n:
        print('No')
        return
    
    arr = [int(i) for i in s]
    aux = [0] * n

    for i in range(sq):
        for j in range(sq):
            if i == 0 or j == 0 or i == sq -1 or j == sq - 1:
                aux[i * sq + j] = 1


    if arr == aux:
        print('Yes')
    else:
        print('No')

    

for _ in range(rint()):
    solve()