### Template for taskN.s programs

	.file	"task4.s"
	.text
	.globl	f
f:
    xor %eax, %eax          # Initialize %eax (counter) to 0

loop:
    movl (%rdi), %ecx       # Load the current array element into %ecx
    test %ecx, %ecx         # Check if the element is zero (terminator)
    je done                 # If zero, jump to "done"
    test %ecx, %ecx         # Check if negative number
    js neg                  # Jump to negative if so
    cmp %eax, %ecx          # Compare current array element to largest stored
    jbe skip                # If not, skip
    movl %ecx, %eax         # If larger, set new largest
    jmp skip                # Jmp to iterator

    neg: 
    cmp %eax, %ecx          # Compare current element to largest stored
    jle skip                # If not skip
    movl %ecx, %eax         # If larger, new largest!

    skip:
    addq $4, %rdi           # Move to the next element (4 bytes per integer)
    jmp loop                # Repeat the loop

done:
    ret   
