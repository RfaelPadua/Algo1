valor = float(input("Informe o valor do produto: "))

print(f"O total a pagar com desconto de 10% é R${valor * 0.9: .2f}")

print(f"O valor de cada parcelo, no parcelamento de 3x sem jutos é R${valor / 3: .2f}")

print(f"A comissão do venderdor, se a compra for a vista é R${(valor * 0.9)*0.05: .2f}")

print(f"A comissão do venderdor, se a compra for parcelada é R${valor*0.05: .2f}")