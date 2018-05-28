/*************** header ***************/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*************** define ***************/

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define LSH_RL_BUFSIZE 1024

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t \r \n \a"


/*************** function ***************/

void lsh_loop(void);
char *lsh_read_line(void);
char **lsh_split_line(char *line);

/*************** main ***************/

int main (void){
	
	lsh_loop();
	
	return EXIT_SUCCESS;
}

/*************** function ***************/

void lsh_loop(void){
	
	char *line;
	char **args;
	int status;
	
	do{
		printf("> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);
		
		free(line);
		free(args);
	} while (status);
	
}

char *lsh_read_line(void) {
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;
	
	if (!buffer) {
		printf("메모리 할당 오류 \n");
		exit(EXIT_FAILURE);
	}
	
	while(1) {
		c = getchar();
		
		if(c=='\n' || c == EOF) {
			buffer[position] = '\0';
			return buffer;
		}
		else {
			buffer[position] = c;
		}
		position++;
		
		if (position >= bufsize) {
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer) {
				fprintf(stderr, "메모리 할당 오류 \n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

char **lsh_split_line(char *line) {
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;
		
	if(!tokens) {
		printf("토큰 메모리 할당 오류\n");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL) {
		tokens[position] = token;
		position ++;
		
		if (position >= bufsize) {
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens,bufsize * sizeof(char*));
			if(!tokens) {
				printf("토큰 메모리 할당 오류\n");
				exit(EXIT_FAILURE);
			}
		}
	
	
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
		
