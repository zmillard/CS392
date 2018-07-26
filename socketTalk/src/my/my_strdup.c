/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
/*#include "my.h"
char *my_strdup(char *str){
    int size = 0;
    char *ret = NULL;
    if (str){
        for (size = 0; str[size] != '\0'; size++);
        ret = (char *)malloc(size * sizeof(char));
        for (size = 0; str[size] != '\0'; size++){
			ret[size] = str[size];
		}
        ret[size] = '\0';
    }
    return ret;
}*/
#include "my.h"
#include <stdlib.h>
char* my_strdup(char* str){
    int len;
    int i;
    char* newstr;
    
    if (str == NULL)
        return NULL;

    len = my_strlen(str);
    newstr = (char*) malloc((len+1) * sizeof(char));
    for (i = 0; i < len; i++){
        *newstr = *str;
        newstr++;
        str++;
    }
    *newstr = *str;
    for(i = 0; i < len; i++){
        newstr--;
    }
    return newstr;
}