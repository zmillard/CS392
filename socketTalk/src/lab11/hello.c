#include <ncurses.h>
#include <string.h>
int main(){
 	int ch;
 	int test = 0;
	int place = 0;
	char str[80];
 	initscr();
 	raw();

	do{
		ch = getch();
		while(ch != 23){
			str[place] = ch;
			place++;
			ch = getch();
		}

        	if(ch == 23){
			endwin();
			test = 1;
			return 0;
		}
		getstr(str);
		start_color();
		init_pair(1, COLOR_RED, 0);
		attron(COLOR_PAIR(1));
		printw(str);
		attroff(COLOR_PAIR(1));

 	}while(test == 0);

 	return 0;
}
