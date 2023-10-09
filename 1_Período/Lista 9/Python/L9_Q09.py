qntValores = int(input("Informe a quantidade de valores: "))

menorValor = float("inf")
maiorValor = float("-inf")
media = float(0)

for i in range(qntValores):
    valor = float(input(f"Informe o {i + 1}º valor: "))

    if valor < menorValor:
        menorValor = valor

    if valor > maiorValor:
        maiorValor = valor

    media +=valor

media /= qntValores

print(f"\nO menor valor lido é {menorValor}")
print(f"O maior valor lido é {maiorValor}")
print(f"A media aritmética é {media}")