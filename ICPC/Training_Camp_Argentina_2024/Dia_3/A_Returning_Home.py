import heapq

def min_time_to_home(n, m, sx, sy, fx, fy, instant_moves):
    # Lista para almacenar todas las posiciones de interés: inicio, fin y puntos de movimiento instantáneo
    points = [(sx, sy, 0)]  # El tercer elemento es el tiempo para llegar a ese punto
    points.extend([(x, y, float('inf')) for x, y in instant_moves])
    points.append((fx, fy, float('inf')))
    
    # Diccionario para almacenar los vecinos de cada punto
    neighbors = {point: [] for point in points}
    
    # Añadimos vecinos para cada punto
    x_sorted = sorted(points, key=lambda p: p[0])
    y_sorted = sorted(points, key=lambda p: p[1])
    
    def add_neighbors(sorted_points, axis):
        for i in range(len(sorted_points) - 1):
            p1 = sorted_points[i]
            p2 = sorted_points[i + 1]
            if axis == 'x':
                distance = abs(p1[0] - p2[0])
            else:
                distance = abs(p1[1] - p2[1])
            neighbors[p1].append((p2, distance))
            neighbors[p2].append((p1, distance))
    
    add_neighbors(x_sorted, 'x')
    add_neighbors(y_sorted, 'y')
    
    # Dijkstra para encontrar la distancia mínima
    pq = [(0, (sx, sy, 0))]
    visited = set()
    
    while pq:
        current_time, current_point = heapq.heappop(pq)
        if current_point in visited:
            continue
        visited.add(current_point)
        x, y, _ = current_point
        if (x, y) == (fx, fy):
            return current_time
        for neighbor, distance in neighbors[current_point]:
            if neighbor not in visited:
                nx, ny, _ = neighbor
                if x == nx or y == ny:  # Movimiento instantáneo
                    new_time = current_time
                else:
                    new_time = current_time + distance
                heapq.heappush(pq, (new_time, (nx, ny, new_time)))
    
    return float('inf')

# Ejemplo de uso
n, m = 84, 5
sx, sy, fx, fy = 67, 59, 41, 2
instant_moves = [(39, 56), (7, 2), (15, 3), (74, 18), (22, 7)]

print(min_time_to_home(n, m, sx, sy, fx, fy, instant_moves))
