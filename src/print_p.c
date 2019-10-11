/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:06:38 by aihya             #+#    #+#             */
/*   Updated: 2019/10/11 22:47:45 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_p_on_left(t_fs *fs, char *s, int size)
{
	int		ret;

	ret = 0;
	ft_putstr("0x");
	if (fs->precision > fs->width)
	{
		ret = repeate_char(48, fs->precision - size);
		ft_putstr(s);
	}
	else if (fs->precision >= size)
	{
		ret = repeate_char(48, fs->precision - size);
		ft_putstr(s);
		ret += repeate_char(32, fs->width - fs->precision - 2);
	}
	else
	{
		ft_putstr(s);
		ret = repeate_char(32, fs->width - size - 2);
	}
	ret += size + 2;
	return (ret);
}

int		print_p_on_right(t_fs *fs, char *s, int size)
{
	int		ret;

	ret = 0;
	if (fs->precision > fs->width)
	{
		ft_putstr("0x");
		ret = repeate_char(48, fs->precision - size) + size + 2;
		ft_putstr(s);
	}
	else if (fs->precision >= size)
	{
		ret = repeate_char(32, fs->width - fs->precision - 2);
		ft_putstr("0x");
		ret += repeate_char(48, fs->precision - size) + size + 2;
		ft_putstr(s);
	}
	else if (fs->flags & F_ZERO)
	{
		ft_putstr("0x");
		ret = repeate_char(48, fs->width - size - 2) + size + 2;
		ft_putstr(s);
	}
	else
	{
		ret = repeate_char(32, fs->width - size - 2) + size + 2;
		prefix(s, "0x");
	}
	return (ret);
}

int		print_p(t_fs *fs, va_list ap)
{
	void	*addr;
	char	*s;
	int		size;
	int		ret;

	ret = 0;
	addr = va_arg(ap, void *);
	s = ft_itoa_base((long long)addr, 16, 0);
	size = (int)ft_strlen(s);
	if (fs->flags & F_DASH)
		ret = print_p_on_left(fs, s, size);
	else
		ret = print_p_on_right(fs, s, size);
	return (ret);
}
