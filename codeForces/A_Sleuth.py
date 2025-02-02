import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    vocales = 'aeiouy'
    s = input().lower()
    s = s.replace(' ', '')
    # print(s)
    
    if s[-3] in vocales:
        print("YES")
    else:
        print("NO")
    

for _ in range(1):
    solve()