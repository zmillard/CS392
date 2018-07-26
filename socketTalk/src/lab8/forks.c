pid_t pid;
if((pid = fork()) < 0){
//error, inspect errorno
} else if (pid==0){
//child creates a new child
} else {
//shows ur in the parent
cout << "childs pid is "<< pid
}

//wait then return 0
//send signal with kill ---- kill -9 sends signal to kill
//sends it to another process (pid)
int kill (pid_t pid, int sig); //sig is the flag ur raising give it process id then 
kill (pid, SIGINT);
raise; //raise signal in your own code, can raise seg fault signal
//ctrl-c to kill own process

sighandler_t signal(int signum,sighandler_t handler);
write method in program and put name in handler spot

#include <signal.h>
void hello(int sig){
	mystr("some shit");
}
int main(){
	singal(SIGINT, hello);
	while(1);
	return 1;
}
int pause; //just like sleep but it can listen to signals while its pausing
//if you want to infinitely look for signals you can put pause in an infinite while loop
//pause will never move until it gets ANYYYY singal. once a signal happens it will stop

unsigned int alarm(unsigned int seconds ); //give it the number of seconds and after that number of seconds it will sounds alarm

int main(){
	signal(SIGINT, exitthis); //user pressed control c
	signal(SIGNALALARM, hello);
	alarm(10);
	pause(); //will run exitthis
	return o;
}