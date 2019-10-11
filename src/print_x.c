/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:41:54 by aihya             #+#    #+#             */
/*   Updated: 2019/10/10 22:38:45 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_x_on_right(t_fs *fs, char *s, int size)
{
	if (fs->precision != DEFAULT)
	{
		if (fs->precision >= fs->width)
		{
			repeate_char(48, fs->precision - size);
			ft_putstr(s);
		}
		else if (fs->precision >= size)
		{
			repeate_char(32, fs->width - fs->precision);
			repeate_char(48, fs->precision - size);
			ft_putstr(s);
		}
		else
		{
			repeate_char(32, fs->width - size);
			ft_putstr(s);
		}
	}
	else
	{
		repeate_char(fs->flags & F_ZERO ? 48 : 32, fs->width - size);
		ft_putstr(s);
	}
}

void	print_x_on_left(t_fs *fs, char *s, int size)
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

static char	*get_s(unsigned long long int val, t_fs *fs)
{
	char	*s;
	char	*tmp;

	if (val == 0)
	{
		if (fs->precision == 0 || (fs->flags & F_HTAG))
			s = ft_strdup("");
		else
			s = ft_strdup("0");
	}
	else
		s = ft_itoa_base_u(val, 16, 0);
	if (fs->flags & F_HTAG)
	{
		tmp = ft_strjoin("0x", s);
		free(s);
		s = ft_strdup(tmp);
		free(tmp);
	}
	return (s);
}

void	print_x(t_fs *fs, va_list ap)
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
	s = get_s(val, fs);
	size = (int)ft_strlen(s);
	if (fs->flags & F_DASH)
		print_x_on_left(fs, s, size);
	else
		print_x_on_right(fs, s, size);
	free(s);
}

