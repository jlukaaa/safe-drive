	.file	"bmp.c"
	.section .rdata,"dr"
LC0:
	.ascii "rb\0"
LC1:
	.ascii "fopen\0"
LC2:
	.ascii "Failed to read BMP headers\12\0"
	.align 4
LC3:
	.ascii "Unsupported BMP format (only uncompressed 24bpp)\12\0"
LC4:
	.ascii "malloc\0"
LC5:
	.ascii "Failed to read BMP scanline\12\0"
	.text
	.globl	_load_bmp
	.def	_load_bmp;	.scl	2;	.type	32;	.endef
_load_bmp:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$120, %esp
	movl	$LC0, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fopen
	movl	%eax, -20(%ebp)
	cmpl	$0, -20(%ebp)
	jne	L2
	movl	$LC1, (%esp)
	call	_perror
	movl	$0, %eax
	jmp	L17
L2:
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$14, 4(%esp)
	leal	-62(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	cmpl	$1, %eax
	jne	L4
	movl	-20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$40, 4(%esp)
	leal	-102(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	cmpl	$1, %eax
	je	L5
L4:
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$27, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC2, (%esp)
	call	_fwrite
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L17
L5:
	movzwl	-62(%ebp), %eax
	cmpw	$19778, %ax
	jne	L6
	movzwl	-88(%ebp), %eax
	cmpw	$24, %ax
	jne	L6
	movl	-86(%ebp), %eax
	testl	%eax, %eax
	je	L7
L6:
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$49, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC3, (%esp)
	call	_fwrite
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L17
L7:
	movl	-98(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	-94(%ebp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	xorl	%eax, %edx
	movl	%edx, -28(%ebp)
	subl	%eax, -28(%ebp)
	movl	-24(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	cltd
	andl	$3, %edx
	addl	%edx, %eax
	sarl	$2, %eax
	sall	$2, %eax
	movl	%eax, -32(%ebp)
	movl	-24(%ebp), %eax
	imull	-28(%ebp), %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -36(%ebp)
	cmpl	$0, -36(%ebp)
	jne	L8
	movl	$LC4, (%esp)
	call	_perror
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L17
L8:
	movl	-52(%ebp), %eax
	movl	$0, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	$0, -12(%ebp)
	jmp	L9
L16:
	movl	-94(%ebp), %eax
	testl	%eax, %eax
	jle	L10
	movl	-28(%ebp), %eax
	subl	$1, %eax
	subl	-12(%ebp), %eax
	jmp	L11
L10:
	movl	-12(%ebp), %eax
L11:
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	imull	-24(%ebp), %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -44(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -48(%ebp)
	cmpl	$0, -48(%ebp)
	jne	L12
	movl	$LC4, (%esp)
	call	_perror
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L17
L12:
	movl	-32(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	movl	%eax, %edx
	movl	-32(%ebp), %eax
	cmpl	%eax, %edx
	je	L13
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$28, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC5, (%esp)
	call	_fwrite
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	jmp	L17
L13:
	movl	$0, -16(%ebp)
	jmp	L14
L15:
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	-44(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	-48(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%ecx)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	-44(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	-48(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%ecx)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	-44(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	-48(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%ecx)
	addl	$1, -16(%ebp)
L14:
	movl	-16(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jl	L15
	movl	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	addl	$1, -12(%ebp)
L9:
	movl	-12(%ebp), %eax
	cmpl	-28(%ebp), %eax
	jl	L16
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	12(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%eax)
	movl	-36(%ebp), %eax
L17:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.section .rdata,"dr"
LC6:
	.ascii "wb\0"
LC7:
	.ascii "Failed to write BMP headers\12\0"
	.text
	.globl	_write_bmp
	.def	_write_bmp;	.scl	2;	.type	32;	.endef
_write_bmp:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$120, %esp
	movl	16(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	cltd
	andl	$3, %edx
	addl	%edx, %eax
	sarl	$2, %eax
	sall	$2, %eax
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	imull	20(%ebp), %eax
	movl	%eax, -28(%ebp)
	movw	$19778, -58(%ebp)
	movl	-28(%ebp), %eax
	addl	$54, %eax
	movl	%eax, -56(%ebp)
	movw	$0, -52(%ebp)
	movw	$0, -50(%ebp)
	movl	$54, -48(%ebp)
	movl	$40, -98(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -94(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -90(%ebp)
	movw	$1, -86(%ebp)
	movw	$24, -84(%ebp)
	movl	$0, -82(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -78(%ebp)
	movl	$2835, -74(%ebp)
	movl	$2835, -70(%ebp)
	movl	$0, -66(%ebp)
	movl	$0, -62(%ebp)
	movl	$LC6, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fopen
	movl	%eax, -32(%ebp)
	cmpl	$0, -32(%ebp)
	jne	L19
	movl	$LC1, (%esp)
	call	_perror
	movl	$-1, %eax
	jmp	L30
L19:
	movl	-32(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$14, 4(%esp)
	leal	-58(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	cmpl	$1, %eax
	jne	L21
	movl	-32(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$40, 4(%esp)
	leal	-98(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	cmpl	$1, %eax
	je	L22
L21:
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$28, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC7, (%esp)
	call	_fwrite
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$-1, %eax
	jmp	L30
L22:
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -36(%ebp)
	cmpl	$0, -36(%ebp)
	jne	L23
	movl	$LC4, (%esp)
	call	_perror
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$-1, %eax
	jmp	L30
L23:
	movl	$0, -12(%ebp)
	jmp	L24
L29:
	movl	20(%ebp), %eax
	subl	$1, %eax
	subl	-12(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-40(%ebp), %eax
	imull	16(%ebp), %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -44(%ebp)
	movl	$0, -16(%ebp)
	jmp	L25
L26:
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	-36(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	-44(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%ecx)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	-36(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	-44(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%ecx)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	-36(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	-44(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, (%ecx)
	addl	$1, -16(%ebp)
L25:
	movl	-16(%ebp), %eax
	cmpl	16(%ebp), %eax
	jl	L26
	movl	16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	jmp	L27
L28:
	movl	-20(%ebp), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	addl	$1, -20(%ebp)
L27:
	movl	-20(%ebp), %eax
	cmpl	-24(%ebp), %eax
	jl	L28
	movl	-24(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$1, 4(%esp)
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	addl	$1, -12(%ebp)
L24:
	movl	-12(%ebp), %eax
	cmpl	20(%ebp), %eax
	jl	L29
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
L30:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.globl	_grayscale_average
	.def	_grayscale_average;	.scl	2;	.type	32;	.endef
_grayscale_average:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L32
L33:
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -5(%ebp)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -6(%ebp)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -7(%ebp)
	movzbl	-5(%ebp), %edx
	movzbl	-6(%ebp), %eax
	addl	%eax, %edx
	movzbl	-7(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	$1431655766, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movb	%al, -8(%ebp)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-8(%ebp), %eax
	movb	%al, (%edx)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-8(%ebp), %eax
	movb	%al, (%edx)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-8(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -4(%ebp)
L32:
	movl	12(%ebp), %eax
	imull	16(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jg	L33
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_grayscale_luminance
	.def	_grayscale_luminance;	.scl	2;	.type	32;	.endef
_grayscale_luminance:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$32, %esp
	movl	$0, -4(%ebp)
	jmp	L35
L36:
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -5(%ebp)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -6(%ebp)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -7(%ebp)
	movzbl	-5(%ebp), %eax
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	fldl	LC8
	fmulp	%st, %st(1)
	movzbl	-6(%ebp), %eax
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	fldl	LC9
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movzbl	-7(%ebp), %eax
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	fldl	LC10
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fnstcw	-18(%ebp)
	movzwl	-18(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -20(%ebp)
	fldcw	-20(%ebp)
	fistps	-22(%ebp)
	fldcw	-18(%ebp)
	movzwl	-22(%ebp), %eax
	movb	%al, -8(%ebp)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-8(%ebp), %eax
	movb	%al, (%edx)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-8(%ebp), %eax
	movb	%al, (%edx)
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-8(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -4(%ebp)
L35:
	movl	12(%ebp), %eax
	imull	16(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jg	L36
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.globl	_max3
	.def	_max3;	.scl	2;	.type	32;	.endef
_max3:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$28, %esp
	movl	8(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%cl, -20(%ebp)
	movb	%dl, -24(%ebp)
	movb	%al, -28(%ebp)
	movzbl	-20(%ebp), %eax
	movb	%al, -1(%ebp)
	movzbl	-24(%ebp), %eax
	cmpb	-1(%ebp), %al
	jbe	L38
	movzbl	-24(%ebp), %eax
	movb	%al, -1(%ebp)
L38:
	movzbl	-28(%ebp), %eax
	cmpb	-1(%ebp), %al
	jbe	L39
	movzbl	-28(%ebp), %eax
	movb	%al, -1(%ebp)
L39:
	movzbl	-1(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.globl	_min3
	.def	_min3;	.scl	2;	.type	32;	.endef
_min3:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$28, %esp
	movl	8(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	16(%ebp), %eax
	movb	%cl, -20(%ebp)
	movb	%dl, -24(%ebp)
	movb	%al, -28(%ebp)
	movzbl	-20(%ebp), %eax
	movb	%al, -1(%ebp)
	movzbl	-24(%ebp), %eax
	cmpb	-1(%ebp), %al
	jnb	L42
	movzbl	-24(%ebp), %eax
	movb	%al, -1(%ebp)
L42:
	movzbl	-28(%ebp), %eax
	cmpb	-1(%ebp), %al
	jnb	L43
	movzbl	-28(%ebp), %eax
	movb	%al, -1(%ebp)
L43:
	movzbl	-1(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.globl	_grayscale_desaturation
	.def	_grayscale_desaturation;	.scl	2;	.type	32;	.endef
_grayscale_desaturation:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 3, -12
	movl	$0, -8(%ebp)
	jmp	L46
L47:
	movl	-8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -9(%ebp)
	movl	-8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -10(%ebp)
	movl	-8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, -11(%ebp)
	movzbl	-11(%ebp), %ecx
	movzbl	-10(%ebp), %edx
	movzbl	-9(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_max3
	movzbl	%al, %ebx
	movzbl	-11(%ebp), %ecx
	movzbl	-10(%ebp), %edx
	movzbl	-9(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_min3
	movzbl	%al, %eax
	addl	%ebx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movb	%al, -12(%ebp)
	movl	-8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-12(%ebp), %eax
	movb	%al, (%edx)
	movl	-8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-12(%ebp), %eax
	movb	%al, (%edx)
	movl	-8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	leal	2(%eax), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movzbl	-12(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -8(%ebp)
L46:
	movl	12(%ebp), %eax
	imull	16(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jg	L47
	nop
	addl	$28, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.globl	_mean_filter
	.def	_mean_filter;	.scl	2;	.type	32;	.endef
_mean_filter:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	imull	16(%ebp), %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -40(%ebp)
	cmpl	$0, -40(%ebp)
	je	L59
	movl	12(%ebp), %eax
	imull	16(%ebp), %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_memcpy
	movl	$1, -12(%ebp)
	jmp	L51
L58:
	movl	$1, -16(%ebp)
	jmp	L52
L57:
	movl	$0, -20(%ebp)
	movl	$0, -24(%ebp)
	movl	$0, -28(%ebp)
	movl	$-1, -32(%ebp)
	jmp	L53
L56:
	movl	$-1, -36(%ebp)
	jmp	L54
L55:
	movl	-12(%ebp), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	imull	12(%ebp), %eax
	movl	-16(%ebp), %ecx
	movl	-36(%ebp), %edx
	addl	%ecx, %edx
	addl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, -44(%ebp)
	movl	-44(%ebp), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	addl	%eax, -20(%ebp)
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	addl	%eax, -24(%ebp)
	movl	-44(%ebp), %eax
	leal	2(%eax), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	addl	%eax, -28(%ebp)
	addl	$1, -36(%ebp)
L54:
	cmpl	$1, -36(%ebp)
	jle	L55
	addl	$1, -32(%ebp)
L53:
	cmpl	$1, -32(%ebp)
	jle	L56
	movl	-12(%ebp), %eax
	imull	12(%ebp), %eax
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	addl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	movl	%eax, -48(%ebp)
	movl	-48(%ebp), %edx
	movl	8(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movl	-20(%ebp), %ecx
	movl	$954437177, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movb	%al, (%ebx)
	movl	-48(%ebp), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movl	-24(%ebp), %ecx
	movl	$954437177, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movb	%al, (%ebx)
	movl	-48(%ebp), %eax
	leal	2(%eax), %edx
	movl	8(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movl	-28(%ebp), %ecx
	movl	$954437177, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movb	%al, (%ebx)
	addl	$1, -16(%ebp)
L52:
	movl	12(%ebp), %eax
	subl	$1, %eax
	cmpl	-16(%ebp), %eax
	jg	L57
	addl	$1, -12(%ebp)
L51:
	movl	16(%ebp), %eax
	subl	$1, %eax
	cmpl	-12(%ebp), %eax
	jg	L58
	movl	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	jmp	L48
L59:
	nop
L48:
	addl	$68, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC12:
	.ascii "Image.bmp\0"
LC13:
	.ascii "bmp_24_copy_mean.bmp\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	leal	20(%esp), %eax
	movl	%eax, 8(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_load_bmp
	movl	%eax, 28(%esp)
	cmpl	$0, 28(%esp)
	jne	L61
	movl	$1, %eax
	jmp	L64
L61:
	movl	20(%esp), %edx
	movl	24(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_mean_filter
	movl	20(%esp), %edx
	movl	24(%esp), %eax
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC13, (%esp)
	call	_write_bmp
	testl	%eax, %eax
	je	L63
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$1, %eax
	jmp	L64
L63:
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, %eax
L64:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.section .rdata,"dr"
	.align 8
LC8:
	.long	-446676599
	.long	1070801616
	.align 8
LC9:
	.long	962072674
	.long	1071827124
	.align 8
LC10:
	.long	-1614907703
	.long	1069362970
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_perror;	.scl	2;	.type	32;	.endef
	.def	_fread;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_fseek;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
