# *** Write your name here ***
#
.global dotprod_asm
dotprod_asm:	
	
    xor %r10, %r10
    xor %r11, %r11
    pushq %r12
    pushq %r13 
    pushq %rbx
    pushq %rbp
    pushq %rdi
    pushq %rsi

    movq %rdi, %r10 #A DATA ARRAY
    movq %rsi, %r11 #B DATA ARRAY
    movq $0, %rdx   #RETURN VALUE
    movq $1, %rbp   #ITERATOR
    movq %rcx, %rbx #LENGTH
    xor %r12, %r12  #CURRENT A
    xor %r13, %r13  #CURRENT B
   #movq $1, %r8    #CURRENT PRODUCT

comp:
    movq (%r10), %r12 #set current a
    movq (%r11), %r13 #set current b
    imulq %r12, %r13  #multiply
    addq %rdx, %r12   #add

reset:
    inc %rbp
    movq 8(%r10), %r10
    movq 8(%r11), %r11

main_loop:
    cmp %rbx, %rbp
    je end
    jmp comp

end:
    popq %r12
    popq %r13 
    popq %rbx
    popq %rbp
    popq %rdi
    popq %rsi
    ret
    
    


#void dotprod0(vec_ptr a, vec_ptr b, data_t *dest)
#{
#  assert(a->len == b->len);
#  *dest = 0;
#  for (int i = 0; i < a->len; i++)
#	*dest += a->data[i] * b->data[i];
#}  
#assert(a->len == b->len);
#dotprod_asm(a->data, b->data, dest, a->len);

