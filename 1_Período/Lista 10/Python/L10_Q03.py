soma = 0
menor = float('inf')
maior = float('-inf')

for i in range(10):
    numero = float(input(f"Informe o {i+1}º numero: "))
    soma +=numero

    if numero < menor: menor = numero

    if numero > maior: maior = numero

print()
print("Maior valor: ", maior)
print("Menor valor: ", menor)
print("Soma dos valores: ", soma)
print()