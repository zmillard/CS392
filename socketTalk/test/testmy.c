  #include <stdio.h>
  #include "my.h"
  int main(){

  /*char a[] = "a";
  char ab[] = "ab";
  char abc[] = "abc";*/
  char test2[] = "123456789";
  char test[] = "h";
  char test3[] = "";
  char test4[] = "";


 /* my_int(1);
  my_str("");
  my_str(NULL);
  my_str("Hello");
  my_str(" World!\n");
  my_char('\n');*/
  my_num_base(9, test);
  my_num_base(0, test2);
  my_num_base(-2147483647, test2);
  my_strnconcat(test3, test4, 4);
  /*printf("%i\n", my_strlen(a));
  printf("%i\n", my_strlen(""));
  printf("%i\n", my_strlen(NULL));
  printf("%i\n", my_strlen(ab));
  printf("%i\n", my_strlen(abc));
  my_str(a);
  printf(" %i\n", my_revstr(a));
  my_str(ab);
  printf(" %i\n", my_revstr(ab));
  my_str(abc);
  printf(" %i\n", my_revstr(abc));
  printf(" %i\n", my_revstr(NULL));
  my_alpha();*/

  return 0;
}
