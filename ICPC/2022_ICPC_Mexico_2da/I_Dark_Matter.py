s = input().strip()

num = s.split('+');

a = int(num[0])
b = int(num[1])

res = a + b + ((a * a + b * b) + (a - b) + abs(a) * 2 * b - (a * b + 2));
print(res)
