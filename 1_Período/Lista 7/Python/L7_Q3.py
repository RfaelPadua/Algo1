import math
numeroDeLados = 0
while numeroDeLados < 3 or numeroDeLados > 5:
    numeroDeLados = int(input("Informe o numero de lados: "))

lados = float(input(f"Informe a medida dos lados: "))

if numeroDeLados == 3:
    print("TRIÂNGULO")
    area = (lados**2 * math.sqrt(3)) / 4 
elif numeroDeLados == 4:
    print("QUADRADO")
    area = lados ** 2
elif numeroDeLados == 5:
    print("PENTÁGONO")
    area = (5 * lados**2) / (4 * math.tan(math.pi / 5))


print(area)