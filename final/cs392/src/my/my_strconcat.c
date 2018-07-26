/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
/*char *my_strconcat(char *a, char *b){
    int size = 0;
	int	i = 0;
    char *ret = NULL;
    if (a && b){
        for (i = 0; a[i] != '\0'; i++, size++);
        for (i = 0; b[i] != '\0'; i++, size++);
        ret = (char*)malloc(size * sizeof(char));
        for (i = 0; a[i] != '\0'; i++){
			ret[i] = a[i];
		}         
        for (size = 0; b[size] != '\0'; size++, i++){
			ret[i] = b[size];
		}        
        ret[i] = '\0';
    }else if (a){
		ret = a;
	}else if (b){
		ret = b;
	}      
    return ret;
}*/
char* my_strconcat(char* a, char* b){
    /***Allocates new memory.**
Copies concatenated strings in that new memory
Returns pointer to it
If both NULL return NULL
Returns new memory, with contents of a followed by contents of b*/
    int i;
    int len;
    char* newstr;
    if (a == NULL){
        if(b == NULL) {
            return NULL;
        }
        return my_strdup(b);
    }
    if (b == NULL){
        return my_strdup(a);
    }
    len = my_strlen(a) + my_strlen(b) + 1;
   
    newstr = (char*) malloc(len * sizeof(char));
    
    while(*a != '\0'){
        *newstr = *a;
        a++;
        newstr++;
    }
    while(*b != '\0'){
        *newstr = *b;
        b++;
        newstr++;
    }
    *newstr = '\0';
    len--;
    for (i = 0; i < len; i++){
        newstr--;
    }
    return newstr;
}