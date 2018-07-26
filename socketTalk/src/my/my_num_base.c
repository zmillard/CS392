/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
int rec = 0;
void my_num_base(int i, char *c){

	unsigned int size = my_strlen(c);
	/*unsigned int a = 1;*/
	int j;

	if(c == NULL || c == '\0' || c ==0 || size < 1){
		my_str("ERROR");
		return;
	}
  /*my_str("flag");*/
	if(i < 0){
		i *= -1; /*negates*/
		my_char('-');
	}
	/*if (size == 1){
		my_str(c);
		return;
	}else*/ if(i == 0 && rec == 0){
		my_str("0");
		return;
	}else	if(size == 1 && i >= 1){
		for(j = 0; j < i; j++){
			my_str(c);
		}
		return;
	}else{
		if (size == 1){
			while (size < i + 1){
				my_str(c);
				size++;
			}
			return;
		}
		if (i != 0)	{
			rec = 1;
			my_num_base(i / size, c);
			my_char(c[i % size]);
		}

		/*if(size > 1){
			while((a*size) < i){
				a *= size;
				my_int(a);
				my_str(" ");
			}
			while(a > 0){
				my_char(c[i/a]);
				i %= a;
				a /= size;
			}
		}else if (size == 1){
			my_str(c);
		}*/
		return;
	}


}
