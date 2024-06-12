def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    t = int(data[index])
    index += 1
    
    results = []
    
    for _ in range(t):
        N = int(data[index])
        index += 1
        A = list(map(int, data[index:index+N]))
        index += N
        
        # Track the number of shots and where they come from
        shots = []
        even_need = 0
        
        # Check feasibility
        possible = True
        
        for i in range(N):
            num_targets = A[i]
            if num_targets == 1:
                shots.append((i + 1, 1))  # lane index (1-based), number of shots
            elif num_targets > 1:
                if num_targets % 2 == 0:
                    shots.append((i + 1, num_targets))
                else:
                    shots.append((i + 1, num_targets))
                    even_need += 1  # Every odd count lane needs to end on an odd shot, hence an even shot is needed as an extra

        # If the number of lanes with an odd number of targets is even, we can manage, otherwise no
        if even_need % 2 != 0:
            possible = False
        
        if possible:
            results.append("YES")
            sequence = []
            for lane, count in shots:
                if count % 2 == 1:
                    sequence.extend([lane] * count)
                else:
                    sequence.extend([lane] * count)
            results.append(' '.join(map(str, sequence)))
        else:
            results.append("NO")
    
    sys.stdout.write("\n".join(results) + "\n")

solve()