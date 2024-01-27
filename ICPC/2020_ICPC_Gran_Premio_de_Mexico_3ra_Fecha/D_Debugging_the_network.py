import sys
input = sys.stdin.readline

def sol(s, k):
    i = 0
    res = ""
    mx = k
    while i < len(s):
        curr = ""
        while i < len(s) and s[i].isdigit():
            curr += s[i]
            i += 1

        curr = "0" if curr == "" else curr
        num = int(curr)
        
        k -= num
        if (k < 0 or len(res) > mx):
            print("unfeasible")
            return
        
        num = 1 if num == 0 else num
        res += s[i] * num


        i += 1

    if (len(res) > mx):
        print("unfeasible")
    else:
        print(res)

    

for _ in range(int(input())):
    s, k = input().split()
    k = int(k)

    sol(s, k)


