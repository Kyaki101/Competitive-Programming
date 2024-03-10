def sol():
    inp = input()
    numbers = inp.split()
    n, m, k = map(int, numbers)
    inp = input()
    numbers = inp.split()
    nums = list(map(int, numbers))
    nums.sort(reverse=True)
    suma = sum(nums)
    part = 0
    for i in range(min(m + k, n)):
        part += nums[i]
    print((part/suma) * 100)

    

t = 1
while t:
    sol()
    t -= 1


#numbers = input_numbers.split() splits input by spaces
#n, f, a, b = map(int, numbers) Turns input into indivudual vars
#numbers = inp.split() Splits input by spaces
#nums = list(map(int, numbers))  Turns input into list of numbers