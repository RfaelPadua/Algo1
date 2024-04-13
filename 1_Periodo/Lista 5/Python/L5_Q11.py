n = 0

while n <= 100 or n > 999:
    n = int(input("Informe um numero de 3 digitos: "))

n = str(n)
n = n[::-1]

print(n)