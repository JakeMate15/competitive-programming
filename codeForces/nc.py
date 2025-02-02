import random

t = 1
print(t)
for _ in range(t):
    print(''.join(random.choices('0123456789', k = 200000)))