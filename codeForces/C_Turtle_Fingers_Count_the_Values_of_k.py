import sys, math, collections

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def pow_mod(x, y):
    number = 1
    while y:
        if y & 1:
            number = number * x
        y >>= 1
        x = x * x
    return number
        

def solve():
    a, b, l = rvar()

    st = set()
    for i in range(0, 21):
        for j in range(0, 21):
            aa = int(pow_mod(a, i))
            bb = int(pow_mod(b, j))

            if aa * bb > l:
                break

            k = l // (aa * bb)
            if l == k * aa * bb:
                st.add(k)

    print(len(st))
    
for _ in range(rint()):
    solve()