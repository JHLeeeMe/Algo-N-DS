	.file	"linear_search.c"
	.text
	.section	.rodata
.LC0:
	.string	"found!"
.LC1:
	.string	"Not found!"
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
	movl	$1, -48(%rbp)
	movl	$5, -44(%rbp)
	movl	$7, -40(%rbp)
	movl	$2, -36(%rbp)
	movl	$12, -32(%rbp)
	movl	$6, -28(%rbp)
	movl	$55, -24(%rbp)
	movl	$7, -52(%rbp)
	movl	-52(%rbp), %ecx
	leaq	-48(%rbp), %rax
	movl	$55, %edx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	linearSearch
	testb	%al, %al
	je	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	jmp	.L3
.L2:
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L3:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	linearSearch
	.type	linearSearch, @function
linearSearch:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L7
.L10:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -32(%rbp)
	jne	.L8
	movl	$1, %eax
	jmp	.L9
.L8:
	addl	$1, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L10
	movl	$0, %eax
.L9:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	linearSearch, .-linearSearch
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
