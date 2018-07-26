/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
void my_num_base(int i, char *c){
	int size = my_strlen(c);
	unsigned int a = 1;
	if(c == NULL || c == '\0'){
		return;
	}
    if(i < 0){
        i *= -1; /*negates*/
        my_char('-');
    }
    if(size > 0){      
        while((a*size) < i){
            a *= size;
        }
        while(a > 0){
            my_char(c[i/a]);
            i %= a;
            a /= size;
        }
    }
}