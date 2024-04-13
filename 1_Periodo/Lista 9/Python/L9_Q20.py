soma = 0
numero = int(input("Informe um numero inteiro: "))

for i in range(1, numero):
    if numero % i == 0:
        soma += i
        print(i, end = ' + ')

print('=', soma)