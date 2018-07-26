/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
int my_strrindex(char* c, char d){
	int i = 0;
    int val = -1;
	if(d){
		if (c){
			for (i=0; c[i]!='\0'; i++){
				if (c[i]==d){
					val = i;
				}
			} 
		}
	}
    return val;
}