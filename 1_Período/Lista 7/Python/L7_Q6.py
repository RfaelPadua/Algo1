i  = -1

while i < 0:
    i = int(input("Informe um numero inteiro positivo: "))

valor1 = int(input("Informe um valor:"))
valor2 = int(input("Informe um valor: "))
valor3 = int(input("Informe um valor: "))

if i % 2 == 0:
    print((valor1+valor2+valor3)/3)
elif i > 10:
    print((valor1*2+valor2*3+valor3*4)/9)