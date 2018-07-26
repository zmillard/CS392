#include "my.h"
int my_revstr(char* c){
	int count = my_strlen(c);
	int i;
	int spot = 0;
	char temp;
	int len = my_strlen(c);
	if(c == NULL){
		return -1;
	}else{
		for(i = count; i > 0 && i != spot; i--){
			temp = c[spot];
			c[spot] = c[i];
			c[i] = temp;
			temp++;
			spot++;
		}
		
	}
	return len;
}