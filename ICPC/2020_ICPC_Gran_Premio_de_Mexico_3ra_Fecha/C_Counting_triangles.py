import sys
input = sys.stdin.readline

def sol():
    n, k = map(int, input().split())
    res = ((n + 1) * (n + 2) // 2) * (k + 1)
    print(res % 1000000007)

for _ in range(int(input())):
    sol()