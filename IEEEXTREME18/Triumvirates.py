import random
import math

def read_input():
    N = int(input().strip())
    points = [tuple(map(int, input().split())) for _ in range(N)]
    return N, points

def squared_distance(p1, p2):
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

def calculate_stability(triumvirate):
    p1, p2, p3 = triumvirate
    d1 = squared_distance(p1, p2)
    d2 = squared_distance(p1, p3)
    d3 = squared_distance(p2, p3)
    return max(d1, d2, d3) - min(d1, d2, d3)

def kmeans_plus_plus(points, k):
    n = len(points)
    clusters = []
    clusters.append(random.choice(points))
    
    for _ in range(k - 1):
        distances = [min(squared_distance(p, c) for c in clusters) for p in points]
        total_distance = sum(distances)
        probabilities = [d / total_distance for d in distances]
        cumulative_probs = [sum(probabilities[:i+1]) for i in range(len(probabilities))]
        r = random.random()
        for i, cum_prob in enumerate(cumulative_probs):
            if r <= cum_prob:
                clusters.append(points[i])
                break

    triumvirates = []
    for i in range(0, len(points), 3):
        triumvirates.append((i, (i + 1) % n, (i + 2) % n))
    
    return triumvirates

def refine_solution(groups, points):
    improved = True
    while improved:
        improved = False
        for i in range(len(groups)):
            for j in range(i + 1, len(groups)):
                for a in range(3):
                    for b in range(3):
                        new_groups = [list(g) for g in groups]
                        new_groups[i][a], new_groups[j][b] = new_groups[j][b], new_groups[i][a]
                        new_groups[i] = tuple(new_groups[i])
                        new_groups[j] = tuple(new_groups[j])
                        new_score = sum(calculate_stability((points[x], points[y], points[z])) for x, y, z in new_groups)
                        if new_score < sum(calculate_stability((points[x], points[y], points[z])) for x, y, z in groups):
                            groups = new_groups
                            improved = True
    return groups

def main():
    N, points = read_input()
    initial_groups = kmeans_plus_plus(points, N // 3)
    best_groups = refine_solution(initial_groups, points)
    for group in best_groups:
        print(group[0], group[1], group[2])

if __name__ == "__main__":
    main()
