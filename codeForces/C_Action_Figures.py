t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    total_cost = 0
    group_cost = 0
    max_cost = 0
    count = 0
    for i in range(n):
        cost = i + 1  # cost of figure i (1-indexed)
        group_cost += cost
        max_cost = max(max_cost, cost)
        count += 1
        if s[i] == '1':
            if count >= 2:
                total_cost += group_cost - max_cost
            else:
                total_cost += group_cost
            group_cost = 0
            max_cost = 0
            count = 0
    print(total_cost)
