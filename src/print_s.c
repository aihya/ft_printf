/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:06:59 by aihya             #+#    #+#             */
/*   Updated: 2019/10/09 19:47:50 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s_on_left(t_fs *fs, char *s, int size)
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

void	print_s_on_right(t_fs *fs, char *s, int size, char sym)
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
	int		null;
	char	*s;
	int		size;

	null = 0;
	s = va_arg(ap, char *);
	if (s != NULL)
		size = (int)ft_strlen(s);
	else
	{
		null = 1;
		s = ft_strdup("(null)");
		size = 6;
	}
	if (fs->flags & F_DASH)
		print_s_on_left(fs, s, size);
	else if (fs->flags & F_ZERO)
		print_s_on_right(fs, s, size, 48);
	else
		print_s_on_right(fs, s, size, 32);
	if (null)
		free(s);
}
