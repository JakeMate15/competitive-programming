import random

n = random.randint(3, 20)
nums = [random.randint(1, 15) for _ in range(n)]
print(n)
print(*nums)
