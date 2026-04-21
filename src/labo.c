#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../headers/shared.h"
#include "../headers/utils.h"

int main(int argc, char **argv){
    printf("launching lab\n");

    int port = DEFAULT_PORT;
    if(argv[1]){
        port = argv[1];
    }

    int zombie = sfork();
    if(zombie == 0){
        execl("./zombie", "zombie", port, NULL);
        printf("exec fail");
        exit(1);
    }

    int controller = sfork();
    if(controller == 0){
        execl("./controller", "controller", port, NULL);
        printf("exec fail");
        exit(1);
    }
}
