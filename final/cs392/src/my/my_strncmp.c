/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
int my_strncmp(char *a, char *b, int n){
    int i;
	int size1 = 0;
	int	size2 = 0;
    int ret = 0;
    if (a && b){
        for (size1 = 0; a[size1] != '\0'; size1++); /*gets location of /0 */
        for (size2 = 0; b[size2] != '\0'; size2++);
        if (size1 == 0 && (size2 > 0)){
            ret = -1;
        }else if (size2 == 0 && (size1 > 0)){
            ret = 1;
        }else{
            for (i = 0; i < n && a[i] != '\0' && b[i] != '\0'; i++){
				if (a[i] > b[i]){
                    return 1;
                }else if (a[i] < b[i]){
                    return -1;
                }
			}
			if(size1 < size2 && size1 < n){
				return -1;
			}else if(size1 > size2 && size2 < n){
				return 1;
			}
        }
    }else if(!a && !b){
		ret = 0;
	}else if (!a){
		ret = -1;
	}else if (!b){
		ret = 1;
	}
    return ret;
}
