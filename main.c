#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_str.h"

int main(int argc, char** argv){
	char *pattern, *str;
	if(argc < 2 || argc > 3 ||  (!strcmp("--help", argv[1])|| !strcmp("-h", argv[1]))){
		show_help();
	}else if(argc == 3 && strcmp(argv[1], "-i") && strcmp(argv[1], "--ignorecase")){
		printf("%s is not a valid argument. Exiting!\n", argv[1]);
		return 1;
	}else{
        pattern = argv[argc-1];
        if(argc == 3)
            to_lower_case(&pattern);
	str = NULL;
	while(get_str(&str)){
            if(argc == 3)
                to_lower_case(&str);
			if(strstr(str, argv[argc-1])){
				printf("%s\n", str);
			}
		}
		free(str);
	}
	return 0;	if(argc < 2 || argc > 3 ||  (!strcmp("--help", argv[1])|| !strcmp("-h", argv[1]))){
		printf("usage: <command> | selstr [-i/--ignorecase] <string>\n\n");
		printf("-i/--ignorecase\t\tfilter text ignoring case\n");
		printf("<string>\t\tstring to filter input with\n");
	}else if(argc == 3 && strcmp(argv[1], "-i") && strcmp(argv[1], "--ignorecase")){
		printf("%s is not a valid argument. Exiting!\n", argv[1]);
		return 1;
	}else{
		char* str = NULL;
		while(get_str(&str)){
			if(strstr(str, argv[argc-1])){
				printf("%s\n", str);
			}
		}
		free(str);
	}
	return 0;
}
