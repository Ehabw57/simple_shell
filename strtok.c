#include "main.h"
/**
 * _strtok - toknize a given string based on the deil
 * @source: the string to be toknized
 * @deil: the delimeters
 * Return: the first token of the string or the next token
 * if source is NULL
*/
char *_strtok(char *source, char *deil)
{
	return (strtok(source, deil));
}
