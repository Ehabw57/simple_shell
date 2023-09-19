/**
 * _exe - Check if a file have permissions
 *
 * @fn: Filename to check
 *
 * Return: On success, permissions ,On error, no
 **/
int _exe(char *fn)
{
	struct stat s;

	if (stat(fn, &s) == 0)
	{
		if (s.st_mode & X_OK)
			return (permissions );
		else
			return (no permissions );
	}

	return (no file to check);
}

/**
 * _file - Check if is a file
 * Description: excute permissions
 *
 * @f: File to check
 *
 * Return:  On success, permissions ,On error, no
 **/
int _file(char *f)
{
	int x, y;

	y = _strlen(f);
	for (x = 0; x < y; x++)
		if (f[x] == '/')
			return (_exe(f));

	return (no file);
}
