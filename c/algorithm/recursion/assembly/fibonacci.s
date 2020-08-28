	.file	"fibonacci.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	jmp	.L2
.L3:
	movl	-8(%rbp), %eax
	movl	%eax, %edi
	call	fibonacci
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -8(%rbp)
.L2:
	cmpl	$9, -8(%rbp)
	jbe	.L3
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	fibonacci_tailrec
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L4:
	cmpl	$9, -4(%rbp)
	jbe	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	fibonacci
	.type	fibonacci, @function
fibonacci:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, -20(%rbp)
	cmpl	$1, -20(%rbp)
	ja	.L8
	movl	-20(%rbp), %eax
	jmp	.L9
.L8:
	movl	-20(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	fibonacci
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fibonacci
	addl	%ebx, %eax
.L9:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	fibonacci, .-fibonacci
	.globl	fibonacci_tailrec
	.type	fibonacci_tailrec, @function
fibonacci_tailrec:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	$1, %edx
	movl	$0, %esi
	movl	%eax, %edi
	call	__fibonacci_tailrec
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	fibonacci_tailrec, .-fibonacci_tailrec
	.globl	__fibonacci_tailrec
	.type	__fibonacci_tailrec, @function
__fibonacci_tailrec:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L13
	movl	-8(%rbp), %eax
	jmp	.L14
.L13:
	cmpl	$1, -4(%rbp)
	jne	.L15
	movl	-12(%rbp), %eax
	jmp	.L14
.L15:
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	addl	%eax, %edx
	movl	-4(%rbp), %eax
	leal	-1(%rax), %ecx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	%ecx, %edi
	call	__fibonacci_tailrec
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	__fibonacci_tailrec, .-__fibonacci_tailrec
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
