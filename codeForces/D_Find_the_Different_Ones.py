def preprocesar(a):
    n = len(a)
    diffIndex = [n] * n  # Inicializar con n para indicar que no hay índice diferente
    lastSeen = {}
    
    for i in range(n - 1, -1, -1):
        if a[i] in lastSeen:
            diffIndex[i] = lastSeen[a[i]]
        lastSeen[a[i]] = i
        
    return diffIndex

def consulta(diffIndex, l, r):
    return diffIndex[l - 1] <= r - 1  # Ajuste para índices basados en 1

def main():
    t = int(input())  # Leer el número de casos de prueba
    for _ in range(t):
        n = int(input())  # Leer el tamaño del arreglo
        a = list(map(int, input().split()))  # Leer los elementos del arreglo
        diffIndex = preprocesar(a)  # Preprocesar el arreglo
        
        q = int(input())  # Leer el número de consultas
        for _ in range(q):
            l, r = map(int, input().split())  # Leer los índices l y r para la consulta actual
            # Verificar y mostrar el resultado de la consulta
            if consulta(diffIndex, l, r):
                print("YES")
            else:
                print("NO")

if __name__ == "__main__":
    main()
