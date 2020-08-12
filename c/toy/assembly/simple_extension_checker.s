	.file	"simple_extension_checker.c"
	.text
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"Maybe JPEG"
.LC2:
	.string	"Maybe BMP"
.LC3:
	.string	"Maybe GIF"
.LC4:
	.string	"Maybe PNG"
.LC5:
	.string	"Maybe TIFF"
	.align 8
.LC6:
	.string	"Not an image file\nOR Not supported"
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
	jmp	.L14
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
	jmp	.L14
.L4:
	movq	-24(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rcx
	movl	$1, %edx
	movl	$8, %esi
	movq	%rax, %rdi
	call	fread@PLT
	movzbl	-16(%rbp), %eax
	cmpb	$-1, %al
	jne	.L5
	movzbl	-15(%rbp), %eax
	cmpb	$-40, %al
	jne	.L5
	movzbl	-14(%rbp), %eax
	cmpb	$-1, %al
	jne	.L5
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	jmp	.L6
.L5:
	movzbl	-16(%rbp), %eax
	cmpb	$66, %al
	jne	.L7
	movzbl	-15(%rbp), %eax
	cmpb	$77, %al
	jne	.L7
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	jmp	.L6
.L7:
	movzbl	-16(%rbp), %eax
	cmpb	$71, %al
	jne	.L8
	movzbl	-15(%rbp), %eax
	cmpb	$73, %al
	jne	.L8
	movzbl	-14(%rbp), %eax
	cmpb	$70, %al
	jne	.L8
	movzbl	-13(%rbp), %eax
	cmpb	$56, %al
	jne	.L8
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	jmp	.L6
.L8:
	movzbl	-16(%rbp), %eax
	cmpb	$-119, %al
	jne	.L9
	movzbl	-15(%rbp), %eax
	cmpb	$80, %al
	jne	.L9
	movzbl	-14(%rbp), %eax
	cmpb	$78, %al
	jne	.L9
	movzbl	-13(%rbp), %eax
	cmpb	$71, %al
	jne	.L9
	movzbl	-12(%rbp), %eax
	cmpb	$13, %al
	jne	.L9
	movzbl	-11(%rbp), %eax
	cmpb	$10, %al
	jne	.L9
	movzbl	-10(%rbp), %eax
	cmpb	$26, %al
	jne	.L9
	movzbl	-9(%rbp), %eax
	cmpb	$10, %al
	jne	.L9
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	jmp	.L6
.L9:
	movzbl	-16(%rbp), %eax
	cmpb	$73, %al
	jne	.L10
	movzbl	-15(%rbp), %eax
	cmpb	$32, %al
	jne	.L10
	movzbl	-14(%rbp), %eax
	cmpb	$73, %al
	je	.L11
.L10:
	movzbl	-16(%rbp), %eax
	cmpb	$73, %al
	jne	.L12
	movzbl	-15(%rbp), %eax
	cmpb	$73, %al
	jne	.L12
	movzbl	-14(%rbp), %eax
	cmpb	$42, %al
	jne	.L12
	movzbl	-13(%rbp), %eax
	testb	%al, %al
	je	.L11
.L12:
	movzbl	-16(%rbp), %eax
	cmpb	$77, %al
	jne	.L13
	movzbl	-15(%rbp), %eax
	cmpb	$77, %al
	jne	.L13
	movzbl	-14(%rbp), %eax
	testb	%al, %al
	jne	.L13
.L11:
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	jmp	.L6
.L13:
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
.L6:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
.L14:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L15
	call	__stack_chk_fail@PLT
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
