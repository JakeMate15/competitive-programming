import sys
import math

input = sys.stdin.read
data = input().split()

index = 0
t = int(data[index])
index += 1

results = []

for _ in range(t):
    n = int(data[index])
    index += 1
    a = list(map(int, data[index:index + n]))
    index += n
    
    if n == 3:
        results.append("YES")
        continue
    
    def is_non_decreasing(arr):
        return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))
    
    b = [math.gcd(a[i], a[i + 1]) for i in range(n - 1)]
    
    if is_non_decreasing(b):
        results.append("YES")
        continue
    
    found = False
    
    for i in range(n):
        if i == 0:
            new_b = [math.gcd(a[j], a[j + 1]) for j in range(1, n - 1)]
        elif i == n - 1:
            new_b = [math.gcd(a[j], a[j + 1]) for j in range(n - 2)]
        else:
            new_b = [math.gcd(a[j], a[j + 1]) for j in range(i - 1)] + [math.gcd(a[j], a[j + 1]) for j in range(i + 1, n - 1)]
        
        if is_non_decreasing(new_b):
            found = True
            break
    
    if found:
        results.append("YES")
    else:
        results.append("NO")

sys.stdout.write("\n".join(results) + "\n")
