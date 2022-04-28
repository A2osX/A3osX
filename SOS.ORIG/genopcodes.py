import json
import sys
import os
import re

opcodes = { 'ADC', 'AND', 'ASL', 'BCC', 'BCS', 'BEQ', 'BIT', 'BMI', 'BNE', 'BPL', 'BRK', 'BVC', 'BVS', 'CLC', 'CLD', 'CLI', 'CLV', 'CMP', 'CPX', 'CPY', 'DEC', 'DEX', 'DEY', 'EOR', 'INC', 'INX', 'INY', 'JMP', 'JSR', 'LDA', 'LDX', 'LDY', 'LSR', 'NOP', 'ORA', 'PHA', 'PHP', 'PLA', 'PLP', 'ROL', 'ROR', 'RTI', 'RTS', 'SBC', 'SEC', 'SED', 'SEI', 'STA', 'STX', 'STY', 'TAX', 'TAY', 'TSX', 'TXA', 'TXS', 'TYA'}

for line in opcodes:
    print("s@^{}$@\t\t\t\t{} @ig;".format(line.strip(),line.strip().lower()))
    print("s@^{}(\ )@\t\t\t\t{} @ig;".format(line.strip(),line.strip().lower()))
    print("s@^([A-Z0-9.]+)\ {}$@\\1\t\t\t\t{}@ig;".format(line.strip(),line.strip().lower()))
    print("s@^([A-Z0-9.]+)\ {} @\\1\t\t\t\t{} @ig;".format(line.strip(),line.strip().lower()))

