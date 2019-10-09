/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:59:11 by aihya             #+#    #+#             */
/*   Updated: 2019/10/09 22:59:07 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prefix(char *str, char *prefix)
{
	ft_putstr(prefix);
	ft_putstr(str);
}

void	print_o_on_right(t_fs *fs, char *s, int size)
{
	
}

void	print_o_on_left(t_fs *fs, char *s, int size)
{
	repeate_char(48, fs->precision - size);
	if (fs->precision >= fs->width)
		ft_putstr(s);
	else if (fs->precision > size)
	{
		ft_putstr(s);
		repeate_char(32, fs->width - fs->precision);
	}
	else
	{
		ft_putstr(s);
		repeate_char(32, fs->width - size);
	}
}

void	print_o(t_fs *fs, va_list ap)
{
	unsigned long long int	val;
	char					*s;
	char					*tmp;
	int						size;

	if (fs->length == L_hh)
		val = (unsigned char)va_arg(ap, int);
	else if (fs->length == L_h)
		val = (unsigned short int)va_arg(ap, int);
	else if (fs->length == L_l)
		val = (unsigned long int)va_arg(ap, long int);
	else if (fs->length == L_ll)
		val = (unsigned long long int)va_arg(ap, long long int);
	else
		val = (unsigned int)va_arg(ap, int);

	s = ft_itoa_base_u(val, 8, 0);
	size = (int)ft_strlen(s);
	if (fs->flags & F_HTAG)
	{
		tmp = ft_strjoin("0", s);
		free(s);
		ft_strdup(tmp);
		free(tmp);
		size += 1;
	}
	if (fs->flags & F_DASH)
		print_o_on_left(fs, s, size);
	if (fs->flags & F_ZERO)
		print_o_on_right(fs, s, size, 48);
	else
		print_o_on_right(fs, s, size, 32);
}
