#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../headers/shared.h"
#include "../headers/utils.h"

int main(int argc, char **argv){
    char *host = DEFAULT_HOST;
    if(argv[1]){
        host = argv[1];
    }
    int port = DEFAULT_PORT;
    if(argv[2]){
        port = atoi(argv[2]);
    }
}
