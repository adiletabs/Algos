# This is a copyright from https://gist.github.com/dario2994/fb4713f252ca86c1254d
# My own implementation to be added soon

#!/usr/bin/env python3

# This program prints all hcn (highly composite numbers) <= MAXN (=10**18)
#
# The value of MAXN can be changed arbitrarily. When MAXN = 10**100, the
# program needs less than one second to generate the list of hcn.
from math import log

MAXN = 10**18

# Generates a list of the first primes (with product > MAXN).
def gen_primes():
	primes = []
	primes_product = 1
	for n in range(2, 10**10):
		is_prime = True
		for i in range(2, n):
			if n % i == 0:
				is_prime = False
		if is_prime: 
			primes.append(n)
			primes_product *= n
			if primes_product > MAXN: break
	return primes

# Generates a list of the hcn <= MAXN.
def gen_hcn():
	primes = gen_primes()
	print(primes)
	hcn = [(1, 1, [])]
	for i in range(len(primes)):
		new_hcn = []
		for el in hcn:
			new_hcn.append(el)
			if len(el[2]) < i: continue
			e_max = el[2][i-1] if i >= 1 else int(log(MAXN, 2))
			for e in range(1, e_max+1):
				n = el[0]
				div = el[1]
				exponents = el[2].copy()
				n *= pow(primes[i], e)
				div *= e+1
				exponents.append(e)
				if n > MAXN: break
				new_hcn.append((n, div, exponents))
		new_hcn.sort()
		hcn = [(1, 1, [])]
		for el in new_hcn:
			if el[1] > hcn[-1][1]: hcn.append(el)
	return hcn


hcn = gen_hcn()
# From here on is only pretty printing.
print("Number of highly composite numbers less than", MAXN, "is", len(hcn),"\n")

def PrintWithCorrectSpaces(a, b, c):
	aspace = int(log(MAXN, 10)) + 5
	bspace = int(log(hcn[-1][1], 10)) + 5
	assert(len(a) < aspace)
	assert(len(b) < bspace)
	
	print(a, " "*(aspace-len(a)), b, " "*(bspace-len(b)), c)


PrintWithCorrectSpaces("number", "divisors", "factorization")

primes = gen_primes()
for el in hcn:
	factorization = "*".join([str(primes[i])+("^"+str(el[2][i]) if el[2][i]>1 else "") for i in range(len(el[2]))])
	
	PrintWithCorrectSpaces(str(el[0]), str(el[1]), factorization)
