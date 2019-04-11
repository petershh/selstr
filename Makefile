.PHONY: all install

all: selstr

get_str.o: get_str.c
	gcc -c get_str.c -Iheaders -o get_str.o

main.o: main.c get_str.c
	gcc -c main.c -Iheaders -o main.o

selstr: main.o get_str.o
	gcc main.o get_str.o -o selstr

install:
	install selstr /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/selstr
