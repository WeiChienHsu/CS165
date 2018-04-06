# Chapter 1

## Computer Systems: Hardware and Software
- CPU
- Main memory (ramdon-access memory or RAM)
- Secondary Storage devices
- Input Device
- Output Device

### CPU: 	
Part of a computer that runs programs. Without CPU, computer could not run software.
A program is a sequence of instructions stored in the computer’s memory. CPU is engaged in a process known formally as below: (With Arthmetic and Logic Unit, ALU)

- Fetch: The CPU’s control unit fetches, from main memory (computer’s work area), the next instruction in the sequence of program instructions. 
- Decode: The instruction is encoded in the form of a number. The control unit decodes the instruction and generates an electornic signal.
- Execute: The signal is routed to the appropriate component caused them to perform an operations.


### Main Memory (RAM)
Where the compoter stores a program while the program is running, as well as the data that the program is working with.

RAM is called this because the CPU is able to quickly access data stored at any random loaciton in this memory.Only used for temporary storage while a program is running.

Computer's memory is divided into tiny storage cells known as bytes. One byte is enough momory to stroe just a single letter or a small number. Each byte is devided into eight smaller storage locations known as bits. (Tiny components that can hold either a positive or a negative charge)

Each byte is assigned a unique number known as an address. A byte is identified by its address, so that the data stroed there can be located.

### Secondary Storage (Disk Drive)
Type of memory can hold data for long period of time by magnetically encoding data onto a circular disk.

### Input Device / Output Device
Any information the computer collects from / sends to the outside world.

***

## Software
- System Software 
- Application Software

### System Software
- Operating Systems: Controls internal operations of computer's hardware, Manages all the devices connected to the computer, Allows data to be saved to and retrived from storage and Allows other programs to run on computer.
- Utility Programs: Enhances the computer's opration or safeguards. (ex. Virus sacnner)
- Software Development Tools: Compilers and Integrated Development Environment.

***

## Programming Languages
- Low Level: Resembles the numeric machine language of the computer more than the natural language of humans.
- High Level: Closer to the level of human-readability.

### C++
Widely used language because, in addition to the high-level features necessary for writing applications, it also has many low-level features.(Based on C language, which was invented for purpose such as writing opreating system and compilers.)

### Translating source code into machine language
#### Proprocessor -> Compiler -> Linker
1. Save source code to a file.
2. "Preprocessor" Reads the source code and Searchs for special lines taht begin with #.
3. These lines contian commands or "Directives" that cause the preprocessor to Amend or Process the source code.
4. "Compiler" Steps through the preprocessed source code, "translating" each source code instruction into the "machine code".
5. Uncovers any "syntax errors" that may be in the program.
6. Compiler "stores" the translated machine language instructions. (Object code)
7. "Linker" combines the object file with the necessary "library" routines.
8. "Executable file" contains machine language instrucions or executable code and is ready to run on computer.

