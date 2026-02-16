    .file   "sort_array.s"
    .text
    .globl  f

#bubble sort
f:
    movq %rdi, %rsi          # Copy the pointer to %rsi for traversal
    xor %r9, %r9             # 0 r9
    pushq %rbx               # Save callee register

find_length:
    cmpl $0, (%rsi)          # Compare the current element with 0
    je end_find_length       # If it's 0, we've reached the end of the array
    addq $4, %rsi            # Move to the next element (assuming 4-byte integers)
    inc %r9                  # Increment counter
    jmp find_length          # Continue until we find the end

end_find_length:
    dec %r9                  # Decrement by 1 to get the last index (since we exclude the 0)

outer_loop:
    movq $0, %rcx            # Initialize inner loop counter
    movq %rdi, %rsi          # Copy the pointer to %rsi for traversal

inner_loop:
    movl (%rsi), %eax        # Load current element into %eax
    cmpl $0, (%rsi)          # Is end?
    je no_swap               # If yes, go to ending condition
    testq %rsi, %rsi         # Is negative?
    js inner_neg             # If yes need signed compare!

inner_pos:
    movl 4(%rsi), %ebx       # Load next element into %ebx
    cmpl %ebx, %eax          # Compare current and next element
    jle no_swap              # If current <= next, no swap needed

    # Swap the elements
    movl %ebx, (%rsi)        # Move next element to current position
    movl %eax, 4(%rsi)       # Move current element to next position
    jmp no_swap              # Move to end condition

inner_neg:
    movl 4(%rsi), %ebx       # Load next element into %ebx
    cmpl %ebx, %eax          # Compare current and next element
    jbe no_swap              # If current <= next, no swap needed
    
    # Swap the elements
    movl %ebx, (%rsi)        # Move next element to current position
    movl %eax, 4(%rsi)       # Move current element to next position

no_swap:
    addq $4, %rsi            # Move to the next element
    incq %rcx                # Increment inner loop counter
    cmpq %r9, %rcx           # Compare inner loop counter with array length - 1
    jl inner_loop            # If not done, continue inner loop

    decq %r9                 # Decrement outer loop counter
    cmpq $0, %r9             # Check if outer loop is done
    jg outer_loop            # If not done, continue outer loop

    popq %rbx                # Release callee register
    ret                      
