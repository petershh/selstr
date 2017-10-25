all: selstr

get_str.o: get_str.c ./headers/get_str.h
	gcc -c get_str.c -o ./obj/get_str.o

main.o: main.c ./headers/get_str.h
	gcc -c main.c -Iheaders -o ./obj/main.o

selstr: main.o get_str.o
	gcc ./obj/main.o ./obj/get_str.o -o ./bin/selstr
