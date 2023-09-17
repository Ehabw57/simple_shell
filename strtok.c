#include "main.h"
#include <stdlib.h>
char *_strtok(char *source,char *deil)
{
static char *token;
int i =0,int j=0;

if(source == NULL)
{
	while(*token != '\0')
		token++;
	return(token++);
}

while(source[i] != '\0')
{
	j = 0;
	while(deil[j] != '\0')
	{
		if(deil[j] == source[i])
		{
			source[i] = '\0';
break:
		}
		j++;
	}
	i++;
}
token = source;
return(token);
}

