def can_transform(n, a, b, m, d):
    from collections import defaultdict, deque

    required_changes = defaultdict(int)
    for i in range(n):
        if a[i] != b[i]:
            required_changes[b[i]] += 1

    available_operations = defaultdict(int)
    for value in d:
        available_operations[value] += 1

    for value, needed in required_changes.items():
        if available_operations[value] < needed:
            return "NO"
    return "YES"

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    t = int(data[index])
    index += 1
    results = []

    for _ in range(t):
        n = int(data[index])
        index += 1
        a = list(map(int, data[index:index + n]))
        index += n
        b = list(map(int, data[index:index + n]))
        index += n
        m = int(data[index])
        index += 1
        d = list(map(int, data[index:index + m]))
        index += m

        result = can_transform(n, a, b, m, d)
        results.append(result)

    for result in results:
        print(result)

if __name__ == "__main__":
    main()
