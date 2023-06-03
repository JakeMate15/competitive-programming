MOD = 10**9 + 7
fac = [1] * (10**6 + 5)


def calcF():
    for i in range(1, len(fac)):
        fac[i] = (fac[i - 1] * i) % MOD


def extendedEuclid(a, b):  # a * x + b * y = gcd(a, b)
    if b == 0:
        return 1, 0
    x, y = extendedEuclid(b, a % b)
    x, y = y, x - (a // b) * y
    if a * x + b * y == -gcd(a, b):
        x = -x
        y = -y
    return x, y


def inv(a, mod):  # inverse of a modulo mod
    assert gcd(a, mod) == 1
    sol = extendedEuclid(a, mod)
    return (sol[0] % mod + mod) % mod


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def main():
    n, k = map(int, input().split())

    a = list(map(int, input().split()))
    rep = {}
    for num in a:
        if num in rep:
            rep[num] += 1
        else:
            rep[num] = 1

    calcF()

    q = 1
    for x in rep.values():
        q *= fac[x]

    q %= MOD
    print((q * inv(fac[n], MOD) + MOD) % MOD)

    for _ in range(k):
        A, B = map(int, input().split())
        A -= 1

        keyR = a[A]
        if keyR != B:
            if B not in rep:
                rep[B] = 0
            if rep[keyR] == 0:
                q //= 1
            else:
                q //= rep[keyR]
            rep[keyR] -= 1
            rep[B] += 1
            q *= rep[B]
            q %= MOD
            a[A] = B

        print((q * inv(fac[n], MOD) + MOD) % MOD)


main()
