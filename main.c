#include "shell.h"
int status = 0;
int main(int ac, char *av[])
{

	char *line = NULL;
	char **token = NULL;
	int i = 0, len, stat, counter = 0;
	size_t size = 0;
	do
	{
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "@zerobors$ ", 11);
		ac = counter++;
		len = getline(&line, &size, stdin);
		if (len == -1)
		{
			free(line);
			exit(0);
		}

		line[len - 1] = '\0';
		token = malloc(sizeof(char *) * len);
		if (token == NULL)
		{
			perror("cant allocate memory\n");
			continue;
		}
		i = 0;
		token[0] = strtok(line, " ");
		while (token[i] != NULL)
		{
			i++;
			token[i] = strtok(NULL, " ");
		}
		stat = builtins(token[0], token);
		if (stat == 0 || stat < 0)
		{
			free(token);
			continue;
		}
		else if (stat == 69)
		{
			free(line);
			exit(status);
		}

		stat = path_finder(token[0], token);
		if (stat == 0 || stat < 0)
		{
			free(token);
			continue;
		}
		stat = accessable(token[0], token);
		if (stat == 0 || stat < 0)
		{
			free(token);
			continue;
		}
		_peror(": not found\n", av[0], token[0], counter);
		free(token);
	} while (isatty(STDIN_FILENO) || len != EOF);
	free(line);

	return (ac = status);
}
