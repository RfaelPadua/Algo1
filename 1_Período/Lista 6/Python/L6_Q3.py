preço_maça = 0.90
preço_maça_desconto = 0.70

qnt = int(input("Informe a quantidade de maças compradas: "))
print()
if qnt < 12:
    print(f"O preço todal é de R${qnt*preço_maça}")
else:
    print(f"O preço todal é de R${qnt*preço_maça_desconto}")

print()