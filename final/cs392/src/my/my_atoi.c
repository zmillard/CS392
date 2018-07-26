/*Zoe Millard
*I pledge my honor that I have abided by the Stevens Honor System. -zm
*/
#include "my.h"
#include <limits.h>
int my_atoi(char *str){
  int ret = 0, neg = 0, i = 0, lowerIndex = 0, upperIndex = 0, foundNum = 0;
  long retNum = 0;

  if (str){
      for (i = 0; str[i] != '\0'; i++){
        if (str[i] - '0' < 10 && str[i] - '0' >= 0 && !foundNum){
            lowerIndex = i;
            foundNum = 1;
        }else if (!foundNum && str[i] == '-'){
          neg = !neg;
        }else if (foundNum && (str[i] - '0' < 0 || str[i] - '0' >= 10)){
          upperIndex = i;
        }
      }
      upperIndex = (upperIndex)? upperIndex: i;
      for (i = lowerIndex; i < upperIndex && str[i] != '\0'; i++){
        if (str[i] - '0' < 10 && str[i] - '0' >= 0){
          retNum = (retNum * 10) + (str[i] - '0');
        }
      }
      if (neg){
        retNum *= -1;
      }
      if (retNum >= -2147483648 && retNum <= 2147483647){
        ret = (int)retNum;
      }
  }
  return ret;








    /*int r = 0;
    char neg = 1;
	if(c == NULL){
		return 0;
	}
    while (*c){
        if(*c == '-'){
            neg *= -1;
        }else if((*c - '0') >= 0 && (*c - '0') <= 9){
            r = (r*10) + (*c - '0');
        }else if(r != 0){
			return r * neg;
		}
		c++;
    }
    return r * neg;*/
}
