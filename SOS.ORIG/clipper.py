import json
import sys
import os
import re
from enum import Enum

preamble="NEW\n  AUTO 3,1\n*--------------------------------------\n"
postamble="*--------------------------------------\nMAN\nSAVE /A3OSX.BUILD/SOS.13/{}\nLOAD /A3OSX.BUILD/SOS.13/sos.s\nASM\n"

file = open('SOS13Src.txt', 'r')
lines = file.readlines()

is_src = False
inside_file = False

state = 0 # 0:seeking 1:inside 2:emitting

for line in lines:
    stripped_line = line.strip()
    if stripped_line.startswith("FILE: "):
        # (re)start file processing
        #print("Found new file: {}".format(stripped_line))
        if inside_file:
            if is_src:
                text_file.write(postamble.format(name.lower()))
            text_file.close()
            is_src = False
        name=stripped_line[6:]
        if (stripped_line.endswith("SRC")):
            is_src = True
            name=name[:len(name)-4]
            #print("File is source!")
        text_file = open("{}.txt".format(name), "w")
        text_file.write(preamble)
        inside_file = True
    else:
        if inside_file:
            text_file.write(line)
            #text_file.write("\n")
if inside_file:
    if is_src:
        lower_name = name.lower()
        text_file.write(postamble.format(lower_name))
    text_file.close()

#print(postamble.format("bleah")) 
