numeros = [float(input("Informe um numero real: ")) for i in range(10)]
maiorNumero = float('-inf')
menorNumero = float('inf')

for numero in numeros:
    if numero > maiorNumero:
        maiorNumero = numero
    if numero < menorNumero:
        menorNumero = numero

print(f'O menor numero é {menorNumero}')
print(f'O maior numero é {maiorNumero}')