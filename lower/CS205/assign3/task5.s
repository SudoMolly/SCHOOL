### Template for taskN.s programs


#RETURNS INDEX
	.file	"task5.s"
	.text
	.globl	f
f:
    xor %eax, %eax          # Initialize %eax (current largest position) to 0
    xor %r8d, %r8d          # Intialize %r8d (current counter)
    xor %r9d, %r9d          # Intialize %r9d (current largest)

loop:
    inc %r8d                # Increment counter
    movl (%rdi), %ecx       # Load the current array element into %ecx
    test %ecx, %ecx         # Check if the element is zero (terminator)
    je done                 # If zero, jump to "done"
    test %ecx, %ecx         # Is negative element?
    js neg                  # If so negative compare
    cmp %r9d, %ecx          # Compare current stored largest to element
    jbe skip                # If not larger, next element
    movl %ecx, %r9d         # Set new largest
    movl %r8d, %eax         # Set new largest position
    jmp skip

    neg: 
    cmp %r9d, %ecx          # Compare current largest with element
    jle skip                # If not larger, skip
    movl %ecx, %r9d         # New largest
    movl %r8d, %eax         # New largest position

    skip:
    addq $4, %rdi           # Move to the next element (4 bytes per integer)
    jmp loop                # Repeat the loop

done:
    dec %eax                # Account for intial index being zero
    ret   
