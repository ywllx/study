#!/usr/bin/env python

import sys
import os
from collections import deque

name = sys.argv[1]
num = sys.argv[2]

filenames = []
for i in xrange(int(num)):
    filename = name + str(i) + ".dat"
    filenames.append(filename)

for fl in filenames:
    if os.path.isfile(fl):
        os.remove(fl)

fileque = deque(filenames)

for line in sys.stdin.readlines():
    fname = fileque.popleft()
    with open(fname, "a+") as f:
        f.write(line)
    fileque.append(fname)

    
