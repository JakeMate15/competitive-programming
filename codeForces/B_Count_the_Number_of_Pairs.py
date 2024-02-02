import sys
input = sys.stdin.readline

def sol():
    n, k = map(int, input().split())
    s = input()
    
    minus = [0] * 26  
    mayus = [0] * 26  

    for c in s:
        if c.islower():
            index = ord(c) - ord('a')
            if 0 <= index < 26:
                minus[index] += 1
        else:
            c = c.lower()
            index = ord(c) - ord('a')
            if 0 <= index < 26:
                mayus[index] += 1

    letras = [0] * 26
    res = 0
    for i in range(26):
        res += min(minus[i], mayus[i])
        letras[i] = max(minus[i], mayus[i]) - min(minus[i], mayus[i])

    for i in range(26):
        if(k <= 0):
            break
        cuantos = letras[i] // 2
        res += min(cuantos, k)
        k -= min(cuantos, k)

    #print(letras)
    print(res)


for _ in range(int(input())):
    sol()