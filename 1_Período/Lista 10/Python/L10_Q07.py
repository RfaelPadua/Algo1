valor = int(input("Informe um valor inteiro: "))
fatorial = 1

for i in range(valor, 1, -1):
    fatorial *= i

print(f"Fatorial de {valor} é {fatorial}")