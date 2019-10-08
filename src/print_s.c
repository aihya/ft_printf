#include "ft_printf.h"

void	print_s_on_dash(t_fs *fs, char *s, int size)
{
	if (fs->precision == -1 || fs->precision >= size)
	{
		ft_putstr_to(s, size);
		repeate_char(' ', fs->width - size);
	}
	else if (fs->precision < size)
	{
		ft_putstr_to(s, fs->precision);
		repeate_char(' ', fs->width - fs->precision);
	}
}

void	print_s_on_zero(t_fs *fs, char *s, int size, char sym)
{
	if (fs->precision == -1 || fs->precision >= size)
	{
		repeate_char(sym, fs->width - size);
		ft_putstr_to(s, size);
	}
	else if (fs->precision < size)
	{
		repeate_char(sym, fs->width - fs->precision);
		ft_putstr_to(s, fs->precision);
	}
}

void	print_s(t_fs *fs, va_list ap)
{
	char	*s;
	int		size;

	s = va_arg(ap, char *);
	size = (int)ft_strlen(s);
	if (fs->width > size)
	{
		if (fs->flags & F_DASH)
			print_s_on_dash(fs, s, size);
		else if (fs->flags & F_ZERO)
			print_s_on_zero(fs, s, size, 48);
		else
			print_s_on_zero(fs, s, size, 32);
	}
	else
	{
		
	}
}