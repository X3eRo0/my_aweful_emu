import struct

opcodes = {
    "add a": 0x87,
    "add b": 0x80,
    "add c": 0x81,
    "mvi a": 0x3e,
    "mvi b": 0x06,
    "sub a": 0x97,
    "hlt"  : 0x76,
}

with open("source.asm", "r") as file:
    code = file.readlines()

for i in range(len(code)):
    code[i] = code[i].strip()

