qntValores = int(input("Informe a quantidade de valores: "))
soma = 0
for i in range(qntValores):
    valor = float(input(f"Informe o {i + 1}º valor: "))

    soma += valor

media = soma / qntValores

print(f"A media aritmética dos valores lidos é {media}")