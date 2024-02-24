def calculate_months(A, B, C):
    months = 0  # Contador de meses
    currentApartments = 1  # Comenzamos con 1 apartamento
    totalIncome = 0  # Ingresos totales inicialmente son 0

    # Continuar hasta alcanzar o superar el número objetivo de apartamentos
    while currentApartments < C:
        months += 1  # Pasó un mes
        totalIncome += currentApartments * B  # Ingresos generados en este mes

        # Calcular cuántos apartamentos nuevos podemos comprar este mes
        newApartments = totalIncome // A

        # Actualizar el número de apartamentos en posesión y los ingresos totales
        currentApartments += newApartments
        totalIncome -= newApartments * A  # Pagar por los nuevos apartamentos

    return months

# Lectura de los valores de A, B, y C desde la entrada estándar
A = int(input())
B = int(input())
C = int(input())

# Llamada a la función y salida del resultado
print(calculate_months(A, B, C))
