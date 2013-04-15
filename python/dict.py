#!/usr/bin/env python

D = {'spam':2, 'ham':1, 'egg':3}
print '-'*40
print "Dictionary D: {'spam':2, 'ham':1, 'egg':3}"
print "D = %r" % D
print "D['spam'] = %r" % (D['spam'])
print "len(D) = %r" % (len(D))
print "list(D.keys()) = %r" % (list(D.keys()))
print "list(D.values()) = %r" % (list(D.values()))
print "list(D.items()) = %r" % (list(D.items()))
print '-'*80

D['ham'] = ['grill', 'bake', 'fry']
print "D = %r" % D
del D['egg']
print "D = %r" % D
D['brunch'] = 'Bacon'
print "D = %r" % D
D1 = {'toast':4, 'muffin':5}
print "D1 = %r" % D1
D.update(D1)
print "After D.update(D1), D = %r" % D
print '-'*80

print "D2 = {x: x**2 for x in [1, 2, 3, 4]}"
print "D2 = %r" % ({x: x**2 for x in [1, 2, 3, 4]})
print "D3 = dict.fromkeys(['a', 'b', 'c'], 0)"
print "D3 = %r" % (dict.fromkeys(['a', 'b', 'c'], 0))


