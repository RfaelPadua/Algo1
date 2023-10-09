altura = int(input("Informe a altura do triangulo: "))

for i in range(0, altura):
    for j in range(i + 1):
        print("*", end = ' ')
    print()