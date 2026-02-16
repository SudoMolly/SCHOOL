# *** Write your name here ***
#
.global dotprod_asm
dotprod_asm:
    
    #Intialize pointers
    pushq %rbp              # Save callee-register
    movq %rsp, %rbp         # Save the stack so we can mess with arguments
    
    #Save callee-saved registers
    pushq %rbx              
    pushq %r12
    pushq %r13
    pushq %r14

    # Load arguments
    movq %rdi, %r12         # r12 = list1 
    movq %rsi, %r13         # r13 = list2 
    movq %rcx, %r14         # r14 = length 
    movq %rdx, %rbx         # rbx = return value
    
    # Initialize FPU
    fldz                    # Load 0.0 into st(0) (accumulator for the sum)

multiply_and_sum_loop:
    # Check if we've processed all elements
    cmpq $0, %r14           # Compare r14 (length) with 0
    jle done                # If r14 <= 0, jump to done

    # Load elements from list1 and list2
    fldl (%r12)             # Load double from list1 into st(0)
    fmull (%r13)            # Multiply st(0) by double from list2, result in st(0)

    # Add the result to the accumulator
    faddp %st(0), %st(1)    # Add st(0) to st(1), store result in st(1), pop st(0)

    # Move to the next elements in the arrays
    addq $8, %r12           # Increment list1 pointer by 8 bytes (double size)
    addq $8, %r13           # Increment list2 pointer by 8 bytes (double size)
    decq %r14               # Decrement length counter
    jmp multiply_and_sum_loop # Repeat the loop

done:
    # Store the result in return_value
    fstpl (%rbx)            # Store st(0) (accumulated sum) into return_value, pop st(0)

    # Restore callee-saved registers
    popq %r14               
    popq %r13
    popq %r12
    popq %rbx
    movq %rbp, %rsp         # Restore the stack pointer
    popq %rbp               # Restore the base pointer
    ret                     # Return from the function
