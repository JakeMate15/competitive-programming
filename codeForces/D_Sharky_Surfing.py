import sys
import heapq

def main():
    data = sys.stdin.read().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
        n = int(data[idx])
        m = int(data[idx + 1])
        L = int(data[idx + 2])
        idx += 3
        hurdles = []
        for _ in range(n):
            l = int(data[idx])
            r = int(data[idx + 1])
            hurdles.append((l, r))
            idx += 2
        powerups = []
        for _ in range(m):
            x = int(data[idx])
            y = int(data[idx + 1])
            powerups.append((x, y))
            idx += 2
        free_intervals = []
        previous_end = 1
        for l, r in hurdles:
            s = previous_end
            e = l - 1
            if s <= e:
                free_intervals.append((s, e))
            previous_end = r + 1
        if previous_end <= L:
            free_intervals.append((previous_end, L))
        current_k = 1
        collected_count = 0
        power_up_idx = 0
        pq = []
        impossible = False
        fi_size = len(free_intervals)
        for i in range(fi_size):
            s, e = free_intervals[i]
            while power_up_idx < m and powerups[power_up_idx][0] <= e:
                heapq.heappush(pq, -powerups[power_up_idx][1])
                power_up_idx += 1
            if i < fi_size - 1:
                next_s = free_intervals[i + 1][0]
                required = next_s - e
                if current_k >= required:
                    continue
                needed = required - current_k
                sum_added = 0
                while sum_added < needed and pq:
                    v = -heapq.heappop(pq)
                    sum_added += v
                    collected_count += 1
                if sum_added < needed:
                    impossible = True
                    break
                current_k += sum_added
        if impossible:
            print(-1)
        else:
            print(collected_count)

if __name__ == "__main__":
    main()
