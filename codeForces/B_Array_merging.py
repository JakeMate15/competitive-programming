def max_subarray_length(a, b):
    c = a + b  # Merge arrays a and b
    max_length = 0  # Maximum length of a subarray

    i = 0
    while i < len(c):
        num = c[i]
        count = 0

        while i < len(c) - 1 and num == c[i + 1]:
            count += 1
            i += 1

        max_length = max(max_length, count + 1)
        i += 1

    return max_length

# Read the number of test cases
t = int(input())

for _ in range(t):
    # Read the length of the arrays
    n = int(input())

    # Read the elements of array a
    a = list(map(int, input().split()))

    # Read the elements of array b
    b = list(map(int, input().split()))

    # Call the max_subarray_length function for the current test case
    result = max_subarray_length(a, b)

    # Print the result
    print(result)
