#include "libft.h"

int		ft_isalpha(int c)
{
	return ((c >= 'a' && 'z' >= c) || (c >= 'A' && 'Z' >= c));
}