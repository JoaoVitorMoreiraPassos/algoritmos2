tudo = [float(i) for i in input().split()]
tudo.sort(reverse=True)
a = tudo[0]
b = tudo[1]
c = tudo[2]
if(a>=(b+c)):
        print("NAO FORMA TRIANGULO")
elif(a*a == b*b + c*c):
        print("TRIANGULO RETANGULO")
elif(a*a > b*b + c*c):
        print("TRIANGULO OBTUSANGULO")
elif(a*a < b*b + c*c ):
        print("TRIANGULO ACUTANGULO")
if(a == b and b == c):
        print("TRIANGULO EQUILATERO")
elif((a == b or a==c or b == c)):
        print("TRIANGULO ISOSCELES")