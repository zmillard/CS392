#include <math.h>
#include "my.h"
void my_int(int i){
	int save_place;
	int num;
	int j;
	save_place = 0;
	j = 100000;
	while(j >= 10){
		if((i%j) >= i){
			save_place = j;
		}
		j /= 10;
	}
	j = save_place;
	while (j >= 10){
		num = ((i % j) - (i % (j/10)));
		my_char((char)(num + '0'));
		j /= 10;
	}
	return;
}