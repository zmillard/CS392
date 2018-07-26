/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
int my_strindex(char *c, char b){
    int i = 0;
    int val = -1;
    if (c){
		for (i=0; c[i]!='\0'; i++){
			if (c[i]==b){
                val = i;
                break;
            }
		} 
	}
    return val;
}