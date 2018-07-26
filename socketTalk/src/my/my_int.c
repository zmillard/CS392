#include "my.h"
#include <math.h>
#include <stdio.h>
void my_int(int n){
	int base;
	int exp = -1;
	int r;
	if (n == 0){
		my_char(((char)0) + '0');
	} else {
		if (n < 0){
			my_char('-');
		}
		base = 10;
		if (n > 0){
			n *= -1;
		}
		while(exp >= n / base){
			exp *= base;
		}	
		while(exp < 0){
			r = (n / exp);
			my_char(((char)r) + '0');
			n = n % exp;
			exp = exp / base;
		}  
	}
} 
