
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;
int main () {
	int pid;
	pid = fork(); //pid value different for parent (any) and child (0) process 
		if (pid < 0)
		{
			cout<<"Error while creating proccess, program will be terminated \n" << endl;
			exit(1);
		} else if (pid>0)
		{
			int status;
			waitpid(pid, &status, 0); //wait for child process to change state
		} else{
			execl("teams", "", NULL); //need at least three arguments, otherwise won't work
		}
	exit(0);
}