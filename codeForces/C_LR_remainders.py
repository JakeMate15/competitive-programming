t = int(input())  # Number of test cases

for _ in range(t):
    n, m = map(int, input().split())  # Length of the array and the modulus value
    a = list(map(int, input().split()))  # The array elements
    s = input()  # The string of commands

    # Initialize the product of all elements
    product = 1
    for num in a:
        product = (product * num) % m

    for command in s:
        # Output the remainder of the product divided by m
        print(product)

        if command == 'L':
            # Remove the leftmost element and update the product
            product = (product * pow(a.pop(0), -1, m)) % m
        else:
            # Remove the rightmost element and update the product
            product = (product * pow(a.pop(), -1, m)) % m
