/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
int my_strcmp(char *a, char *b){
    int i = 0;
	int size1 = 0;
	int	size2 = 0;
    int val = 0;
    if (a&&b){
        for (size1 = 0; a[size1] != '\0'; size1++); /*gets location of /0 */
        for (size2 = 0; b[size2] != '\0'; size2++);
        if (size1==0 && size2>0){
			return -1; /*if there is nothing in one return -1*/
        }else if (size2==0 && size1>0){
            return 1;
        }else{
            for (i = 0; (a[i] != '\0') && (b[i] != '\0'); i++){
				if (a[i] > b[i]){
                    return 1;
                }else if (a[i] < b[i]){
                    return -1;
                }
			}
			if( size1 < size2){
				return -1;
			}else if(size1 > size2){
				return 1;
			}
        }
    }else if(!a && !b){
		val = 0;
	}else if (!a){
		val = -1;
	}else if (!b){
		val = 1;
	}
    return val;
}