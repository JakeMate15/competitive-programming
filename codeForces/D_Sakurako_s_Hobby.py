import sys
input = sys.stdin.read
data = input().split()

index = 0
t = int(data[index])
index += 1

for _ in range(t):
    n = int(data[index])
    index += 1
    
    p = [0] * (n + 1)
    for i in range(1, n + 1):
        p[i] = int(data[index])
        index += 1
    
    s = data[index]
    index += 1

    cnt = 1
    color = [0] * (n + 1)
    res = [0] * (n + 1)
    
    for i in range(1, n + 1):
        if color[i]:
            continue

        curr = i
        while not color[curr]:
            color[curr] = cnt
            if s[curr - 1] == '0':
                res[cnt] += 1
            curr = p[curr]

        cnt += 1

    # print(f"color: {color[1:]}")
    # print(f"res: {res[1:]}")

    output = []
    for i in range(1, n + 1):
        who = color[i]
        print(res[who], end = ' ')
    
    print()