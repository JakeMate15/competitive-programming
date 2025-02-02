import sys, heapq

input = lambda: sys.stdin.readline()
rint = lambda: int(input())
rvar = lambda: map(int, input().split())
rlist = lambda: list(map(int, input().split()))

def solve():
    n = rint()
    arr = rlist()
    
    pq = []
    ans = 0
    for x in arr:
        if x == 0:
            if len(pq) > 0:
                ans += -heapq.heappop(pq)
        else:
            heapq.heappush(pq, -x)

    print(ans)

for _ in range(rint()):
    solve()