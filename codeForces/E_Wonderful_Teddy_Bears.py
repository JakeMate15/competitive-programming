import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n=int(input())
    s=input().strip()
    p=0
    inv=0
    for c in s:
        if c=='P':
            p+=1
        else:
            inv+=p
    print((inv+1)//2)
