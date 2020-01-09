#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64

#define LSH_TOK_DELM "\t\r\n\a"

//hello world
//hi modified
int main(int argc, char** argc) {
	lsh_loop();
	return EXIT_SUCCESS;
}

void lsh_loop() {
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
	}while(status);
}

char *lsh_read_line(void) {
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * buffersize);
	int c;

	if (!buffer) {
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while(1) {
		c = getchar();
		if(c == EOF || c == '\n') {
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
			if(!buffer) {
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/*
 char *lsh_read_line(void) {
 	char *line = NULL;
	ssize_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	return line;
 }
 */

char **lsh_split_line(char *line) {
	int bufsize = LSH_TOK_BUFSIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if(!token) {
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while(token != NULL) {
		tokens[position] = token;
		position++;

		if(position >= bufsize) {
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if(!tokens) {
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strok(NULL, LSH_TOK_DELIM);
	}

	tokens[position] = NULL;

	return tokens;
}
