import sys
import heapq
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    pq = []
    res = 0
    for x in a:
        if(x == 0):
            if(len(pq) > 0):
                res += -heapq.heappop(pq)
        else:
            heapq.heappush(pq, -x)

    print(res)