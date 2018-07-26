/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
char *my_strnconcat(char *a, char *b, int n){
  int i = 0;
	int size = 0;
  char *ret = NULL;
  unsigned int size2 = my_strlen(a);
  unsigned int size3 = my_strlen(b);
  if(a == NULL && b == NULL){
    return NULL;
  }
  if(size2 == 0 && size3 == 0){
    return "";
  }
	if(n < 0){
		n = 0;
	}
    if (a || b){
        if (a){ for (i = 0; i < n && a[i] != '\0'; i++, size++);}
        if (b){	for (i = 0; i < n && b[i] != '\0'; i++, size++);}
		    i = 0;
        if (a && b){
			       size--;
		    }
        ret = (char *)malloc(size * sizeof(char));
        if (a){
			       for (i = 0; a[i] != '\0'; i++){
				           ret[i] = a[i];
			       }
		    }
        if (b){
			       for (size = 0; size < n && b[size] != '\0'; i++, size++){
				           ret[i] = b[size];
			       }
		    }
        if (n > 0){

			       ret[i] = '\0';
		    }

    }
    return ret;
}
