#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "../headers/shared.h"
#include "../headers/utils.h"

int main(int argc, char **argv){
    printf("launching lab\n");

    char port[5];
    sprintf(port, "%d", DEFAULT_PORT);
    if(argv[1]){
        strcpy(port, argv[1]);
    }

    int zombie = sfork();
    if(zombie == 0){
        execl("./zombie", "zombie", argv[1], NULL);
        perror("exec fail");
        exit(1);
    }

    int controller = sfork();
    if(controller == 0){
        execl("./controller", "controller", DEFAULT_HOST, argv[1], NULL);
        perror("exec fail");
        exit(1);
    }
    swait(NULL);
    swait(NULL);
}
