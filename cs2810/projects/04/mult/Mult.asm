// This file is part of the materials accompanying the book 
// "The Elements of Computing Systems" by Nisan and Schocken, 
// MIT Press. Book site: www.idc.ac.il/tecs
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[3], respectively.)

// Initialize sum with zero
@sum
M=0

(LOOP)
	// R1--
	@R1
	D=M-1	
	@R1
	M=D

	// If R1 < 0, jump to end
	@R1
	D=M
	@END
	D;JLT

	// sum = sum + R0
	@R0
	D=M
	@sum
	M=M+D

	// Continue the loop
	@LOOP
	0;JMP

(END)
	@sum
	D=M
	@R2
	M=D
	@END
	0;JMP