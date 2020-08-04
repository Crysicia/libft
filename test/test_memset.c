#include <stdio.h>
int main(void)
{
	char *data = malloc(15);
	char str[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r', 't', 'o', 'u', 't', 'l', 'e', 'm', 'o', '\0'};

	int i = 0;
	while (i < 15)
	{
		data[i] = str[i];
		i++;
	}
	printf("OG: %s\n", data);
	ft_memset(data, 125, -2);
	printf("NEW: %s\n", data);
	return (0);
}