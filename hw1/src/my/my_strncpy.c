/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
char *my_strncpy(char *dst, char *src, int n){
    int i = 0;
    if (dst && src){
        for (i = 0; (i<n) && (src[i]!='\0'); i++){
			dst[i] = src[i];
		}
        dst[i] = '\0';
    }else if(!dst && !src){
		return NULL;
	}
    return dst;
}