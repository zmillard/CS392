/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
int my_atoi(char *c){
    int r = 0;
    char neg = 1;
	if(c == NULL){
		return 0;
	}
    while (*c){
        if(*c == '-'){
            neg *= -1;
        }else if((*c - '0') >= 0 && (*c - '0') <= 9){
            r = (r*10) + (*c - '0');
        }else if(r != 0){
			return r * neg;
		}
		c++;
    }
    return r * neg;
} 