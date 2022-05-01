import json
import sys
import os
import re
from enum import Enum

preamble="NEW\r\nAUTO 3,1\r\n*--------------------------------------\r\n"
postamble="*--------------------------------------\r\nMAN\r\nSAVE /A3OSX.BUILD/SOS/{}\r\nLOAD /A3OSX.BUILD/SOS/SOS.S\r\nASM\r\n"

file = open('SOS13Src.txt', 'r')
lines = file.readlines()

inside_file = False

state = 0 # 0:seeking 1:inside 2:emitting

for line in lines:
    stripped_line = line.strip()
    if stripped_line.startswith("FILE: "):
        # (re)start file processing
        #print("Found new file: {}".format(stripped_line))
        if inside_file:
            text_file.write(postamble.format(name))
            text_file.close()
        name=stripped_line[6:]
        if (stripped_line.endswith("SRC")):
            name=name[:len(name)-4]
            #print("File is source!")
        text_file = open("{}.txt".format(name), "w")
        text_file.write(preamble)
        inside_file = True
    else:
        if inside_file:
            text_file.write(line[:len(line)-1])
            text_file.write("\r\n")
if inside_file:
    text_file.write(postamble.format(name))
    text_file.close()

