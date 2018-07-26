/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
char* my_strfind(char *c, char b){
	if (c){
		while (*c != '\0'){
			if (*c == b){
				return c;
			}
			c++;
		}
	}else if(!c){
		return NULL;
	}
	return NULL;
}