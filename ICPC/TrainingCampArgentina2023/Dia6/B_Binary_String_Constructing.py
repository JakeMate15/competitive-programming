v = [int(i) for i in input().split(" ")]

a = v[0]
b = v[1]
x = v[2]

ultimo = -1
if b > a:
	ultimo = 1
	print(1, end="")
	b -= 1
else:
	ultimo = 0
	print(0, end="")
	a -= 1

while x > 1:
	x -= 1
	if ultimo == 0:
		print(1, end="")
		ultimo = 1
		b -= 1
	else:
		print(0, end="")
		ultimo = 0
		a -= 1

if ultimo == 1:
	while b > 0:
		print(1, end="")
		b -= 1
	while a > 0:
		print(0, end="")
		a -= 1

else:
	while a > 0:
		print(0, end="")
		a -= 1
	while b > 0:
		print(1, end="")
		b -= 1
	
print()