#include "main.h"
void hello(void)
{
	printf("ha iwont die\n");
	return;
}

int main(int ac, char *av, char *env[])
{
	//simple_shell
	int i = 0, len;
	size_t n = 1;
	char *line;
	char **tok;
	char *full;

	while (1)
	{
		write(1, "$ ", 2);
		len = getline(&line, &n, stdin);
		line[len] = '\0';

		if (line[len - 1] == EOF)
			exit(0);
		tok = malloc(sizeof(char) * len + 1);
		tok[0] = _strtok(line, " ");
		while (tok[i] != NULL)
		{
			i++;
			tok[i] = _strtok(NULL, " ");
		}
		if (builtins(tok[0], tok) == 0)
		{
			free(line);
			free(tok);
			continue;
		}
		full = _ispath(env, tok[0]);
		if (full != NULL)
		{
			_exec(full, tok);
			free(line);
			free(tok);
			free(full);
			continue;
		}
		perror("command not found\n");
		free(line);
		free(tok);
		free(full);
		continue;
	}
}
