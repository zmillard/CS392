/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
char* my_strrfind(char *c, char b){
	char* d = NULL;
    if (c){
		while (*c != '\0'){
			if (*c == b){
				d = c;
			}
			c++;
		}
	}else{
		return NULL;
	}
    return d;
}