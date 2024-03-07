n = int(input())
s = input().split()
ans = 0
cnt = [[0 for k in range(46)] for k in range(6)]
for y in s:
    cnt[len(y)][sum([int(c) for c in y])] += 1
for L in s:
    for lenr in range(len(L) % 2, len(L) + 1, 2):
        l = len(L) + lenr
        suml = sum([int(c) for c in L[:l // 2]])
        sumr = sum([int(c) for c in L[l // 2:]])
        if suml - sumr >= 0:
            ans += cnt[lenr][suml - sumr]
for R in s:
    for lenl in range(len(R) % 2, len(R), 2):
        l = len(R) + lenl
        suml = sum([int(c) for c in R[-l // 2:]])
        sumr = sum([int(c) for c in R[:-l // 2]])
        if suml - sumr >= 0:
            ans += cnt[lenl][suml - sumr]
print(ans)