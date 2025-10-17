def solve():
    import sys
    input_data = sys.stdin.read().strip().split()
    t = int(input_data[0])
    idx = 1
    results = []
    for _ in range(t):
        n = int(input_data[idx]); idx+=1
        T = 2
        for _ in range(n):
            gate1_type = input_data[idx]; gate1_val = int(input_data[idx+1]); idx+=2
            gate2_type = input_data[idx]; gate2_val = int(input_data[idx+1]); idx+=2

            if gate1_type == '+' and gate2_type == '+':
                T = T + gate1_val + gate2_val
            elif gate1_type == '+' and gate2_type == 'x':
                # (+a, x b): T -> b*T + a
                T = gate2_val * T + gate1_val
            elif gate1_type == 'x' and gate2_type == '+':
                # (x a, +b): T -> a*T + b
                T = gate1_val * T + gate2_val
            else:
                # (x a, x b): T -> T * max(a, b)
                T = T * max(gate1_val, gate2_val)

        results.append(str(T))

    print('\n'.join(results))

solve()