#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
 
using namespace std;

void sigint(int a) {
    cout<<"CTRL+C\n";
}

void sigtstp(int a) {
    cout<<"CTRL+Z\n";
}
 
int main()
{
    signal(SIGINT, sigint);
    signal(SIGTSTP, sigtstp);
 
     struct termios oldt, newt;
     int ch;
     tcgetattr( STDIN_FILENO, &oldt );
     newt = oldt;
     newt.c_lflag &= ~( ICANON | ECHO );
     tcsetattr( STDIN_FILENO, TCSANOW, &newt );
     do {
		 ch=getchar();
		 cout<<ch<<'\n';
	} while(ch!='q');
     tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
 
}