valor = float(input("\nInforme o valor de compra: "))

print()

if valor < 10:
    print(f"O valor de venda é R${valor + valor * 0.7}")
elif valor < 30:
    print(f"O valor de venda é R${valor + valor * 0.5}")
elif valor < 50:
    print(f"O valor de venda é R${valor + valor * 0.4}")
else:
    print(f"O valor de venda é R${valor + valor * 0.3}")

print()