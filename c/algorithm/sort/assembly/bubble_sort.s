	.file	"bubble_sort.c"
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
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$5, -48(%rbp)
	movl	$7, -44(%rbp)
	movl	$1, -40(%rbp)
	movl	$3, -36(%rbp)
	movl	$2, -32(%rbp)
	movl	$10, -28(%rbp)
	movl	$9, -24(%rbp)
	movl	$45, -20(%rbp)
	movl	$8, -52(%rbp)
	movl	-52(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	bubbleSort
	movl	$0, -56(%rbp)
	jmp	.L2
.L3:
	movl	-56(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -56(%rbp)
.L2:
	movl	-56(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L3
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	bubbleSort
	.type	bubbleSort, @function
bubbleSort:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	-28(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	.L7
.L11:
	movl	$0, -8(%rbp)
	jmp	.L8
.L10:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L9
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movl	-8(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
.L9:
	addl	$1, -8(%rbp)
.L8:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L10
	subl	$1, -12(%rbp)
.L7:
	cmpl	$0, -12(%rbp)
	jg	.L11
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	bubbleSort, .-bubbleSort
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
