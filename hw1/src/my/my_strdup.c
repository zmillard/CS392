/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
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
}