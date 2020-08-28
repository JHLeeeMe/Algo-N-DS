	.file	"bit_vector.c"
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
	subq	$96, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %r12
	movl	$1, -64(%rbp)
	movl	$82, -60(%rbp)
	movl	$32, -56(%rbp)
	movl	$9, -52(%rbp)
	movl	$3, -48(%rbp)
	movl	$103, -44(%rbp)
	leaq	-64(%rbp), %rax
	movl	$6, %esi
	movq	%rax, %rdi
	call	max
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %ebx
	movq	%rbx, %rax
	subq	$1, %rax
	movq	%rax, -80(%rbp)
	movq	%rbx, -128(%rbp)
	movq	$0, -120(%rbp)
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
	movq	%rax, -72(%rbp)
	movl	$0, -92(%rbp)
	jmp	.L2
.L3:
	movq	-72(%rbp), %rax
	movl	-92(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	set_bit
	addl	$1, -92(%rbp)
.L2:
	movl	-92(%rbp), %eax
	cmpq	%rax, %rbx
	ja	.L3
	movl	$0, -96(%rbp)
	jmp	.L4
.L5:
	movq	-72(%rbp), %rax
	movl	-96(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	test_bit
	addl	$1, -96(%rbp)
.L4:
	movl	-96(%rbp), %eax
	cmpq	%rax, %rbx
	ja	.L5
	movl	$0, -100(%rbp)
	jmp	.L6
.L7:
	movq	-72(%rbp), %rax
	movl	-100(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	clear_bit
	addl	$1, -100(%rbp)
.L6:
	movl	-100(%rbp), %eax
	cmpq	%rax, %rbx
	ja	.L7
	movl	$0, -88(%rbp)
	jmp	.L8
.L9:
	movq	-72(%rbp), %rax
	movl	-88(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	test_bit
	addl	$1, -88(%rbp)
.L8:
	movl	-88(%rbp), %eax
	cmpq	%rax, %rbx
	ja	.L9
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
	movzbl	(%rdx), %edx
	movl	%edx, %edi
	movl	-12(%rbp), %edx
	andl	$7, %edx
	movl	$1, %esi
	movl	%edx, %ecx
	sall	%cl, %esi
	movl	%esi, %edx
	orl	%edi, %edx
	movl	%eax, %ecx
	movq	-8(%rbp), %rax
	addq	%rcx, %rax
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
	movl	%edx, %esi
	movl	-12(%rbp), %edx
	andl	$7, %edx
	movl	$1, %edi
	movl	%edx, %ecx
	sall	%cl, %edi
	movl	%edi, %edx
	notl	%edx
	andl	%esi, %edx
	movl	%eax, %ecx
	movq	-8(%rbp), %rax
	addq	%rcx, %rax
	movb	%dl, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	clear_bit, .-clear_bit
	.section	.rodata
.LC0:
	.string	"%d-th bit is 1\n"
.LC1:
	.string	"%d-th bit is 0\n"
	.text
	.globl	test_bit
	.type	test_bit, @function
test_bit:
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
	movl	-12(%rbp), %eax
	shrl	$3, %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movl	-12(%rbp), %eax
	andl	$7, %eax
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L15
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L17
.L15:
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L17:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	test_bit, .-test_bit
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
	jmp	.L19
.L21:
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jnb	.L20
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
.L20:
	addl	$1, -4(%rbp)
.L19:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jb	.L21
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	max, .-max
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
