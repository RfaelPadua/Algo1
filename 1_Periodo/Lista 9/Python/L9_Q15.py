divisores = []
while True:
    numero = int(input("Informe um numero positivo maior que 0: "))
    
    if numero > 0:
        break

for i in range(1, numero):
    if numero % i ==0:
        divisores.append(i)

print(divisores)