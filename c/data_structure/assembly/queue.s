	.file	"queue.c"
	.text
	.section	.rodata
.LC0:
	.string	"true"
.LC1:
	.string	"false"
.LC2:
	.string	"empty Queue: %s\n"
.LC3:
	.string	"clear(Q): "
.LC4:
	.string	"enqueue(Q, 10)"
.LC5:
	.string	"Q->front->data: %d\n"
.LC6:
	.string	"Q->rear->data: %d\n"
.LC7:
	.string	"(void*)Q->front->next: %p\n"
.LC8:
	.string	"enqueue(Q, 20)"
.LC9:
	.string	"Q->front->next->data: %d\n"
	.align 8
.LC10:
	.string	"(void*)Q->front->next->next: %p\n"
.LC11:
	.string	"(void*)Q->rear->next: %p\n"
.LC12:
	.string	"enqueue 0 to 9"
.LC13:
	.string	"print_queue(Q): "
.LC14:
	.string	"dequeue(Q): %d\n"
.LC15:
	.string	"peek(Q): %d\n"
.LC16:
	.string	"get_size(Q): %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L2
	movl	$-1, %eax
	jmp	.L3
.L2:
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movl	$0, 16(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	is_empty
	testb	%al, %al
	je	.L4
	leaq	.LC0(%rip), %rax
	jmp	.L5
.L4:
	leaq	.LC1(%rip), %rax
.L5:
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	clear
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	movq	-8(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	enqueue
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	is_empty
	testb	%al, %al
	je	.L6
	leaq	.LC0(%rip), %rax
	jmp	.L7
.L6:
	leaq	.LC1(%rip), %rax
.L7:
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	movq	-8(%rbp), %rax
	movl	$20, %esi
	movq	%rax, %rdi
	call	enqueue
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	is_empty
	testb	%al, %al
	je	.L8
	leaq	.LC0(%rip), %rax
	jmp	.L9
.L8:
	leaq	.LC1(%rip), %rax
.L9:
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	clear
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	is_empty
	testb	%al, %al
	je	.L10
	leaq	.LC0(%rip), %rax
	jmp	.L11
.L10:
	leaq	.LC1(%rip), %rax
.L11:
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC12(%rip), %rdi
	call	puts@PLT
	movl	$0, -12(%rbp)
	jmp	.L12
.L13:
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	enqueue
	addl	$1, -12(%rbp)
.L12:
	cmpl	$10, -12(%rbp)
	jne	.L13
	leaq	.LC13(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	print_queue
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	dequeue
	movl	%eax, %esi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	dequeue
	movl	%eax, %esi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	peek
	movl	%eax, %esi
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	peek
	movl	%eax, %esi
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC13(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	print_queue
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	get_size
	movl	%eax, %esi
	leaq	.LC16(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.globl	is_empty
	.type	is_empty, @function
is_empty:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	testl	%eax, %eax
	sete	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	is_empty, .-is_empty
	.section	.rodata
.LC17:
	.string	"already empty Queue"
	.text
	.globl	clear
	.type	clear, @function
clear:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	is_empty
	testb	%al, %al
	je	.L17
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	jmp	.L21
.L17:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L19
.L20:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movl	16(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 16(%rax)
.L19:
	movq	-24(%rbp), %rax
	movl	16(%rax), %eax
	testl	%eax, %eax
	jne	.L20
	movq	-24(%rbp), %rax
	movq	$0, 8(%rax)
.L21:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	clear, .-clear
	.globl	enqueue
	.type	enqueue, @function
enqueue:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L23
	movl	$0, %eax
	jmp	.L24
.L23:
	movq	-8(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	is_empty
	testb	%al, %al
	je	.L25
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L26
.L25:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L26:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movl	16(%rax), %eax
	leal	1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 16(%rax)
	movl	$1, %eax
.L24:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	enqueue, .-enqueue
	.section	.rodata
.LC18:
	.string	"Queue is empty"
	.text
	.globl	dequeue
	.type	dequeue, @function
dequeue:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	is_empty
	testb	%al, %al
	je	.L28
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
	movl	$-1, %eax
	jmp	.L29
.L28:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movl	16(%rax), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 16(%rax)
	movl	-4(%rbp), %eax
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	dequeue, .-dequeue
	.globl	peek
	.type	peek, @function
peek:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	is_empty
	testb	%al, %al
	je	.L31
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
	movl	$-2147483648, %eax
	jmp	.L32
.L31:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %eax
.L32:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	peek, .-peek
	.globl	get_size
	.type	get_size, @function
get_size:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	get_size, .-get_size
	.section	.rodata
.LC19:
	.string	"{ "
.LC20:
	.string	"%d "
.LC21:
	.string	"}"
	.text
	.globl	print_queue
	.type	print_queue, @function
print_queue:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	leaq	.LC19(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L36
.L37:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC20(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L36:
	cmpq	$0, -8(%rbp)
	jne	.L37
	leaq	.LC21(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	print_queue, .-print_queue
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
