numeros = []

for i in range(3):
    numeros.append(int(input(f"informe o valor {i + 1}: ")))

numeros.sort()

print(*numeros, sep = ", ")