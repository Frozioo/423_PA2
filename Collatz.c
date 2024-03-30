// Trey Larson

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    
    // error checking
    if (argc != 2) {
    
        printf("Usage: %s <starting value>\n", argv[0]);
        return 1;
    }
    
    int start = atoi(argv[1]);
    
    if (start <= 0) {
    
        printf("<starting value> should be a positive integer\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
    
        Collatz(start);
        exit(0);
        
    } else {
    
        // invoke wait call
        wait(NULL);
    }

    return 0;
}

void Collatz(int n) {

    while (n != 1) {
    
    	// separated with commas just like in the example
        printf("%d, ", n);
        
        // if n is even
        if (n % 2 == 0) {
        // n/2
            n = n / 2;
        // if n is odd
        }
        
        else {
        // 3*n+1
            n = 3 * n + 1;
        }
    }
    // should always end with 1
    printf("1\n");
}
