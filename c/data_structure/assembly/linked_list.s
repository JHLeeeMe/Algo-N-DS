	.file	"linked_list.c"
	.text
	.section	.rodata
.LC0:
	.string	"%i "
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
	subq	$32, %rsp
	movl	$8, %edi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	$0, (%rax)
	movq	-16(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$2, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$4, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$5, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$6, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$7, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$8, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$9, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	.L2
.L3:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L2:
	cmpq	$0, -24(%rbp)
	jne	.L3
	jmp	.L4
.L5:
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
.L4:
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.globl	add
	.type	add, @function
add:
.LFB6:
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
	jne	.L8
	movl	$0, %eax
	jmp	.L9
.L8:
	movq	-8(%rbp), %rax
	movl	-28(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L10
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L11
.L10:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L12
.L13:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L12:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L13
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L11:
	movl	$1, %eax
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	add, .-add
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
