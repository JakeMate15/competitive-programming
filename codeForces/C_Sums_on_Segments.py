import sys, math

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def maxc(v):
    ans = 0
    current = 0
    for x in v:
        current += x
        if current < 0:
            current = 0
        ans = max(ans, current)
    return ans

def print_set(st):
    st_sorted = sorted(st)
    print(len(st_sorted))
    print(' '.join(map(str, st_sorted)))

def solve():
    N = rint()
    vl = rlist()

    id = -1
    for i in range(N):
        if vl[i] != 1 and vl[i] != -1:
            id = i
            break

    if id != -1:
        a = vl[:id]
        b = vl[id+1:]
    else:
        a = vl[:]
        b = []

    maxi = max(maxc(a), maxc(b))

    a_inv = [-x for x in a]
    b_inv = [-x for x in b]
    mini = max(maxc(a_inv), maxc(b_inv)) * -1

    st = set(range(mini, maxi + 1))

    if id == -1:
        print_set(st)
        return

    a_rev = a[::-1]

    sum_b = 0
    maxi_b = 0
    mini_b = 0
    for x in b:
        sum_b += x
        maxi_b = max(maxi_b, sum_b)
        mini_b = min(mini_b, sum_b)

    sum_a = 0
    maxia = 0
    minia = 0
    for x in a_rev:
        sum_a += x
        maxia = max(maxia, sum_a)
        minia = min(minia, sum_a)

    maxi_total = maxi_b + maxia
    mini_total = mini_b + minia

    delta = vl[id]
    st.update(range(mini_total + delta, maxi_total + delta + 1))

    print_set(st)
    

for _ in range(rint()):
    solve()
    