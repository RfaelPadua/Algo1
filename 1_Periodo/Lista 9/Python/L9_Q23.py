while True:
    altura = float(input("Informe a altura do triângulo: "))
    base = float(input("Informe a base do triângulo: "))

    if base > 0 and altura > 0:
        break

    print("Valores invalidos!")

areaTriangulo = (base*altura)/2

print("A area do triângulo é ", areaTriangulo)