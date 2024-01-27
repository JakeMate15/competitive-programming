import sys
input = sys.stdin.readline

def f(v):
    if (v >= 500):
        return v - 100
    else :
        return v

a, b, c = map(int, input().split())
print(min(
        f(a + b + c), 
        f(a) + f(b) + f(c),
        f(a + b) + f(c),
        f(a + c) + f(b),
        f(c + b) + f(a)
    ))
