#include "libft.h"

int		ft_isspace(int c)
{
	return ((c >= 9 && 13 >= c) || c == 32);
}
