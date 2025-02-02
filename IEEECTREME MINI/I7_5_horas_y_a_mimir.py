import sys, math

# input = lambda: sys.stdin.readline()
# rint = lambda: int(input())
# rvar = lambda: map(int, input().split())
# rlist = lambda: list(map(int, input().split()))

def solve():
    count = 25 
    
    def llenar(cantidad):
        nonlocal count
        if count + cantidad > 25:
            print("¡Límite de llenado alcanzado!")
            count = 25
        else:
            count += cantidad
    
    def vaciar(cantidad):
        nonlocal count
        if count - cantidad < 0:
            print("¡Vaso vacío alcanzado!")
            count = 0
        else:
            count -= cantidad
    
    def mostrar_vaso():
        if count == 0:
            print("Vaso vacío.")
            return
        filas = []
        full_rows = count // 5
        remainder = count % 5
        if remainder > 0:
            filas.append('*' * remainder)
        for _ in range(full_rows):
            filas.append('*' * 5)
        for fila in filas:
            print(fila)
    
    while True:
        entrada = input("Ingrese comando (Ej: Vaciar:6, Llenar:3) o 'Salir' para terminar: ").strip()
        if entrada.lower() == 'salir':
            break
        if ':' not in entrada:
            print("Formato inválido. Use 'Acción:Cantidad'.")
            continue
        accion, valor = entrada.split(':', 1)
        accion = accion.strip().lower()
        try:
            cantidad = int(valor.strip())
        except ValueError:
            print("Cantidad inválida. Debe ser un número entero.")
            continue
        if accion == 'llenar':
            llenar(cantidad)
        elif accion == 'vaciar':
            vaciar(cantidad)
        else:
            print("Acción desconocida. Use 'Llenar' o 'Vaciar'.")
            continue
        mostrar_vaso()
    
for _ in range(1):
    solve()