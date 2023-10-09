valoresFib = [0, 1]

for i in range(1, 20):
    valor = valoresFib[0] + valoresFib[1]
    print(valor, end = " ")
    valoresFib.pop(0)
    valoresFib.append(valor)