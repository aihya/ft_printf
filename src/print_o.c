/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:59:11 by aihya             #+#    #+#             */
/*   Updated: 2019/10/13 13:19:37 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	prefix(char *str, char *prefix)
{
	ft_putstr(prefix);
	ft_putstr(str);
}

int		print_o_on_right(t_fs *fs, char *s, int size)
{
	int		ret;

	ret = 0;
	if (fs->precision != DEFAULT)
	{
		if (fs->precision >= fs->width)
		{
			ret += repeate_char(48, fs->precision - size);
			ft_putstr(s);
		}
		else if (fs->precision >= size)
		{
			ret += repeate_char(32, fs->width - fs->precision);
			ret += repeate_char(48, fs->precision - size);
			ft_putstr(s);
		}
		else
		{
			ret += repeate_char(32, fs->width - size);
			ft_putstr(s);
		}
	}
	else
	{		
		ret += repeate_char(fs->flags & F_ZERO ? 48 : 32, fs->width - size);
		ft_putstr(s);
	}
	return (ret + size);
}

int		print_o_on_left(t_fs *fs, char *s, int size)
{
	int		ret;

	ret = repeate_char(48, fs->precision - size);
	if (fs->precision >= fs->width)
		ft_putstr(s);
	else if (fs->precision > size)
	{
		ft_putstr(s);
		ret += repeate_char(32, fs->width - fs->precision);
	}
	else
	{
		ft_putstr(s);
		ret += repeate_char(32, fs->width - size);
	}
	return (ret + size);
}

char	*get_s(unsigned long long int val, t_fs *fs)
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
		s = ft_itoa_base_u(val, 8, 0);	
	if (fs->flags & F_HTAG)
	{
		tmp = ft_strjoin("0", s);
		free(s);
		s = ft_strdup(tmp);
		free(tmp);
	}
	return (s);
}

int		print_o(t_fs *fs, va_list ap)
{
	unsigned long long int	val;
	char					*s;
	char					*tmp;
	int						size;
	int						ret;

	ret = 0;
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
		ret = print_o_on_left(fs, s, size);
	else
		ret = print_o_on_right(fs, s, size);
	free(s);
	return (ret);
}
