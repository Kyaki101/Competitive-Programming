import sys

n = 10**6 // 2
alphabet = [chr(ord('A') + i) for i in range(25)]

# Repeat the alphabet as needed and slice to exactly 1 million characters
result = (alphabet * ((n // 26) + 1))[:n]
second = (alphabet * ((n // 26) + 1))[:n]



# Join and print all at once (much faster than printing in a loop)
sys.stdout.write(''.join(result + second))

