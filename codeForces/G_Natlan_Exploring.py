MAX_A = 1_000_001
MOD = 998244353

def compute_mobius(max_n):
    mobius = [1] * (max_n + 1)
    spf = [0] * (max_n + 1)  # Smallest prime factor
    for i in range(2, max_n + 1):
        if spf[i] == 0:
            spf[i] = i
            for j in range(2 * i, max_n + 1, i):
                if spf[j] == 0:
                    spf[j] = i
        if spf[i] == i:
            for j in range(i, max_n + 1, i):
                mobius[j] *= -1
            square = i * i
            for j in range(square, max_n + 1, square):
                mobius[j] = 0
    return mobius, spf

def get_unique_prime_factors(x, spf):
    factors = []
    while x > 1:
        p = spf[x]
        factors.append(p)
        while x % p == 0:
            x //= p
    return factors

def generate_square_free_divisors(primes):
    divisors = [1]
    for p in primes:
        sz = len(divisors)
        for i in range(sz):
            new_d = divisors[i] * p
            if new_d <= MAX_A:
                divisors.append(new_d)
    return divisors

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    a = [0] + list(map(int, data[1:]))
    
    mobius, spf = compute_mobius(MAX_A)
    
    sum_d = [0] * MAX_A
    dp = [0] * (n + 1)
    dp[1] = 1
    
    primes_a1 = get_unique_prime_factors(a[1], spf)
    divisors_a1 = generate_square_free_divisors(primes_a1)
    
    for d in divisors_a1:
        sum_d[d] += dp[1]
        if sum_d[d] >= MOD:
            sum_d[d] -= MOD
    
    total_sum = dp[1]
    
    for i in range(2, n + 1):
        primes_ai = get_unique_prime_factors(a[i], spf)
        divisors_ai = generate_square_free_divisors(primes_ai)
        sum_coprime = 0
        for d in divisors_ai:
            if mobius[d] == 1:
                sum_coprime += sum_d[d]
                if sum_coprime >= MOD:
                    sum_coprime -= MOD
            elif mobius[d] == -1:
                sum_coprime += MOD - sum_d[d]
                if sum_coprime >= MOD:
                    sum_coprime -= MOD
        
        dp[i] = (total_sum - sum_coprime) % MOD
        if dp[i] < 0:
            dp[i] += MOD
        
        for d in divisors_ai:
            sum_d[d] += dp[i]
            if sum_d[d] >= MOD:
                sum_d[d] -= MOD
        
        total_sum += dp[i]
        if total_sum >= MOD:
            total_sum -= MOD
    
    print(dp[n])

if __name__ == "__main__":
    main()
