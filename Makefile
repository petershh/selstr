.PHONY: all install

all: selstr

get_str.o: get_str.c
	gcc -c get_str.c -o ./obj/get_str.o

main.o: main.c get_str.c
	gcc -c main.c -Iheaders -o ./obj/main.o

selstr: main.o get_str.o
	gcc ./obj/main.o ./obj/get_str.o -o ./bin/selstr

install:
	install ./bin/selstr /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/selstr
