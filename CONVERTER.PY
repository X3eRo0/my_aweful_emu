f = open('source.asm') 
f1=open("instruction.bin",'w')   
Codes = {'ADD A': '0x87',
'ADD B': '0x80',
 'SUB A': '0x97',
 'SUB B': '0x90',
 'MVI A': '0x3e',
 'MVI B': '0x06',
 'HLT' :  '0x76'}
for line in f:
    line=line.rstrip().lstrip()
    a = line[0:5]
    a= a.upper()
    print(a)
    opcode = Codes.get(a)
    f1.write(opcode)
    print(opcode)



Codes = {}
f.close
# a=[]
# with open('codes.txt') as f1:

#     code_line =f1.readline().strip('.')
#     a.append(code_line)
# print(a)    