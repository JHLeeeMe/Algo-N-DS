	.file	"bit_vector.c"
	.text
	.section	.rodata
.LC0:
	.string	"###################"
.LC1:
	.string	"# Init bit_vector #"
.LC2:
	.string	"##################"
.LC3:
	.string	"# Set bit_vector #"
.LC4:
	.string	"####################"
.LC5:
	.string	"# Clear bit_vector #"
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
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$112, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %r12
	movl	$1, -80(%rbp)
	movl	$20, -76(%rbp)
	movl	$32, -72(%rbp)
	movl	$9, -68(%rbp)
	movl	$3, -64(%rbp)
	movl	$10, -60(%rbp)
	movl	$7, -56(%rbp)
	movl	$19, -52(%rbp)
	movl	$16, -48(%rbp)
	leaq	-80(%rbp), %rax
	movl	$9, %esi
	movq	%rax, %rdi
	call	max
	movl	%eax, -100(%rbp)
	movl	-100(%rbp), %ebx
	movq	%rbx, %rax
	subq	$1, %rax
	movq	%rax, -96(%rbp)
	movq	%rbx, -144(%rbp)
	movq	$0, -136(%rbp)
	movq	%rbx, %r13
	movl	$0, %r14d
	movl	$16, %eax
	subq	$1, %rax
	addq	%rbx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$0, %rax
	movq	%rax, -88(%rbp)
	movl	-100(%rbp), %edx
	movq	-88(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$0, -108(%rbp)
	jmp	.L2
.L3:
	movq	-88(%rbp), %rax
	movl	-108(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	test_bit
	addl	$1, -108(%rbp)
.L2:
	movl	-108(%rbp), %edx
	leaq	1(%rbx), %rax
	cmpq	%rax, %rdx
	jb	.L3
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$0, -112(%rbp)
	jmp	.L4
.L5:
	movl	-112(%rbp), %eax
	movl	-80(%rbp,%rax,4), %edx
	movq	-88(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	set_bit
	addl	$1, -112(%rbp)
.L4:
	cmpl	$8, -112(%rbp)
	jbe	.L5
	movl	$0, -116(%rbp)
	jmp	.L6
.L7:
	movq	-88(%rbp), %rax
	movl	-116(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	test_bit
	addl	$1, -116(%rbp)
.L6:
	movl	-116(%rbp), %edx
	leaq	1(%rbx), %rax
	cmpq	%rax, %rdx
	jb	.L7
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	movq	-88(%rbp), %rax
	movl	-100(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	clear_bit_all
	movl	$0, -104(%rbp)
	jmp	.L8
.L9:
	movq	-88(%rbp), %rax
	movl	-104(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	test_bit
	addl	$1, -104(%rbp)
.L8:
	movl	-104(%rbp), %edx
	leaq	1(%rbx), %rax
	cmpq	%rax, %rdx
	jb	.L9
	movq	%r12, %rsp
	movl	$0, %eax
	movq	-40(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leaq	-32(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	set_bit
	.type	set_bit, @function
set_bit:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	shrl	$3, %eax
	movl	%eax, %ecx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rdx), %esi
	movl	-12(%rbp), %edx
	andl	$7, %edx
	movl	$1, %edi
	movl	%edx, %ecx
	sall	%cl, %edi
	movl	%edi, %edx
	movl	%edx, %ecx
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	orl	%ecx, %esi
	movl	%esi, %edx
	movb	%dl, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	set_bit, .-set_bit
	.globl	clear_bit
	.type	clear_bit, @function
clear_bit:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	shrl	$3, %eax
	movl	%eax, %ecx
	movq	-8(%rbp), %rdx
	addq	%rcx, %rdx
	movzbl	(%rdx), %edx
	movl	-12(%rbp), %ecx
	andl	$7, %ecx
	movl	$1, %esi
	sall	%cl, %esi
	movl	%esi, %ecx
	notl	%ecx
	movl	%eax, %esi
	movq	-8(%rbp), %rax
	addq	%rsi, %rax
	andl	%ecx, %edx
	movb	%dl, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	clear_bit, .-clear_bit
	.globl	clear_bit_all
	.type	clear_bit_all, @function
clear_bit_all:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	clear_bit_all, .-clear_bit_all
	.globl	max
	.type	max, @function
max:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L16
.L18:
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jnb	.L17
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
.L17:
	addl	$1, -4(%rbp)
.L16:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jb	.L18
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	max, .-max
	.section	.rodata
.LC6:
	.string	"%d-th bit is 1\n"
.LC7:
	.string	"%d-th bit is 0\n"
	.text
	.globl	test_bit
	.type	test_bit, @function
test_bit:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	shrl	$3, %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %edx
	movl	-12(%rbp), %eax
	andl	$7, %eax
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L21
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L23
.L21:
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L23:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	test_bit, .-test_bit
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
