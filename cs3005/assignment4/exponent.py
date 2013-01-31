def exponentiate(num, exponent):
	new_num = 1
	for i in range(exponent):
		new_num *= num
	return new_num
	
l = range(20)

for n in l:
	print 2**n, exponentiate(2, n) 	