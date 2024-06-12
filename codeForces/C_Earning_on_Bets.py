from scipy.optimize import linprog

# Coeficientes de las variables en las desigualdades originales
A_ub = [
    [-26, 1, 1],  # x2 + x3 - 26x1 < 0
    [1, -40, 1],  # x1 + x3 - 40x2 < 0
    [1, 1, -11]   # x1 + x2 - 11x3 < 0
]

# Lado derecho de las desigualdades originales
b_ub = [0, 0, 0]

# Agregar restricciones adicionales para x1, x2, x3 >= 1
A_ub.extend([
    [-1, 0, 0],  # -x1 <= -1 (equivalente a x1 >= 1)
    [0, -1, 0],  # -x2 <= -1 (equivalente a x2 >= 1)
    [0, 0, -1]   # -x3 <= -1 (equivalente a x3 >= 1)
])
b_ub.extend([-1, -1, -1])

# Coeficientes de la función objetivo (puede ser cualquier función, aquí se minimiza 0 para obtener una solución factible)
c = [0, 0, 0]

# Resolver el problema de programación lineal
res = linprog(c, A_ub=A_ub, b_ub=b_ub, method='highs')

# Imprimir la solución
print('Solución:')
print('x1:', res.x[0])
print('x2:', res.x[1])
print('x3:', res.x[2])
print('Éxito:', res.success)
print('Mensaje:', res.message)
