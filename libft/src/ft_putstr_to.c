#include "libft.h"
#include <unistd.h>

void	ft_putstr_to(const char *str, int size)
{
	if (size < 0 || size > (int)ft_strlen(str))
		ft_putstr(str);
	else
		write(1, str, size);
}