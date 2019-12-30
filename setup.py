#!/usr/local/bin/python3
# Copy template folder
# Rename folder and "script" occurance in files to $1

import sys
import os
from distutils.dir_util import copy_tree

if len(sys.argv) < 2:
    print("No name given.")
    exit(1)

from_ =  "./template/"
to_ = "./" + sys.argv[1] + "/"

copy_tree(from_, to_)

os.chdir(to_)

files = ("script.c", "script.h", "script-test.c", "makefile")
for name in files:
    f = open(name, "r+")
    content = f.read().replace("script", sys.argv[1])
    f.truncate(0)
    f.seek(0, os.SEEK_SET)
    f.write(content)
    f.close()

os.rename("script.c", sys.argv[1] + ".c")
os.rename("script.h", sys.argv[1] + ".h")
os.rename("script-test.c", sys.argv[1] + "-test.c")

print("Done.")
