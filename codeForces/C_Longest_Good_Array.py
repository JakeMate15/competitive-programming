import sys
input = sys.stdin.read
data = input().split()

def g(n):
    return n * (n + 1) // 2

index = 0
t = int(data[index])
index += 1

results = []
for _ in range(t):
    l = int(data[index])
    r = int(data[index + 1])
    index += 2
    
    tam = r - l

    lo = -1
    hi = 100000
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        s = g(mid)

        if s <= tam:
            lo = mid
        else:
            hi = mid
    
    results.append(hi)

for result in results:
    print(result)

