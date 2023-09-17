#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    char buf[1025];
    char *buf2=NULL;
    size_t i = 1024;
    int fd;
    if (ac == 1)
    {
        printf("u are in interact mode\n");
       
        while (1)
        {
            getline(&buf2, &i, stdin);
            printf("%s\n", buf2);
            free(buf2);
        }
    }
    else
    {
        printf("non enter act mode\n");
        fd = open(av[1], O_RDONLY);
        while ((i = read(fd, buf, 1024)) > 0)
            write(STDOUT_FILENO, buf, i);
    }
    close(fd);
    return (0);
}
