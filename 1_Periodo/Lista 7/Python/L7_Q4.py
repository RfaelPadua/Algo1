cont = 0
respostas = []
print("\nResponda s ou n para as perguntar:")
respostas.append(input("Telefonou para a vítima? "))
respostas.append(input("Esteve no local do crime? "))
respostas.append(input("Mora perto da vítima? "))
respostas.append(input("Devia para a vítima? "))
respostas.append(input("Já trabalhou com a vítima? "))

cont = respostas.count('y')
print()
if cont == 5:
    print("Assassino")
elif cont >= 3:
    print("Cúmplice")
elif cont == 2:
    print("Suspeita")
else:
    print("Inocente")

print()