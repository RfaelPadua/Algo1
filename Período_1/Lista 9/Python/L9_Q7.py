qntValores = int(input("Informe a quantidade de valores: "))

maiorValor = float("-inf")

for i in range(qntValores):
    valor = float(input(f"Informe o {i + 1}º valor: "))

    if valor > maiorValor:
        maiorValor = valor



print(f"O maior valor lidos é {maiorValor}")