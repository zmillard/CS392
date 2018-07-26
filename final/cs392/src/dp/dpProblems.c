#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
struct string_info{
	char* str; 
	int index; 
}; 
typedef struct string_info* String_Info;

/*
*
* With double pointers. There are two NULL checks you have to do:
* You need to check if BOTH head and tail are NULL.
* AND, you need to check if what head and tail point to are NULL. So, IE
*
* _____                                 _____
*|HEAD|                                 |TAIL|
*|NULL|->                           <-- |NULL|
* - ---                                 ------
* Here, we see we need to check if the head and tail are NULL. If we dont,
* when we try to do *head or *tail, we get a Seg Fault since there is nothing there to dereference.
* 
* Let us take a look at the other case mentioned:
* _____    _______________________     ______
*|HEAD|-> |NULL|NULL|NULL |NULL  | <-- |TAIL|
* - ---    -----------------------     ------
*           |     |    |    |
*           v     v    v    v
*
* If we try to derefence what head points to, we can do that! Head is not NULL, so we can do *head.
* BUT, *head returns NULL. Not a string, but a NULL. Hmmm... 
* 
* Let's say we want the first character of the first string. We can do (*head)[0].
* Or, we can do **head. That is, dereference head, and then derefence it again [so more like *(*head)]
* BUT, *head was NULL. As we saw earlier, if we try to derefence NULL, we get a seg fault.
* Thus, before we ever do **head or (*head)[x], we need to check if *head is NULL. 

* Don't just accept this fact. Make sure you understand it with this simple example
* It will get harder in the future, so if you have any questions, ASK NOW!
*
* ---------------------------------------------------------------------------------------------------------
*
* This lab also makes use of structs. If you know how to work with these, feel free to skip this section.
*
* Structs are like classes; they pack data into 1 'box', if you will.
*
* To use them, you need to first malloc the pointer. Note that the pointer to the struct is given to you:
* typedef struct string_info* String_Info. So, the pointer to a string_info struct is called String_Info.
* 
* Let's recall how we malloc'd strings. We did char* str = (char*)malloc(sizeof(char)*i), wher i is len
*
* We malloc structs in a similar way. Just replace char* with String_Info, and char with struct string_info. Make sense?
* Think about the i component. Do we need it? If we keep it, then we are saying we want to make i structs. But we only want 1 struct.
* So, do we need the i? 
*
* By a call to malloc, we were given a pointer to a chunk of memory that is the size of our struct.
* More specifically, we cast it to a String_Info type. That's great... Now what do we do with it?
* Well, we need to set it's components. How do we do that? (Hint! it involves the use of ->).
* Let's think. What would make sense to be on the left side? (where is what we are setting)
* What would make sense on the right side? (what are we setting)
* 
* ----------------------------------------------------------------------------------------------------------
*
* To run this, just use the attached main. This is not a library, so no annoying commands!
* Just use gcc dpProblems.c -std=c99 -o dp -Wall -Werror --pedantic , and then ./dp
*
*/
/*******************************************************  * The Problems:  *******************************************************/
/*
* Find the FIRST instance of a string that has a length >= len.  
* I.E. in the array ["A", "B", CD", EFG", "DE", "DEF"]  * findFirstGreaterLen(1, ..., ...) would return a struct containing "A" and 0.  
* findFirstGreaterLen(3, ..., ...) would return a struct containing "EFG" and 3.  
* findFirstGreaterLen(5, ..., ...) would return NULL (note, NULL, not a struct)  
* findFirstGreaterLen(5, NULL, NULL) would return NULL (note, NULL, not a struct)  
* The struct should contain the index of the occurance and the string at that occurance  *  
* HINT the list is NOT null ('\0') terminated. Think about how we know when we reach the end of the list  
*  
*/ 
String_Info findFirstGreaterLen(int len, char** head, char** tail){
	
	if(head == NULL || tail == NULL || *head == NULL || *tail == NULL){
		return NULL;
	}
	int i = 0;
	if(head && tail){
		if(*head && *tail){
			for(; *head != *tail; head++, i++){
				if(*head == NULL){
					i++;
					head++;
				}
				if(strlen(*head) >= len){
					String_Info si = (String_Info)malloc(sizeof(struct string_info));
					si -> str = *head;
					si -> index = i;
					return si;
				}
			}
		}
	}
	return NULL;
}
/*  
* Find the FIRST instance of a given character in the list  
* Return the index of the string the character is in  
* Return -1 if character is not in any string, or if given null input  
*/ 
int indexOf(char c, char** head, char** tail){
/*implement Me!*/
	int i = 0;
	int d = 0;
	if(head && tail){
		for(; *head != *tail; head++, d++){
			if(*head != NULL){
				for(i = 0; i < strlen(*head); i++){
					if((*head)[i] == c){
						return d;
					}
				}
			}
		}
	}
	return -1;
}
int main(){
	char** head = (char**)malloc(sizeof(char*)*6); 
	char** tail = head + 5; 
	int i = 0; 
	char c; 
	int e = 0; 
	head[0] = "h"; 
	head[1] = "a"; 
	head[2] = "ab"; 
	head[3] = "abcdef"; 
	head[4] = "abd"; 
	head[5] = "cd";
	i =2; 
	String_Info si = findFirstGreaterLen(i, head, tail); 
	printf("For length %i, found at index %i [should be 2] with string %s [should be \"ab\"]\n",  i, si==NULL? -1 : si->index, si == NULL? "NULL" : si->str);
	i =3; 
	si = findFirstGreaterLen(i, head, tail); 
	printf("For length %i, found at index %i [should be 3] with string %s [should be \"abcdef\"]\n",  i, si==NULL? -1 : si->index, si == NULL? "NULL" : si->str);
	i =30;
	si = findFirstGreaterLen(i, head, tail); 
	printf("For length %i, found at index %i [should be -1] with string %s [should be \"NULL\"]\n", i, si==NULL? -1 : si->index, si == NULL? "NULL" : si->str);
	head[3] = NULL; 
	i =3; 
	si = findFirstGreaterLen(i, head, tail); 
	printf("For length %i, found at index %i [should be 4] with string %s [should be \"abd\"]\n",  i, si==NULL? -1 : si->index, si == NULL? "NULL" : si->str);
	head[0] = NULL; 
	i =1; 
	si = findFirstGreaterLen(i, head, tail); 
	printf("For length %i, found at index %i [should be 1] with string %s [should be \"a\"]\n",  i, si==NULL? -1 : si->index, si == NULL? "NULL" : si->str);
	i =30; 
	si = findFirstGreaterLen(i, NULL, tail); 
	printf("For length %i, found at index %i [should be -1] with string %s [should be \"NULL\"]\n", i, si==NULL? -1 : si->index, si == NULL? "NULL" : si->str);
	i =30; 
	si = findFirstGreaterLen(i, head, NULL); 
	printf("For length %i, found at index %i [should be -1] with string %s [should be \"NULL\"]\n", i, si==NULL? -1 : si->index, si == NULL? "NULL" : si->str);
	head[3] = "abcdef";
	c = 'h'; 
	e=-1; 
	i= indexOf( c, head, tail); 
	printf("For char %c, found in string %i [should be %i]\n", c, i, e);
	c = 'a'; 
	e=1; 
	i= indexOf( c, head, tail); printf("For char %c, found in string %i [should be %i]\n", c, i, e);
	c = 'f'; 
	e=3; 
	i= indexOf( c, head, tail); printf("For char %c, found in string %i [should be %i]\n", c, i, e);
	c = 'f'; 
	e=-1; 
	i= indexOf( c, NULL, tail); printf("For char %c, found in string %i [should be %i]\n", c, i, e);
	c = 'f'; 
	e=-1; 
	i= indexOf( c, head, NULL); printf("For char %c, found in string %i [should be %i]\n", c, i, e);
	return 0;
}

