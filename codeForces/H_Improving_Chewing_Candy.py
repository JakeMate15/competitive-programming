from collections import deque

def sol():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    s = data[2]
    
    i = 0
    while i < n and s[i] == s[0]:
        i += 1
    t = s[i:] + s[:i]

    if i == n:
        print("-1")
        return
    
    pro = []
    qt = 1
    last = 0
    for j in range(1, len(t) * 2):
        if t[j % len(t)] == t[last % len(t)]:
            qt += 1
        else:
            pro.append((qt, last))
            qt = 1
            last = j
    pro.append((qt, last))

    i = 0
    j = 1
    cont = [0] * 26
    cont[ord(t[pro[0][1] % len(t)]) - ord('a')] = pro[0][0]
    big = ord(t[pro[0][1] % len(t)]) - ord('a')
    st = {(-cont[big], big)}
    sz = pro[0][0]
    best = -1
    inib = -1

    while i < len(pro):
        if -min(st)[0] <= k:
            if sz > best and sz <= n:
                best = sz
                inib = pro[i][1]
        if -min(st)[0] > k or j == len(pro):
            id = ord(t[pro[i][1] % len(t)]) - ord('a')
            st.discard((-cont[id], id))
            cont[id] -= pro[i][0]
            if cont[id] > 0:
                st.add((-cont[id], id))
            sz -= pro[i][0]
            i += 1
        else:
            id = ord(t[pro[j][1] % len(t)]) - ord('a')
            st.discard((-cont[id], id))
            cont[id] += pro[j][0]
            st.add((-cont[id], id))
            sz += pro[j][0]
            j += 1

    print(best)
    if best != -1:
        print(t[inib % len(t):(inib % len(t) + best)])

sol()
