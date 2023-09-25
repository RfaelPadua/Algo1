valor = float(input("\nInforme o valor da compra: "))
desconto = float(input("Informe o percentual de desconto: "))

valor_com_desconto = valor - valor * desconto/100

if valor_com_desconto < 100:
    print(f"\nNão é possivel conceder o desconto T.T\nO valor da compra é de R${valor}\n")
else:
    print(f"\nÉ possivel conceder o desconto!!\nO valor da compra é de R${valor_com_desconto}\n")