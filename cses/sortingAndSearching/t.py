MOD = 10**9 + 7

def count_distinct_subsequences(n, arr):
    # Map to store the last occurrence of each element
    last = {}
    total = 0  # Total number of valid subsequences
    
    for i, x in enumerate(arr):
        # If x has not appeared before, double the total
        if x not in last:
            total = (total * 2 + 1) % MOD
        else:
            # If x has appeared before, add the number of subsequences before its last occurrence
            total = (total * 2 - (total - last[x]) + MOD) % MOD
        
        # Update the last occurrence of x
        last[x] = total
    
    return total

# Read input
n = int(input())
arr = list(map(int, input().split()))

# Compute and print the result
print(count_distinct_subsequences(n, arr))
