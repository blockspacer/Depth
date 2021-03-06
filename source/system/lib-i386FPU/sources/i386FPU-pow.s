/*!
 *  \file    i386FPU-pow.s
 *  \brief   pow assembler function (source).
 *  \author  J.T. Conklin (jtc@wimsey.com)
 *  \version 1.0
 *  \date    03.01.2006
 */
#=============================================================================
#   FILE DESCRIPTION: pow assembler function.
#
#   AUTHOR:    J.T. Conklin (jtc@wimsey.com)
#   GROUP:     Winning Strategies, Inc.
#   PROJECT:   The Depth
#   PART:      i386 FPU math library
#   VERSION:   1.0
#   CREATED:   03.01.2006 01:14:28
#
#   EMAIL:     chronoxor@gmail.com
#   WWW:       http://code.google.com/p/depth
#
#   COPYRIGHT: (C) 2006 The NULL workgroup. All Rights Reserved.
#-----------------------------------------------------------------------------
#   Copyright (C) 2006 The NULL workgroup
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#-----------------------------------------------------------------------------
#   FILE ID: $Id$
#
#   CHANGE LOG:
#
#   $Log$
#=============================================================================
# DESCRIPTION:
#   double pow(double base, double power)
#   These are general exponentiation functions, returning base raised to
#   power.
#=============================================================================
.text
.global _i386FPU_pow
_i386FPU_pow:
	fldl	12(%esp)		# y
	fxam

	fnstsw
	movb	%ah,		%dl
	andb	$0x45,		%ah
	cmpb	$0x40,		%ah	# is y == 0 ?
	je	11f

	cmpb	$0x05,		%ah	# is y == +inf ?
	je	12f

	cmpb	$0x01,		%ah	# is y == NaN ?
	je	30f

	fldl	4(%esp)			# x : y

	subl	$8,		%esp

	fxam
	fnstsw
	movb	%ah,		%dh
	andb	$0x45,		%ah
	cmpb	$0x40,		%ah
	je	20f			# x is +0

	cmpb	$0x05,		%ah
	je	15f			# x is +inf

	fxch				# y : x

	# First see whether `y' is a natural number.  In this case we
	# can use a more precise algorithm.
	fld	%st			# y : y : x
	fistpll	(%esp)			# y : x
	fildll	(%esp)			# int(y) : y : x
	fucomp	%st(1)			# y : x
	fnstsw
	sahf
	jne	2f

	# OK, we have an integer value for y.
	popl	%eax
	popl	%edx
	orl	$0,		%edx
	fstp	%st(0)			# x
	jns	4f			# y >= 0, jump
	fdivrl	one			# 1/x          (now referred to as x)
	negl	%eax
	adcl	$0,		%edx
	negl	%edx
4:	fldl	one			# 1 : x
	fxch

6:	shrdl	$1,		%edx,		%eax
	jnc	5f
	fxch
	fmul	%st(1)			# x : ST*x
	fxch
5:	fmul	%st(0),		%st	# x*x : ST*x
	shrl	$1,		%edx
	movl	%eax,		%ecx
	orl	%edx,		%ecx
	jnz	6b
	fstp	%st(0)			# ST*x
	ret

	# y is +NAN
30:	fldl	4(%esp)			# x : y
	fldl	one			# 1.0 : x : y
	fucomp	%st(1)			# x : y
	fnstsw
	sahf
	je	31f
	fxch				# y : x
31:	fstp	%st(1)
	ret

.align	4, 0x90
2:	# y is a real number.
	fxch				# x : y
	fldl	one			# 1.0 : x : y
	fld	%st(1)			# x : 1.0 : x : y
	fsub	%st(1)			# x-1 : 1.0 : x : y
	fabs				# |x-1| : 1.0 : x : y
	fcompl	limit			# 1.0 : x : y
	fnstsw
	fxch				# x : 1.0 : y
	sahf
	ja	7f
	fsub	%st(1)			# x-1 : 1.0 : y
	fyl2xp1				# log2(x) : y
	jmp	8f

7:	fyl2x				# log2(x) : y
8:	fmul	%st(1)			# y*log2(x) : y
	fst	%st(1)			# y*log2(x) : y*log2(x)
	frndint				# int(y*log2(x)) : y*log2(x)
	fsubr	%st,		%st(1)	# int(y*log2(x)) : fract(y*log2(x))
	fxch				# fract(y*log2(x)) : int(y*log2(x))
	f2xm1				# 2^fract(y*log2(x))-1 : int(y*log2(x))
	faddl	one			# 2^fract(y*log2(x)) : int(y*log2(x))
	fscale				# 2^fract(y*log2(x))*2^int(y*log2(x)) : int(y*log2(x))
	addl	$8,		%esp
	fstp	%st(1)			# 2^fract(y*log2(x))*2^int(y*log2(x))
	ret


	# pow(x,+0) = 1
