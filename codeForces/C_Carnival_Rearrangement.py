import sys

def main():
    import sys
    import threading
    def solve():
        import sys
        data = sys.stdin.read().split()
        idx = 0
        t = int(data[idx])
        idx +=1
        results = []
        for _ in range(t):
            n = int(data[idx])
            idx +=1
            arr = list(map(int, data[idx:idx+n]))
            idx +=n
            prefix1 = [0]*(n+1)
            prefix2 = [0]*(n+1)
            for i in range(n):
                prefix1[i+1] = prefix1[i] + (1 if arr[i]==1 else 0)
                prefix2[i+1] = prefix2[i] + (1 if arr[i]==2 else 0)
            total1 = prefix1[n]
            total2 = prefix2[n]
            min_option3 = float('inf')
            min_option4 = float('inf')
            for split in range(n+1):
                # Option3: all 1s then all 2s
                cost3 = prefix2[split] + (total1 - prefix1[split])
                if cost3 < min_option3:
                    min_option3 = cost3
                # Option4: all 2s then all 1s
                cost4 = prefix1[split] + (total2 - prefix2[split])
                if cost4 < min_option4:
                    min_option4 = cost4
            answer = min(min_option3, min_option4)
            results.append(str(answer))
        print(' '.join(results))
    threading.Thread(target=solve).start()
if __name__ == "__main__":
    main()
