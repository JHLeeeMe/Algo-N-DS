	.file	"factorial.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d %d %d %d %d"
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
	subq	$48, %rsp
	movl	$0, %edi
	call	factorial
	movl	%eax, -40(%rbp)
	movl	$1, %edi
	call	factorial
	movl	%eax, -36(%rbp)
	movl	$2, %edi
	call	factorial
	movl	%eax, -32(%rbp)
	movl	$3, %edi
	call	factorial
	movl	%eax, -28(%rbp)
	movl	$4, %edi
	call	factorial
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %edi
	movl	-28(%rbp), %esi
	movl	-32(%rbp), %ecx
	movl	-36(%rbp), %edx
	movl	-40(%rbp), %eax
	movl	%edi, %r9d
	movl	%esi, %r8d
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %edi
	call	factorial_rec
	movl	%eax, -20(%rbp)
	movl	$1, %edi
	call	factorial_rec
	movl	%eax, -16(%rbp)
	movl	$2, %edi
	call	factorial_rec
	movl	%eax, -12(%rbp)
	movl	$3, %edi
	call	factorial_rec
	movl	%eax, -8(%rbp)
	movl	$4, %edi
	call	factorial_rec
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %edi
	movl	-8(%rbp), %esi
	movl	-12(%rbp), %ecx
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edi, %r9d
	movl	%esi, %r8d
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	factorial
	.type	factorial, @function
factorial:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L4
	cmpl	$1, -4(%rbp)
	jne	.L5
.L4:
	movl	$1, %eax
	jmp	.L6
.L5:
	movl	-4(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	factorial
	imull	-4(%rbp), %eax
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	factorial, .-factorial
	.globl	factorial_rec
	.type	factorial_rec, @function
factorial_rec:
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
	movl	$1, %esi
	movl	%eax, %edi
	call	__factorial_rec
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	factorial_rec, .-factorial_rec
	.globl	__factorial_rec
	.type	__factorial_rec, @function
__factorial_rec:
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
	cmpl	$0, -4(%rbp)
	jne	.L10
	movl	-8(%rbp), %eax
	jmp	.L11
.L10:
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	movl	-4(%rbp), %edx
	subl	$1, %edx
	movl	%eax, %esi
	movl	%edx, %edi
	call	__factorial_rec
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	__factorial_rec, .-__factorial_rec
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
