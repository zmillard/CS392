/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
int my_strlen(char* c){
	int count = 0;
	if(c == NULL){
		return -1;
	}
	while(c[count] != '\0'){
		count++;
	}
	return count;
}