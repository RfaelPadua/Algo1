qntValores = int(input("Informe a quantidade de valores: "))

menorValor = float("inf")

for i in range(qntValores):
    valor = float(input(f"Informe o {i + 1}º valor: "))

    if valor < menorValor:
        menorValor = valor



print(f"O maior valor lidos é {menorValor}")