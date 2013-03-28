#!/usr/bin/env python

print '-'*40
a1 = 1 / 2
a2 = 1 / 2.0

b1 = 1 / 3
b2 = 1 / 3.0

#python 2 differs with python 3
print "a1 = 1 / 2"
print(a1)
print "a2 = 1 / 2.0"
print(a2)
print '-'*40

#python 2 differs with python 3
print "b1 = 1 / 3"
print(b1)
print "b2 = 1 / 3.0"
print(b2)
print '-'*40

print "repr(b2)"
print(repr(b2))
print "str(b2)"
print(str(b2))
print '-'*40

c1 = 10 / 4
c2 = 10 / 4.0

d1 = 10 // 4
d2 = 10 // 4.0

#python 2 differs with python 3
print "c1 = 10 / 4"
print(c1)
print "c2 = 10 / 4.0"
print(c2)
print '-'*40

print "d1 = 10 // 4"
print(d1)
print "d2 = 10 // 4.0"
print(d2)
print '-'*40

e1 = 1j * 1j
e2 = (2 + 3j)*(4 - 5j)

print "e1 = 1j * 1j"
print(e1)
print "e2 = (2 + 3j)*(4 - 5j)"
print(e2)
print "e2.real, e2.imag, e2.conjugate()"
print(e2.real, e2.imag, e2.conjugate())
print '-'*40

import math
for eachNum in (.2, .7, 1.2, 1.7, -.2, -.7, -1.2, -1.7):
    print "int(%.1f)\t%+.1f" % (eachNum, float(int(eachNum)))
    print "floor(%.1f)\t%+.1f" % (eachNum, math.floor(eachNum))
    print "round(%.1f)\t%+.1f" % (eachNum, round(eachNum))
    print '-'*40

print "0x41, 0o101, 0b1000001"
print(0x41, 0o101, 0b1000001)
print "hex(65), oct(65), bin(65)"
print(hex(65), oct(65), bin(65))
print '-'*40

print "ord('a'), ord('b'), ord('A'), ord('B')"
print(ord('a'), ord('b'), ord('A'), ord('B'))
print "chr(97), chr(98), chr(65), chr(66)" 
print(chr(97), chr(98), chr(65), chr(66))
print '-'*80

import random
for i in xrange(1, 3):
    print "the %dth time random()\t\t\t\t\t\t%f" \
        % (i, random.random())
    print "the %dth time randint(1, 10)\t\t\t\t\t%d" \
        % (i, random.randint(1, 10))
    print "the %dth time uniform(1.5, 10.6)\t\t\t\t\t%f" \
        % (i, random.uniform(1.5, 10.6))
    print "the %dth time random.choice(['perl', 'ruby', 'python', 'go'])\t%s" \
        % (i, random.choice(['perl', 'ruby', 'python', 'go']))   
    print '-'*80

print "Example: A list includes N(1 < N <= 20) elements, and the value of element n(0 <= n <= 2**31 - 1), sort the list"
N = random.randint(2, 20)
randlist = []
print "N = %d" % N
for i in xrange(0, N):
    n = random.uniform(0, 2**31-1)
    randlist.append(n)
print "Generate list"
print randlist
print "Sorted list"
print sorted(randlist)
print '-'*80

import decimal
print "0.1 + 0.1 + 0.1 - 0.3"
print(0.1 + 0.1 + 0.1 - 0.3)
print "decimal.Decimal('0.1') + decimal.Decimal('0.1') + decimal.Decimal('0.1') - decimal.Decimal('0.3')"
print(decimal.Decimal('0.1') + decimal.Decimal('0.1') + decimal.Decimal('0.1') - decimal.Decimal('0.3'))
print '-'*40

x = set('abcde')
y = set('bdxyz')
print "x = set('abcde')"
print(x) 
print "y = set('bdxyz')"
print(y)
print "x - y"
print(x - y)
print "x | y"
print(x | y)
print "x & y"
print(x & y)
print "x ^ y"
print(x ^ y)
print "x > y, x < y, (x - y) < x"
print (x > y, x < y, (x - y) < x)
print '-'*40

print "Use dir() retunr the list of valid attributes including methods fot the set:"
print (dir(x))
print '-'*40
