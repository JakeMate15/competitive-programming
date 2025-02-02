import sys
import math

def main():
    import sys

    input = sys.stdin.read
    data = input().split()
    idx = 0
    t = int(data[idx])
    idx +=1
    for _ in range(t):
        n, m, k = map(int, data[idx:idx+3])
        idx +=3
        h = list(map(int, data[idx:idx+n]))
        idx +=n
        x = list(map(int, data[idx:idx+n]))
        idx +=n

        max_h = max(h)
        low = 1
        high = max_h
        answer = -1

        while low <= high:
            mid = (low + high) //2
            events = []
            possible = False
            for i in range(n):
                hi = h[i]
                xi = x[i]
                required_damage = (hi + mid -1) // mid
                if m - required_damage <0:
                    continue
                Li = xi - (m - required_damage)
                Ri = xi + (m - required_damage)
                events.append((Li, 1))
                events.append((Ri +1, -1))
            if not events:
                possible = False
            else:
                events.sort()
                coverage =0
                prev_pos = None
                for pos, delta in events:
                    if prev_pos is not None:
                        if coverage >=k:
                            if prev_pos <= pos -1:
                                possible = True
                                break
                    coverage += delta
                    prev_pos = pos
            if possible:
                answer = mid
                high = mid -1
            else:
                low = mid +1
        print(answer)

if __name__ == "__main__":
    main()
