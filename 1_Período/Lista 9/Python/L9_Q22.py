
numero = int(input("Informe um numero inteiro positivo: "))

for i in range(2,numero+1,2):
    print(i, end = ' ')

print()

if numero % 2 == 0:
    numero -=1
for i in range(numero, -1, -2):
    print(i, end = ' ')