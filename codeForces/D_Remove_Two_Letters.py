import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input()

    res = n - 1
    i = 1
    while(i < n - 1):
        if(s[i + 1] == s[i - 1]):
            res -= 1
        i += 1

    print(res)