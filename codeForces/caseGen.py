import random

def generate_test_cases():
    t = random.randint(1, 10)  # Número de casos de prueba
    max_n = 50  # Máximo valor para n en cada caso
    total_n = 0  # Suma total de todos los n, no debe exceder 100000
    max_value = 10**9  # Máximo valor para los elementos del array
    
    test_cases = []
    
    for _ in range(t):
        n = random.randint(3, min(100, 100000 - total_n))
        if total_n + n > 100000:
            break
        total_n += n
        array = [random.randint(1, max_value) for _ in range(n)]
        test_cases.append((n, array))
    
    return t, test_cases

def print_test_cases(t, test_cases):
    print(t)
    for n, array in test_cases:
        print(n)
        print(" ".join(map(str, array)))

# Generar y imprimir casos de prueba
t, test_cases = generate_test_cases()
print_test_cases(t, test_cases)
