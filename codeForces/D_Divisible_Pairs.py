def count_beautiful_pairs(test_cases):
    results = []
    for n, x, y, a in test_cases:
        # Initialize dictionaries to store counts of remainders modulo x and y
        mod_x_counts = {}
        mod_y_counts = {}
        
        # Fill the dictionaries with initial counts
        for num in a:
            rx, ry = num % x, num % y
            mod_x_counts[rx] = mod_x_counts.get(rx, 0) + 1
            mod_y_counts[ry] = mod_y_counts.get(ry, 0) + 1
        
        beautiful_pairs = 0
        
        # Iterate through the array to count beautiful pairs
        for num in a:
            rx, ry = num % x, num % y
            
            # Count pairs for sum condition
            target_rx = (x - rx) % x  # Complement remainder for sum to be divisible by x
            sum_pairs = mod_x_counts.get(target_rx, 0)
            if rx == target_rx:  # Adjust count to avoid double counting
                sum_pairs -= 1
            
            # Count pairs for difference condition
            diff_pairs = mod_y_counts[ry] - 1  # Exclude the current element
            
            # Update the total count of beautiful pairs
            beautiful_pairs += sum_pairs * diff_pairs
        
        # Since each pair is counted twice, divide the total by 2
        results.append(beautiful_pairs // 2)
    
    return results

# Example test case
test_cases = [
    (6, 5, 2, [1, 2, 7, 4, 9, 6])
]
count_beautiful_pairs(test_cases)
