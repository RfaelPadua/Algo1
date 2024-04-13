
areaDaNota = 11200
altura = 70
t = int(input())
b = int(input())

area = (t + b) * altura
area /= 2

if area > areaDaNota/2:
    print("1")
elif area < areaDaNota/2:
    print("2")
else:
    print("0")
