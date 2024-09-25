t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    y_start = max(1, n - k + 1)
    y_end = n
    number_of_odds = ( (y_end + 1) // 2 ) - ( y_start // 2 )
    if number_of_odds % 2 == 0:
        print("YES")
    else:
        print("NO")
