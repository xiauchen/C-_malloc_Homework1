/*
 * parse.c : use whitespace to tokenise a line
 * Initialise a vector big enough
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/* Parse a commandline string into an argv array. */
char ** parse(char *line) {

  	static char delim[] = " \t\n"; /* SPACE or TAB or NL */
  	int count = 0,con=0;
  	char * token;
  	

  	/* Nothing entered. */
  	if (line == NULL) {
    	return NULL;
  	}
	for(int i=0;i<sizeof(line);i++){
		if(line[i]==delim[0] || line[i]==delim[1] || line[i]==delim[2]){
			con++;
		}
	}
  	char **newArgv=(char**)malloc(sizeof(char*)*con);
	printf("size = %d\n",sizeof(&newArgv));
	token=strtok(line,delim);
	if(token==NULL) 
		return NULL;
	newArgv[count]=(char*)malloc(sizeof(token));
	newArgv[count]=token;
	count++;
	while(token=strtok(NULL,delim)){
		newArgv[count]=(char*)malloc(sizeof(token));
		newArgv[count]=token;
		count++;
	}
	printf("size = %d\n",sizeof(newArgv));
  	return newArgv;
}


/*
 * Free memory associated with argv array passed in.
 * Argv array is assumed created with parse() above.
 */
void free_argv(char **oldArgv) {

	int i = 0;

	/* Free each string hanging off the array.
	 * Free the oldArgv array itself.
	 *
	 * Fill in code.
	 */
	while(i<sizeof(oldArgv)){
		free(oldArgv[i]);
		i++;
	}
	free(oldArgv);
}
