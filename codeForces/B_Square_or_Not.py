import math
import sys
input = sys.stdin.read

data = input().split()
index = 0
t = int(data[index])
index += 1

results = []

for _ in range(t):
    n = int(data[index])
    s = data[index + 1]
    index += 2
    
    sq = int(math.sqrt(n))
    
    if sq * sq != n:
        results.append("No")
        continue
    
    ok = True
    for j in range(sq):
        if s[j] != '1' or s[(sq - 1) * sq + j] != '1':
            ok = False
            break
    
    for i in range(sq):
        if s[i * sq] != '1' or s[i * sq + sq - 1] != '1':
            ok = False
            break
    
    if ok:
        for i in range(1, sq - 1):
            for j in range(1, sq - 1):
                if s[i * sq + j] != '0':
                    ok = False
                    break
            if not ok:
                break
    
    if ok:
        results.append("Yes")
    else:
        results.append("No")

print("\n".join(results))