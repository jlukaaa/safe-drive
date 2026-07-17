	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "RT-RK!\0"
LC1:
	.ascii "Originalni tekst:  %s\12\0"
LC2:
	.ascii "Enkriptovani tekst: %s\12\0"
LC3:
	.ascii "Dekriptovani tekst: %s\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$224, %esp
	call	___main
	movl	$LC0, 220(%esp)
	movl	$4, 216(%esp)
	movl	220(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	216(%esp), %eax
	cwtl
	movl	%eax, 8(%esp)
	leal	116(%esp), %eax
	movl	%eax, 4(%esp)
	movl	220(%esp), %eax
	movl	%eax, (%esp)
	call	_encryptCeasar
	leal	116(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	216(%esp), %eax
	cwtl
	movl	%eax, 8(%esp)
	leal	16(%esp), %eax
	movl	%eax, 4(%esp)
	leal	116(%esp), %eax
	movl	%eax, (%esp)
	call	_decryptCeasar
	leal	16(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_encryptCeasar;	.scl	2;	.type	32;	.endef
	.def	_decryptCeasar;	.scl	2;	.type	32;	.endef
