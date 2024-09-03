class ModInt:
    def __init__(self, v, p):
        self.p = p
        self.v = v % p
        if self.v < 0:
            self.v += p

    def __add__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.v + other.v, self.p)
        else:
            return ModInt(self.v + other, self.p)

    def __sub__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.v - other.v, self.p)
        else:
            return ModInt(self.v - other, self.p)

    def __mul__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.v * other.v, self.p)
        else:
            return ModInt(self.v * other, self.p)

    def __truediv__(self, other):
        if isinstance(other, ModInt):
            return ModInt(self.v * pow(other.v, -1, self.p), self.p)
        else:
            return ModInt(self.v * pow(other, -1, self.p), self.p)

    def __neg__(self):
        return ModInt(-self.v, self.p)

    def __eq__(self, other):
        if isinstance(other, ModInt):
            return self.v == other.v
        else:
            return self.v == other

    def __repr__(self):
        return str(self.v)


import sys
input = sys.stdin.read
data = input().split()

MOD = 10**9 + 7

index = 0
t = int(data[index])
index += 1

for _ in range(t):
    n = int(data[index])
    index += 1
    a = list(map(int, data[index:index + n]))
    index += n
    
    sum_a = ModInt(0, MOD)
    ss = ModInt(0, MOD)

    for num in a:
        sum_a += num
        ss += ModInt(num, MOD) * num

    P = (sum_a * sum_a - ss) / ModInt(2, MOD)
    Q = ModInt(n * (n - 1) // 2, MOD)

    result = P / Q
    print(result)