.align	4, 0x90
11:	fstp	%st(0)			# pop y
	fldl	one
	ret

	# y == +inf
.align	4, 0x90
12:	fstp	%st(0)			# pop y
	fldl	4(%esp)			# x
	fabs
	fcompl	one			# < 1, == 1, or > 1
	fnstsw
	andb	$0x45,		%ah
	cmpb	$0x45,		%ah
	je	13f			# jump if x is NaN

	cmpb	$0x40,		%ah
	je	14f			# jump if |x| == 1

	shlb	$1,		%ah
	xorb	%ah,		%dl
	andl	$2,		%edx
	fldl	infinity(,%edx,4)
	ret

.align	4, 0x90
14:	fldl	one
	ret

.align	4, 0x90
13:	fldl	4(%esp)			# load x == NaN
	ret

.align	4, 0x90
	# x is +inf
15:	fstp	%st(0)			# y
	testb	$2,		%dh
	jz	16f			# jump if x == +inf

	# We must find out whether y is an odd integer.
	fld	%st			# y : y
	fistpll	(%esp)			# y
	fildll	(%esp)			# int(y) : y
	fucompp				# <empty>
	fnstsw
	sahf
	jne	17f

	# OK, the value is an integer, but is the number of bits small
	# enough so that all are coming from the mantissa?
	popl	%eax
	popl	%edx
	andb	$1,		%al
	jz	18f			# jump if not odd
	movl	%edx,		%eax
	orl	%edx,		%edx
	jns	155f
	negl	%eax
155:    cmpl	$0x00200000,	%eax
	ja	18f			# does not fit in mantissa bits
	# It's an odd integer.
	shrl	$31,		%edx
	fldl	minfinity(,%edx,8)
	ret

.align	4, 0x90
16:	fcompl	zero
	addl	$8,		%esp
	fnstsw
	shrl	$5,		%eax
	andl	$8,		%eax
	fldl	infinity(,%eax,1)
	ret

.align	4, 0x90
17:	shll	$30,		%edx	# sign bit for y in right position
	addl	$8,		%esp
18:	shrl	$31,		%edx
	fldl	infinity(,%edx,8)
        ret

.align	4, 0x90
	# x is +0
20:	fstp	%st(0)			# y
	testb	$2,		%dl
	jz	21f			# y > 0

	# x is +0 and y is < 0.  We must find out whether y is an odd integer.
	testb	$2,		%dh
	jz	25f

	fld	%st			# y : y
	fistpll	(%esp)			# y
	fildll	(%esp)			# int(y) : y
	fucompp				# <empty>
	fnstsw
	sahf
	jne	26f

	# OK, the value is an integer, but is the number of bits small
	# enough so that all are coming from the mantissa?
	popl	%eax
	popl	%edx
	andb	$1,		%al
	jz	27f			# jump if not odd
	cmpl	$0xffe00000,	%edx
	jbe	27f			# does not fit in mantissa bits
	# It's an odd integer.
	# Raise divide-by-zero exception and get minus infinity value.
	fldl	one
	fdivl	zero
	fchs
	ret

25:	fstp	%st(0)
26:	addl	$8,		%esp
27:	# Raise divide-by-zero exception and get infinity value.
	fldl	one
	fdivl	zero
	ret

.align	4, 0x90
	# x is +0 and y is > 0.  We must find out whether y is an odd integer.
21:	testb	$2,		%dh
	jz	22f

	fld	%st			# y : y
	fistpll	(%esp)			# y
	fildll	(%esp)			# int(y) : y
	fucompp				# <empty>
	fnstsw
	sahf
	jne	23f

	# OK, the value is an integer, but is the number of bits small
	# enough so that all are coming from the mantissa?
	popl	%eax
	popl	%edx
	andb	$1,		%al
	jz	24f			# jump if not odd
	cmpl	$0xffe00000,	%edx
	jae	24f			# does not fit in mantissa bits
	# It's an odd integer.
	fldl	mzero
	ret

22:	fstp	%st(0)
23:	addl	$8,		%esp	# Do not use 2 x pop
24:	fldl	zero
	ret

.align	4, 0x90
infinity:
	.byte 0, 0, 0, 0, 0, 0, 0xf0, 0x7f
minfinity:
	.byte 0, 0, 0, 0, 0, 0, 0xf0, 0xff
mzero:
	.byte 0, 0, 0, 0, 0, 0, 0, 0x80
zero:
	.double 0.0
one:
	.double 1.0
limit:
	.double 0.29
#=============================================================================
