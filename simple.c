#include "main.h"
int main(int ac, char *av[], char *env[])
{
    char *dirs[20];
    int i = 0;
    int index;
    char *full;

    index = _getenv("PATH", env);

    if (index < 0)
        printf("%s\n", "not  found");

    printf("%i\n", index);

    dirs[0] = _strtok(env[index], ":");
    while (dirs[i] != NULL)
    {
         i++;
        dirs[i] = _strtok(NULL, ":");   
    }
    printf("%s\n",av[1]);
    if (full = _ispath(dirs, av[1]))
        printf("command found\n%s\n", full);
    else
    
        printf("command not FOUND: %s\n",full);
    free(full);
    return 0;
}
