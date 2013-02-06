// This file is part of the materials accompanying the book 
// "The Elements of Computing Systems" by Nisan and Schocken, 
// MIT Press. Book site: www.idc.ac.il/tecs
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input. 
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel. When no key is pressed, 
// the screen should be cleared.

// Get the start of the screen memory block
(LOOP)
	// Set loc to the start of the screen memory
	@SCREEN
	D=A
	@loc
	M=D

	// Initialize our counter to the size of the screen's memory block
	@8191
	D=A
	@i
	M=D

	// Get the keyboard value
	@24576
	D=M

	// Jump to FILL if a key is pressed (D != 0)
	@FILL
	D;JNE

	// Jump to CLEAR if no key is pressed
	@CLEAR
	0;JMP

(FILL)
	// Take the start of the screen memory and our offset and set it to black
	@i
	D=M

	@SCREEN
	A=A+D

	// Set rect to black
	M=-1

	// If 'i' is zero return to the start
	@i
	D=M
	M=D-1
	@LOOP
	D;JEQ

	@FILL
	0;JMP

(CLEAR)
	@i
	D=M

	// Take the start of the screen memory and our offset and set it to black
	@SCREEN
	A=A+D

	// Set the rec to white
	M=0

	// If 'i' is zero return to the start
	@i
	D=M
	M=D-1
	@LOOP
	D;JEQ

	@CLEAR
	0;JMP