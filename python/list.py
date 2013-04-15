#!/usr/bin/env python

print '-'*40
l1 = [1, 3, 11]
l2 = [9, 15, 5, 7]
print "l1 = %r" % (l1)
print "l2 = %r" % (l2)
l = l1 + l2
print "l(l1 + l2) = %r" %(l1 + l2)
for i in xrange(0, len(l)):
    print "%-3d" %(i),
print ""
for i in l:
    print "%-3r" %(i),
print ""
print "l[0] = %r, l[-3] = %r" %(l[0], l[-3])
print "l[2:6] = %r" %(l[2:6])
print '-'*40

matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print "matrix = %r" %(matrix)
print "matrix[1] = %r" % (matrix[1])
print "matrix[2][0] = %r" % (matrix[2][0])
print '-'*40

s = '89'
print "s = %s" % (s)
print "res = [c * 4 for c in list(s)]"
res = [c * 4 for c in list(s)]
print "res = %r" %(res)
print "l + list(s) = %r" % (l + list(s))
print '-'*40

print '-'*80
print "Use dir() return the list of valid attributes including methods for the list:"
print (dir(l))
print '-'*80

l.sort()
print "l.sort() = %r" % (l)
l.append(12)
print "l.append(12) = %r" % (l)
l.extend([6,9,13])
print "l.extend([6,9,13]) = %r" % (l)
a = l.pop()
print "l.pop() = %r" % (a)
print "After l.pop(), l = %r" % (l)
