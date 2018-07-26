/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
char *my_strcat(char *dst, char *src){
    int i = 0, j = 0;
    if (dst&&src){
        for (i = 0; dst[i]!='\0'; i++);
        for (j = 0; src[j]!='\0'; j++){
			dst[i++] = src[j];
		}
        dst[i] = '\0';
    }else if(!src){
		return dst;
	}else if(!dst){
		return NULL;
	}
    return dst;
}
