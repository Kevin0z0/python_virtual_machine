a = 1
b = 0
i = 0
print a
print b
print i

while i < 10:
	print a
	t = a
	a = a + b
	b = t
	i += 1
	
print a
print b
print i