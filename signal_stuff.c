#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h> 
#include <unistd.h>
#include <fcntl.h>

static void signal_handler(int signo){
  if (signo == SIGINT){
    printf("Terminating because recieved a SIGINT\n");
    exit(0);
  }
  if (signo == SIGUSR1){
    printf("This is the ppid: %d", getppid());
  }
}

int main(){
    while(1){
        signal(SIGINT, signal_handler);
        signal(SIGUSR1, signal_handler);
        printf("The id is %d\n", getpid());
        sleep(1);
    }

    return 0;
}
