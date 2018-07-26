#include "my.h"
void my_str(char* c){
	int count = my_strlen(c);
	int i;
	if(c == NULL){
	}else{
		for(i = 0; i < count; i++){
			my_char(c[i]);
		}
	}
	
}