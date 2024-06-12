def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    
    results = []
    
    for _ in range(T):
        N = int(data[index])
        M = int(data[index + 1])
        index += 2
        
        clauses = []
        for _ in range(M):
            a = int(data[index])
            b = int(data[index + 1])
            c = int(data[index + 2])
            index += 3
            clauses.append((a, b, c))
        
        # To make the expression odd, we need at least one clause to evaluate to 1.
        # Set all x's to 1 as a possible solution:
        # - x_a * x_b * x_c = 1 * 1 * 1 = 1 for all given clauses
        # We know this works trivially if we can do it.
        # Let's check if this is always possible.
        
        # We can safely set all variables to 1 and achieve sum to be odd if M > 0.
        if M > 0:
            results.append("YES")
            results.append("1 " * N)
        else:
            results.append("NO")
    
    print("\n".join(results))

