#https://codeforces.com/contest/1925/problem/A
def sol():
    input_numbers = input()
    numbers = input_numbers.split()
    n, k = map(int, numbers)
    s = initial(k)
    print(s * n)


def initial(k):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    return alphabet[:k]

t = int(input())
while t:
    sol()
    t -= 1


#numbers = input_numbers.split() splits input by spaces
#n, f, a, b = map(int, numbers) Turns input into indivudual vars
#numbers = inp.split() Splits input by spaces
#nums = list(map(int, numbers))  Turns input into list of numbers