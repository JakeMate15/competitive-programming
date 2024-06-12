import math

def maximize_sauce_volume(N, cases):
    results = []
    for i in range(N):
        l, r = cases[i]
        
        # Función que calcula el volumen del sólido de revolución dado un ángulo theta
        def volume(theta):
            h = l * math.sin(theta)
            r1 = r + h / math.tan(theta)
            r2 = r - h / math.tan(theta)
            if r2 < 0:
                r2 = 0
            return (math.pi / 3) * h * (r1**2 + r2**2 + r1 * r2)
        
        # Maximización usando método de búsqueda ternaria
        left, right = 0, math.pi / 2
        for _ in range(100):
            theta1 = left + (right - left) / 3
            theta2 = right - (right - left) / 3
            if volume(theta1) < volume(theta2):
                left = theta1
            else:
                right = theta2
        
        optimal_theta = (left + right) / 2
        results.append(optimal_theta)
    
    return results

# Ejemplo de entrada
N = 3
cases = [(5, 5), (10, 53), (1000, 235)]

# Obtener los resultados
results = maximize_sauce_volume(N, cases)

# Imprimir los resultados
for result in results:
    print(result)
