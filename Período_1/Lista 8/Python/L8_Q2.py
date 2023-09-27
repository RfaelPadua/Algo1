valores = []

for i in range(3):
    valores.append(int(input(f"Informe o {i + 1}º valor: ")))

valores.sort()

for valor in range(3):
    print(valores[valor], end = " ")