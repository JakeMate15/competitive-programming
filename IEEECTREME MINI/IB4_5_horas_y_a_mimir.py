import sys, math

# input = lambda: sys.stdin.readline()
# rint = lambda: int(input())
# rvar = lambda: map(int, input().split())
# rlist = lambda: list(map(int, input().split()))

def solve():
    s = input("Ingresa 5 palabras separadas por comas: ")
    palabras = [palabra.strip() for palabra in s.split(',')]

    if len(palabras) != 5:
        print("Asegúrate de ingresar exactamente 5 palabras separadas por comas.")
    else:
        palabras_ordenadas = sorted(palabras)
        salida = ",".join(palabras_ordenadas)
        print(salida)
    

for _ in range(1):
    solve()