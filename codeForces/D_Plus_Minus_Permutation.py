import math

def sol():
    n, x, y = map(int, input().split())

    mcd = math.lcm(x, y)
    juntos = n // mcd
    x = n // x
    y = n // y
    x -= juntos
    y -= juntos

    res = 0
    res -= (y * (y + 1)) // 2
    res += ((n - (n - x + 1) + 1) // 2) * ((n - x + 1) + n)
    print(res)

def main():
    t = 1
    t = int(input())
    for _ in range(t):
        sol()

main()
