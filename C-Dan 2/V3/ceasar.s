	.file	"ceasar.c"
	.text
	.globl	_encryptCeasar
	.def	_encryptCeasar;	.scl	2;	.type	32;	.endef
_encryptCeasar:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movw	%ax, -28(%ebp)
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, -16(%ebp)
	movl	$0, -12(%ebp)
	jmp	L2
L7:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -17(%ebp)
	cmpb	$96, -17(%ebp)
	jle	L3
	cmpb	$122, -17(%ebp)
	jle	L4
L3:
	cmpb	$64, -17(%ebp)
	jle	L5
	cmpb	$90, -17(%ebp)
	jg	L5
L4:
	movsbl	-17(%ebp), %eax
	movl	%eax, (%esp)
	call	_tolower
	movb	%al, -17(%ebp)
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movsbl	-17(%ebp), %eax
	leal	-97(%eax), %edx
	movswl	-28(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$26, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	addl	$97, %eax
	movb	%al, (%ebx)
	jmp	L6
L5:
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
L6:
	addl	$1, -12(%ebp)
L2:
	movl	-12(%ebp), %eax
	cmpl	-16(%ebp), %eax
	jl	L7
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	nop
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.globl	_decryptCeasar
	.def	_decryptCeasar;	.scl	2;	.type	32;	.endef
_decryptCeasar:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movw	%ax, -28(%ebp)
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L9
L15:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -13(%ebp)
	cmpb	$96, -13(%ebp)
	jle	L10
	cmpb	$122, -13(%ebp)
	jle	L11
L10:
	cmpb	$64, -13(%ebp)
	jle	L12
	cmpb	$90, -13(%ebp)
	jg	L12
L11:
	movsbl	-13(%ebp), %eax
	movl	%eax, (%esp)
	call	_tolower
	movb	%al, -13(%ebp)
	movzbl	-13(%ebp), %eax
	movzwl	-28(%ebp), %edx
	subl	%edx, %eax
	subl	$97, %eax
	movb	%al, -13(%ebp)
	cmpb	$0, -13(%ebp)
	jns	L13
	movzbl	-13(%ebp), %eax
	addl	$26, %eax
	movb	%al, -13(%ebp)
L13:
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movzbl	-13(%ebp), %edx
	movsbw	%dl, %cx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	subl	%ecx, %eax
	shrw	$8, %ax
	movl	%eax, %ecx
	sarb	$3, %cl
	movl	%edx, %eax
	sarb	$7, %al
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	$26, %ecx
	imull	%ecx, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	addl	$97, %eax
	movb	%al, (%ebx)
	jmp	L14
L12:
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%eax, %edx
	movl	-12(%ebp), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%edx)
L14:
	addl	$1, -12(%ebp)
L9:
	movl	-12(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jl	L15
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	nop
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_tolower;	.scl	2;	.type	32;	.endef
