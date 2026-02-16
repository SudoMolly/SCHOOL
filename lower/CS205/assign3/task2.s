### Template for taskN.s programs

	.file	"task2.s"
	.text
	.globl	f
f:
    xor %eax, %eax          # Initialize %eax (sum) to 0

loop:
    movl (%rdi), %ecx       # Load the current array element into %ecx
    test %ecx, %ecx         # Check if the element is zero (terminator)
    je done                 # If zero, jump to "done"
    addl %ecx, %eax         # add sum to return
    addq $4, %rdi           # Move to the next element (4 bytes per integer)
    jmp loop                # Repeat the loop

done:
    ret   
