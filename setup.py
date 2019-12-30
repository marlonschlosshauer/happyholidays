#!/usr/local/bin/python3

import sys
import os
from distutils.dir_util import copy_tree

if len(sys.argv) < 2:
    print("No name given.")
    exit(1)

from_ =  "./template/"
files = ("script.c", "script.h", "script-test.c", "makefile")
to_be_replaced = "script"

if len(sys.argv) >= 3:
    to_be_replaced = sys.argv[2]
    from_ = "./" + sys.argv[2] + "/"
    files = (sys.argv[2] + ".c", sys.argv[2] + ".h", sys.argv[2] + "-test.c", "makefile")

to_ = "./" + sys.argv[1] + "/"

copy_tree(from_, to_)

os.chdir(to_)

for name in files:
    if not os.path.exists(name):
        continue
    f = open(name, "r+")
    content = f.read().replace(to_be_replaced, sys.argv[1])
    f.truncate(0)
    f.seek(0, os.SEEK_SET)
    f.write(content)
    f.close()


try:
    os.rename(files[0], sys.argv[1] + ".c")
    os.rename(files[1], sys.argv[1] + ".h")
    os.rename(files[2], sys.argv[1] + "-test.c")
except FileNotFoundError:
    pass

print("Done.")
