soma = 0
while True:
    A = int(input("Informe o numero A(entre 0 e 1000): "))
    B = int(input("Informe o numero B(entre 0 e 1000): "))

    if 0 < A < 1000 and 0 < B < 1000:
        break

    print("Numero invalido, insira nomavamente")

for i in range(1000):
    if (i % A == 0 or i % B == 0) and not (i % A == 0 and i % B == 0):
        print(i, end =" + ")
        soma+= i

print("=", soma)