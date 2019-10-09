/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:06:38 by aihya             #+#    #+#             */
/*   Updated: 2019/10/09 00:26:12 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p_on_left(t_fs *fs, char *s, int size)
{
	ft_putstr("0x");
	if (fs->precision > fs->width)
	{
		repeate_char(48, fs->precision - size);
		ft_putstr(s);
	}
	else if (fs->precision >= size)
	{
		repeate_char(48, fs->precision - size);
		ft_putstr(s);
		repeate_char(32, fs->width - fs->precision - 2);
	}
	else
	{
		ft_putstr(s);
		repeate_char(32, fs->width - size - 2);
	}
}

void	print_p_on_right(t_fs *fs, char *s, int size)
{
	if (fs->precision > fs->width)
	{
		ft_putstr("0x");
		repeate_char(48, fs->precision - size);
		ft_putstr(s);
	}
	else if (fs->precision >= size)
	{
		repeate_char(32, fs->width - fs->precision - 2);
		ft_putstr("0x");
		repeate_char(48, fs->precision - size);
		ft_putstr(s);
	}
	else if (fs->flags & F_ZERO)
	{
		ft_putstr("0x");
		repeate_char(48, fs->width - size - 2);
		ft_putstr(s);
	}
	else
	{
		repeate_char(32, fs->width - size - 2);
		prefix(s, "0x");
	}
}

void	print_p(t_fs *fs, va_list ap)
{
	void	*addr;
	char	*s;
	int		size;

	addr = va_arg(ap, void *);
	s = ft_itoa_base((long long)addr, 16, 0);
	size = (int)ft_strlen(s);
	if (fs->flags & F_DASH)
		print_p_on_left(fs, s, size);
	else
		print_p_on_right(fs, s, size);
}
