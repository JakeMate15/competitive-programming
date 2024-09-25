import sys
import threading
import bisect

def main():
    import sys
    import sys
    sys.setrecursionlimit(1 << 25)
    from bisect import bisect_left, bisect_right

    class WaveletTree:
        __slots__ = ['lo', 'hi', 'left', 'right', 'B', 'S', 'a_value']

        def __init__(self, data, lo, hi, sorted_unique_a):
            self.lo = lo
            self.hi = hi
            self.left = None
            self.right = None
            self.B = []
            self.S = []
            self.a_value = 0
            if lo == hi or not data:
                if lo <= hi:
                    self.a_value = sorted_unique_a[lo -1]
                return
            mid = (lo + hi) //2
            self.B = [0]
            self.S = [0]
            left_data = []
            right_data = []
            for x in data:
                if x <= mid:
                    self.B.append(self.B[-1] +1)
                    left_data.append(x)
                else:
                    self.B.append(self.B[-1])
                    right_data.append(x)
                self.S.append(self.S[-1] + sorted_unique_a[x -1])
            self.left = WaveletTree(left_data, lo, mid, sorted_unique_a)
            self.right = WaveletTree(right_data, mid +1, hi, sorted_unique_a)

        def range_sum(self, l, r):
            if self.lo == self.hi:
                return self.a_value * (r - l +1)
            if not self.left and not self.right:
                return 0
            mid = (self.lo + self.hi) //2
            left_count = self.B[r] - self.B[l -1]
            left_sum = self.left.range_sum(self.B[l -1] +1, self.B[r]) if self.left else 0
            right_sum = self.right.range_sum(l - self.B[l -1], r - self.B[r]) if self.right else 0
            return left_sum + right_sum

        def sum_even_func(self, l, r, current_rank):
            if self.lo == self.hi:
                x = self.a_value
                cnt = r - l +1
                if current_rank %2 ==0:
                    return x * ((cnt +1) //2)
                else:
                    return x * (cnt //2)
            if not self.left and not self.right:
                return 0
            sum_e =0
            left_count = self.B[r] - self.B[l -1]
            if self.left:
                sum_e += self.left.sum_even_func(self.B[l -1] +1, self.B[r], current_rank)
            if self.right:
                sum_e += self.right.sum_even_func(l - self.B[l -1], r - self.B[r], current_rank + left_count)
            return sum_e

    import sys

    input = sys.stdin.read
    data = input().split()
    ptr =0
    t = int(data[ptr])
    ptr +=1
    for _ in range(t):
        n, q = int(data[ptr]), int(data[ptr+1])
        ptr +=2
        a = list(map(int, data[ptr:ptr+n]))
        ptr +=n
        sorted_unique_a = sorted(list(set(a)), reverse=True)
        U = len(sorted_unique_a)
        map_a = {x:i+1 for i,x in enumerate(sorted_unique_a)}
        mapped_data = [map_a[x] for x in a]
        wt = WaveletTree(mapped_data, 1, U, sorted_unique_a)
        for __ in range(q):
            l, r = int(data[ptr]), int(data[ptr+1])
            ptr +=2
            sum_total = wt.range_sum(l, r)
            sum_even = wt.sum_even_func(l, r, 1)
            if 2 * sum_even >= sum_total:
                print("YES")
            else:
                print("NO")

threading.Thread(target=main).start()
