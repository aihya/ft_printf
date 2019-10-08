#include "ft_printf.h"

void	print_non_specifier(t_fs *fs, int c)
{
	if (fs->width > 1)
	{
		if (fs->flags & F_DASH)
		{
			ft_putchar(c);
			repeate_char(' ', fs->width - 1);
		}
		else if (fs->flags & F_ZERO)
		{
			repeate_char('0', fs->width - 1);
			ft_putchar(c);
		}
		else if ((fs->flags & F_ZERO) == 0)
		{
			repeate_char(' ', fs->width - 1);
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
}