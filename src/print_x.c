/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:41:54 by aihya             #+#    #+#             */
/*   Updated: 2019/10/22 18:56:52 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_x_on_right(t_fs *fs, char *s, int size, int val)
{
	int		ret;

	ret = 0;
	if (fs->precision != DEFAULT)
	{
		if (fs->precision >= fs->width)
		{
			ret += set_x_right_prefix(val, fs, fs->precision, 0);
			ret += repeate_char(48, fs->precision - size);
		}
		else if (fs->precision >= size)
		{
			ret += set_x_right_prefix(val, fs, fs->precision, 0);
			ret += repeate_char(48, fs->precision - size);
		}
		else
			ret += set_x_right_prefix(val, fs, size, 0);
	}
	else
		ret += set_x_right_prefix(val, fs, size, DEFAULT);
	ft_putstr(s);
	return (ret + size);
}

static int	print_x_on_left(t_fs *fs, char *s, int size, int val)
{
	int		ret;
	int		htag_cond;

	ret = 0;
	htag_cond = val != 0 && (fs->flags & F_HTAG);
	if (fs->precision != DEFAULT)
	{
		if (fs->precision >= fs->width)
			ret += put_x(htag_cond, fs->precision - size, 1, s);
		else if (fs->precision >= size)
		{
			ret += put_x(htag_cond, fs->precision - size, 1, s);
			ret += put_trailing_spaces(fs, htag_cond, fs->precision);
		}
		else
		{
			ret += put_x(htag_cond, fs->precision - size, 0, s);
			ret += put_trailing_spaces(fs, fs->flags & F_HTAG, size);
		}
		return (ret + size);
	}
	ret += put_x(htag_cond, fs->precision - size, 0, s);
	ret += put_trailing_spaces(fs, htag_cond, size);
	return (ret + size);
}

static char	*get_s(unsigned long long int val, t_fs *fs)
{
	char	*s;
	char	*tmp;

	if (val == 0 && fs->precision == 0)
			return (ft_strdup(""));
	return (ft_itoa_base_u(val, 16, fs->specifier == 'x' ? 0 : 1));
}

int			print_x(t_fs *fs, va_list ap)
{
	unsigned long long int	val;
	char					*s;
	int						size;
	int						ret;

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
	ret = 0;
	if (fs->flags & F_DASH)
		ret = print_x_on_left(fs, s, size, val);
	else
		ret = print_x_on_right(fs, s, size, val);
	free(s);
	return (ret);
}
