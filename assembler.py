import sys
import struct

opcodes = {
    "ADD" : {
        "A" : 0x87,
        "B" : 0x80
    },
    "SUB" : {
        "A" : 0x97,
        "B" : 0x90
    },
    "MVI" : {
        "A" : 0x3e,
        "B" : 0x06,
        "E" : 0x0E,
        "D" : 0x16,
        "H" : 0x26
    },
    "PUSH" : {
        "B" : 0xC5,
        "D" : 0xD5,
        "H" : 0xE5
    },
    "POP" : {
        "B" : 0xC1,
        "D" : 0xD1,
        "H" : 0xE1
    },
    "LDA" : 0x3A,
    "STA" : 0x32,
    "HLT" : 0x76
}

def parse_asm(filename):
    input_asm = open(filename).readlines()
    output    = open("instructions.bin", "wb")
    
    for line in input_asm:
        line = line.strip("\r\n")
        line = line.strip()

        opcode = line.split()[0]
        instruction = line.replace(opcode, "")
        instruction = instruction.replace(' ', '')
        instruction = instruction   .split(',') # ["MVI", "A, 0x50"]

        if opcode == "MVI":

            arg_1   = instruction[0]
            imm_v   = int(instruction[1], 16)

            output.write(struct.pack('B', opcodes[opcode][arg_1]))
            output.write(struct.pack('B', imm_v))
        
        if opcode == "ADD":
            output.write(struct.pack('B', opcodes[opcode][instruction[1]]))
        if opcode == "SUB":
            output.write(struct.pack('B', opcodes[opcode][instruction[1]]))
        if opcode == "HLT":
            output.write(struct.pack('B', opcodes[opcode]))
        if opcode == "LDA" or opcode == "STA":
            output.write(struct.pack('B', opcodes[opcode]))
            output.write(struct.pack('H', int(instruction[0], 16)))
        if opcode == "PUSH" or opcode == "POP":
            output.write(struct.pack('B', opcodes[opcode][instruction[0]]))

    
    output.close()


def main():

    parse_asm(sys.argv[1])


if __name__ == "__main__":
    main()

        


        