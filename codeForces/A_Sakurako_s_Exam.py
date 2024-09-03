import sys
input = sys.stdin.read
data = input().split()

index = 0
t = int(data[index])
index += 1

results = []

for _ in range(t):
    a = int(data[index])
    b = int(data[index + 1])
    index += 2
    
    arr = [1] * a + [2] * b
    n = len(arr)
    total_combinations = 1 << n
    
    found = False
    for i in range(total_combinations):
        sum_value = 0
        for j in range(n):
            if i & (1 << j):
                sum_value += arr[j]
            else:
                sum_value -= arr[j]
        
        if sum_value == 0:
            results.append("YES")
            found = True
            break
    
    if not found:
        results.append("NO")

print("\n".join(results))