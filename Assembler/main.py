class Instruction: # Instruction Base Class, also used for Miscellaneous Mode
    text: list[str]
    itype: str

    def __init__(self, text: str):
        self.text = text.strip().split()
        self.opcodes = {
            "NOP": 0x00,
            "HLT": 0x1F
        }

    def parse(self):
        if self.text[0] not in self.opcodes.keys():
            raise Exception(f"Invalid Opcode {self.text[0]}")
        self.opcode = self.opcodes[self.text[0]]
        self.reg1 = 0 if len(self.text) == 1 else int(self.text[1])
        self.arguments = self.parse_arguments()

        self.first_byte = self.opcode << 3 | self.reg1

        return bytearray((self.first_byte, self.arguments))
        

    def parse_arguments(self):
        return 0

class Instruction_IMM(Instruction):
    def __init__(self, text):
        super().__init__(text)
        self.opcodes = {
            "LDI": 0x01,
            "LOD": 0x02,
            "STR": 0x04
        }

    def parse_arguments(self):
        return int(self.text[2])

    

class Instruction_REG(Instruction):
    def __init__(self, text):
        super().__init__(text)
        self.opcodes = {
            "LOD": 0x03,
            "STR": 0x05
        }

    def parse_arguments(self):
        reg2 = int(self.text[2])
        reg3 = 0 if len(self.text) < 4 else int(self.text[3])
        print(reg3)
        return reg2 << 5 | reg3 << 2

class Instruction_DIR(Instruction):
    def __init__(self, text):
        super().__init__(text)


def parse_line(line: str):
    line = line.strip()

    if line == "": return
    
    instruction_type = line[0]

    instruction: Instruction

    match instruction_type:
        case "#": # IMM
            instruction = Instruction_IMM(line[1:])
        case "@": # REG
            instruction = Instruction_REG(line[1:])
        case "$": # MSC
            instruction = Instruction(line[1:])
        case "-": # DIR
            instruction = Instruction_DIR(line[1:])
        case ";": # comment
            return
        case _:
            raise Exception(f"Invalid Instruction Type {instruction_type}")

    return instruction.parse()

code = ("#LDI 0 10", "#LDI 1 11", "@STR 0 1", "@LOD 2 1", "$HLT")

with open("./out/out.bin", "wb") as FILE:
    for line in code:
        out_bytes = parse_line(line)
        if out_bytes is None:
            continue

        FILE.write(out_bytes)