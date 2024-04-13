a = int(input("Informe o tamanho da vareta: "))
b = int(input("Informe o tamanho da vareta: "))
c = int(input("Informe o tamanho da vareta: "))
d = int(input("Informe o tamanho da vareta: "))



if a < b + c and b < c + a and c < b +a:
    print("S")
elif a < d + c and d < c + a and c < d + a:
    print("S")
elif b < d + c and d < c + b and c < d + b:
    print("S")
else:
    print("N")