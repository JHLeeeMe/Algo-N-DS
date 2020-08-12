	.file	"simple_jpeg_checker.c"
	.text
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"Maybe JPEG"
.LC2:
	.string	"No"
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
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$2, -36(%rbp)
	je	.L2
	movl	$1, %eax
	jmp	.L7
.L2:
	movq	-48(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L4
	movl	$1, %eax
	jmp	.L7
.L4:
	movq	-24(%rbp), %rdx
	leaq	-11(%rbp), %rax
	movq	%rdx, %rcx
	movl	$1, %edx
	movl	$3, %esi
	movq	%rax, %rdi
	call	fread@PLT
	movzbl	-11(%rbp), %eax
	cmpb	$-1, %al
	jne	.L5
	movzbl	-10(%rbp), %eax
	cmpb	$-40, %al
	jne	.L5
	movzbl	-9(%rbp), %eax
	cmpb	$-1, %al
	jne	.L5
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	jmp	.L6
.L5:
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
.L6:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
.L7:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
