import heapq

def shortest_time_to_party(t, test_cases):
    results = []

    for case in test_cases:
        n, m, edges, slowness = case['n'], case['m'], case['edges'], case['slowness']

        # Creating the graph
        graph = {i: [] for i in range(1, n + 1)}
        for u, v, w in edges:
            time_u = w * slowness[u - 1]
            time_v = w * slowness[v - 1]
            graph[u].append((v, time_u))
            graph[v].append((u, time_v))

        # Dijkstra's algorithm to find shortest path
        distances = {i: float('inf') for i in range(1, n + 1)}
        distances[1] = 0
        pq = [(0, 1)]

        while pq:
            current_distance, current_node = heapq.heappop(pq)

            if current_distance > distances[current_node]:
                continue

            for neighbor, time in graph[current_node]:
                distance = current_distance + time
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))

        results.append(distances[n])

    return results

def main():
    t = int(input().strip())  # Number of test cases
    test_cases = []

    for _ in range(t):
        n, m = map(int, input().strip().split())
        edges = [tuple(map(int, input().strip().split())) for _ in range(m)]
        slowness = list(map(int, input().strip().split()))

        test_cases.append({'n': n, 'm': m, 'edges': edges, 'slowness': slowness})

    results = shortest_time_to_party(t, test_cases)
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
