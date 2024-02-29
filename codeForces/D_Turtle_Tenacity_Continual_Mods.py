t = int(input())  # Número de casos de prueba
for _ in range(t):
    n = int(input())  # Tamaño del array
    a = list(map(int, input().split()))  # El array
    
    # Comprobar si todos los números son 1
    if all(x == 1 for x in a):
        print("NO")
    else:
        print("YES")
