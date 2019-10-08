#include "ft_printf.h"

void	print_c(t_fs *fs, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	print_non_specifier(fs, c);
}