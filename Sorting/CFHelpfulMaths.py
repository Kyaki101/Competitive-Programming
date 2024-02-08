#
#https://codeforces.com/problemset/problem/339/A
#

def sol():
    n = input()
    numbers = n.split('+')
    numbers.sort()
    res = ""
    for i in numbers:
        res += str(i) + "+"
    res = res[:len(res) - 1]
    print(res)

t = 1
while t:
    sol()
    t -= 1


#numbers = input_numbers.split() splits input by spaces
#n, f, a, b = map(int, numbers) Turns input into indivudual vars
#numbers = inp.split() Splits input by spaces
#nums = list(map(int, numbers))  Turns input into list of numbers