#!/usr/bin/env python

print '-'*40
s1 = "Start study:"
s2 = "python string!"
s = s1 + s2
print "string s1 = %s\nstring s2 = %s" % (s1, s2)
print "s(s1 + s2) = %s" % (s1 + s2)
print '-'*80
for i in xrange(0,len(s)):
    print "%-2d" % (i),
print ""
for i in s:
    print "%-2s" % (i),
print ""
print '-'*80
print "len(s) = %d" % (len(s))
print "s[0] = %s, s[-2] = %s" % (s[0], s[-2])
print "s[8:26] = %s\ns[8:-1] = %s\ns[:8] = %s\ns[9:] = %s" % (s[8:26], s[8:-1], s[:8], s[9:])
print "s[1:10:2] = %s\ns[10:1:-2] = %s" % (s[1:10:2], s[10:1:-2])
print "s[::-1] = %s" % (s[::-1])
print '-'*80
print "Use dir() return the list of valid attributes including methods for the string:"
print (dir(s))
print '-'*80
print "s[:12] + 'ruby' + s[18:] = %s" % (s[:12] + 'ruby' + s[18:])
print "s.replace('python', 'ruby') = %s" % (s.replace('python', 'ruby'))
print "s.replace('st', '$$') = %s" % (s.replace('st', '$$'))
print "s.replace('st', '$$', 1) = %s" % (s.replace('st', '$$', 1))
print '-'*40
print "s.split():"
print s.split()
print "s.split(':'):"
print s.split(':')
print '-'*80

x = 1.23456789
print "x = 1.23456789"
print "%6.2f|" % (x),
print r"<->%6.2f" 
print "%-6.2f|" % (x),
print r"<->%-6.2f" 
print "%6.3f|" % (x),
print r"<->%6.3f" 
print "%4.2f|" % (x),
print r"  <->%4.2f" 
print "%06.2f|" % (x),
print r"<->%06.2f" 
print "%+06.2f|" % (x),
print r"<->%+06.2f" 
print '-'*80

print r"If you directly print dirpath = 'C:\new\text.dat', the output will be:"
print '-'*40
print "dirpath = 'C:\new\text.dat'"
print '-'*40
print "You should add char 'r' before string or use double '\\' to stop escape"
print '-'*80
