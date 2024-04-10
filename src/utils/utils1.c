/*funcion que busca un caracter en un string y retorna 1 si lo encuentra*/
int	ca_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (0);
	return (0);
}
