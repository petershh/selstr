#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int get_str(char** buf){
	char symbol;
	if(!*buf) free(*buf);
	*buf = malloc(sizeof(char));
	int i = 0;
	while(scanf("%c", &symbol)==1 && symbol != '\n'){
		i++;
		*buf = realloc(*buf, i*sizeof(char));
		(*buf)[i-1] = symbol;
	}
	*buf = realloc(*buf, (i+1)*sizeof(char));
	(*buf)[i] = '\0';
	return i;
}

void show_help(){
    puts("selstr - text filtering");
    puts("usage: <command> | selstr [-i/--ignorecase] <string>\n\n");
    puts("-i/--ignorecase\t\tfilter text ignoring case\n");
    puts("<string>\t\tstring to filter input with\n");
}

void to_lower_case(char** str){
    for(int i = 0; (*str)[i] != '\0'; i++){
        if((*str)[i] >= 'A' && (*str)[i] <= 'Z')
            (*str)[i] += ('a' - 'A');
    }
}
