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
