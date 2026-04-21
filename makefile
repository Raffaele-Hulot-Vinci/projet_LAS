CFLAGS= -pedantic -Wvla -Werror -Wall -std=c17 -D_DEFAULT_SOURCE

all : controller zombie labo

controller : controller.o utils.o
	cc $(CFLAGS) -o controller out/controller.o out/utils.o

controller.o : src/controller.c headers/utils.h headers/shared.h
	cc $(CFLAGS) -c src/controller.c -o out/controller.o

zombie : zombie.o utils.o
	cc $(CFLAGS) -o zombie out/zombie.o out/utils.o

zombie.o : src/zombie.c headers/utils.h headers/shared.h
	cc $(CFLAGS) -c src/zombie.c -o out/zombie.o

labo : labo.o utils.o
	cc $(CFLAGS) -o labo out/labo.o out/utils.o

labo.o : src/labo.c headers/utils.h headers/shared.h
	cc $(CFLAGS) -c src/labo.c -o out/labo.o

utils.o : src/utils.c headers/utils.h
	cc $(CFLAGS) -c src/utils.c -o out/utils.o

clean :
	rm out/*
	rm zombie
	rm controllerµ
	rm labo