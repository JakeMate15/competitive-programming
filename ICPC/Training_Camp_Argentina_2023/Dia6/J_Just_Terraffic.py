import sys

mod = 1000000007

def sol():
    n, q = map(int, sys.stdin.readline().split())

    pref = [0] * n
    prefC = [0] * n

    a = list(map(int, sys.stdin.readline().split()))

    pref[0] = a[0]
    for i in range(1, n):
        pref[i] = pref[i-1] + a[i]
    prefC[0] = a[0] * a[0]
    for i in range(1, n):
        prefC[i] = prefC[i-1] + a[i] * a[i]

    for _ in range(q):
        l, r = map(int, sys.stdin.readline().split())
        l -= 1
        r -= 1
        ans = 0
        if l == 0:
            ans = (pref[r] * pref[r] - prefC[r]) // 2
        else:
            pL = pref[r] - pref[l-1]
            pC = prefC[r] - prefC[l-1]
            ans = (pL * pL - pC) // 2
        ans %= mod

        sys.stdout.write(str(ans) + '\n')


def main():
        n = int(sys.stdin.readline())
        t = list(map(int,sys.stdin.readline().split()))

        dif = [0]*(n-1)

        for i in range(1,n):
             dif[i-1] = abs(t[i]-t[i-1])

        camiones = 0
        autos = 0

        for i in range(0,n-1):
             

main()