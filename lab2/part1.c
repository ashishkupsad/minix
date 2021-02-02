#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>

void print_char(char str[], int i, int length){
    
    if(i <= length){
        int pid = fork();
        if(pid > 0){ // returned to parent/caller
            printf("%c %d\n", str[i], pid);
            sleep(rand()%4 + 1);
            print_char(str, i+1, length);
        }
    }
    return;  
}

int main() 
{ 
    char str[] = "Hello World";
    setbuf(stdout, NULL);
    print_char(str, 0, 10);
    return 0;   
}