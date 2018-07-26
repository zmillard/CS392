/* 
 * CS 392 Systems Programming - Homework 1 Data Lab 
 * 
 * Name - zoe millard
 * Email Id - zmillard@stevens.edu
 * Date - 2/17/17
 *
 * Stevens Honour Code - I pledge my onot that I have abided by the Stevens Honor System -zm
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; this is for grading purposes.
 * You can use the same using another control file with main.  
 */
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by the TAs. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  2. Make sure you test for all cases, especially the edge ones.
  3. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * Your code will be checked for C coding rules and standards.
 *  
 */


#endif

/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 *   Solution Provided for reference
 */
int bitAnd(int x, int y) {
  return (~(~x | ~y)); /*demorgans with bit not (or at least thats how i figured it out)*/
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
	return ((~x) & (~y)); /*demorgans with bit not (or at least thats how i figured it out)*/
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
	int a = x << 31; /*left shifts to remove all but lsb*/
	return (a >> 31); /*shifts right to copy lsb over*/
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return (!(x ^ y)); /*use xor to find if they're different then not it*/
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
	int a = ~0 << highbit; /*bit not of 0 shifted by highbit*/
	int b = ~(1 << highbit); /*bit not of 1 shifted by the highbit*/
	int c = ~0 << lowbit; /*bit not of 0 shifted by lowbit*/
	int d = (a & b) | (~c); /* if a = b or c is 1 -> d*/
	return (~d); /*returns not d*/
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) { 
	int a;
	int b;
	unsigned s1 = 0x55;
	unsigned s2 = 0x33;
	unsigned s3 = 0x0F;

	s1 = (((((s1 << 8) + 0x55) << 8) + 0x55)<< 8) + 0x55;/*left shift it three times to make it 01010...*/
	s2 = (((((s2 << 8) + 0x33) << 8) + 0x33)<< 8) + 0x33;/*left shift it three times to make it 00110011..*/
	s3 = (((((s3 << 8) + 0x0F) << 8) + 0x0F)<< 8) + 0x0F;/*left shift it three times to make it 00001111..*/
	
	a = ~((x>>1) & s1);
	x = x + a + 1; /*section 1 - split by sections*/
	a = (x >>2) & s2;
	x = (x & s2) + a; /*section 2*/
	a = (x >>4) & s3;
	x = (x & s3) + a; /*section 2*/
	x = x + (x>>8);
	x = x + (x>>16);
	return (x & 0x3F);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
	return ~(1 << 31);  /*left shift 31 spaces and returns 2's compliment to show max number*/
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
    return !(x >> 31);  /*rightshifts x 31 places then performs not in order to reverse inputs (pos is normally 0, neg is -1)*/
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
	int sum = x + y; /*gets sum*/
	int sx = x >> 31; /*rightshift to get sign x*/
	int sy = y >> 31; /*rightshift to get sign y*/
	int a = (sx ^ sy);
	int b = (sx ^ (sum >> 31));
	return (!(~a & b)); /*if signs are the same and the sign of sums and a number are the same */
}
/* 
 * rempwr2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: rempwr2(15,2) = 3, rempwr2(-35,3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int rempwr2(int x, int n) {
	int a = (1 << n) + ~0;  
    int b = x >> 31;
    int c = x & a;
	int d = (~((!!c)<< n))+1;
    return ((x & a) + (d &b));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
   int test = ((~x+1) + y) >> 31 & 1; /*shifts sign bit to the right*/
   int x1 = (1 << 31) & x; /*takes lowest bit and compares*/
   int y1 = (1 << 31) & y;
   int x2 = x1 ^ y1; /*compares w shifting*/
   x2 = (x2 >> 31) & 1;
   int a = (x1 >> 31);
   int b = (!test & !x2);
   return ((x2 & a) | b); /*if lower*/
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  int test = x >> 31; /*rightshifts to get the sign*/
  return ((~test & x) | (test & (~x + 1))); /*tests to see which is valid and returns the non neg version using bit not*/
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
	int y = ~x+1; /*gets bit not x + 1*/
	int z = ~0 ^ y; /*gets po2*/
	return (!!z); 
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	int x = 0x000000FF << 23; 
	int y = 0x7FFFFF & uf; 
	int z = x & uf;
	int z2 = x && y;
    if(z == z2){return uf;}
    return (uf ^ (1 << 31));
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
	unsigned a = 0x7FFFFFFF;		
	unsigned nan = 0x7F800001;
	unsigned b = uf & a; /*sets sign bit*/
	if (b >= nan){ /*Nan procedure*/
		return uf;
	}
	return b;
}

int main() {
  
  return 0;
}