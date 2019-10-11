/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:25:43 by aihya             #+#    #+#             */
/*   Updated: 2019/10/11 22:54:15 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		repeate_char(char c, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		ft_putchar(c);
		j++;
	}
	return (j);
}

int		interpret_format(const char *format, va_list ap)
{
	int		i;
	int		j;
	t_fs	*fs;
	int		size;

	i = 0;
	size = 0;
	while (format != NULL && format[i])
	{
		if (format[i] == '%')
		{
			fs = get_fs(format, i);
			if (fs->specifier == '\0' || fs->specifier == '%' || ft_strchr(SPECIFIERS, fs->specifier) == NULL)
			{
				if (fs->specifier != '\0')
				{
					size += print_non_specifier(fs, fs->specifier);
					i += 1 + fs->size;
				}
				else
				{
					free(fs);
					break ;
				}
				free(fs);
				continue ;
			}
			else if (fs->specifier == 'c')
				size += print_c(fs, ap);
			else if (fs->specifier == 's')
				size += print_s(fs, ap);
			else if (fs->specifier == 'p')
				size += print_p(fs, ap);
			else if (fs->specifier == 'o')
				size += print_o(fs, ap);
			else if (fs->specifier == 'x')
				print_x(fs, ap);
			i += 1 + fs->size;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			size++;
		}
	}
	return (size);
}

t_fs	*init_fs()
{
	t_fs	*fs;

	fs = (t_fs *)malloc(sizeof(t_fs));
	fs->flags = 0;
	fs->width = 0;
	fs->precision = DEFAULT;
	fs->length = 0;
	fs->specifier = 0;
	fs->size = 0;
	return (fs);
}

void	set_length(const char *format, int *i, t_fs *fs)
{
	if ((format[*i] == 'h' && format[*i + 1] && format[*i + 1] == 'h')
			||	(format[*i] == 'l' && format[*i + 1] && format[*i + 1] == 'l'))
	{
		fs->length = format[*i] == 'h' ? L_hh : L_ll;
		*i += 2;
	}
	else if (format[*i] == 'h' || format[*i] == 'l')
	{
		fs->length = format[*i] == 'h' ? L_h : L_l;
		*i = *i + 1;
	}
	else if (format[*i] == 'L')
	{
		fs->length = L_L;
		*i = *i + 1;
	}
}

void	set_precision(const char *format, int *i, t_fs *fs)
{
	int		j;
	char	*num_string;

	*i = *i + 1;
	if (format[*i] && (format[*i] < 48 || format[*i] > 57))
		fs->precision = 0;
	else
	{
		j = 0;
		while (ft_strchr(NUMBERS, format[*i + j]))
			j++;
		num_string = ft_strsub(format, *i, j);
		fs->precision = ft_atoi(num_string);
		free(num_string);
		*i = *i + j;
	}
}

void	set_flags(const char *format, int *i, t_fs *fs)
{
	if (format[*i] == ' ')
		fs->flags |= F_SPACE;
	else if (format[*i] == '+')
		fs->flags |= F_PLUS;
	else if (format[*i] == '-')
		fs->flags |= F_DASH;
	else if (format[*i] == '0')
		fs->flags |= F_ZERO;
	else if (format[*i] == '#')
		fs->flags |= F_HTAG;
	*i = *i + 1;
}

void	set_width(const char *format, int *i, t_fs *fs)
{
	int		j;
	char	*num_string;

	j = 0;
	while (format[*i + j] && format[*i + j] >= 48 && format[*i + j] <= 57)
		j++;
	num_string = ft_strsub(format, *i, j);
	fs->width = ft_atoi(num_string);
	free(num_string);
	*i = (*i + j);
}

t_fs	*get_fs(const char *format, int start_index)
{
	int		i;
	t_fs	*fs;

	i = start_index + 1;
	fs = init_fs();
	fs->size = i;
	while (format[i] && ft_strchr(ALL, format[i]))
	{
		if (ft_strchr(LENGTHS, format[i]))
			set_length(format, &i, fs);
		else if (format[i] == '.')
			set_precision(format, &i, fs);
		else if (ft_strchr(FLAGS, format[i]))
			set_flags(format, &i, fs);
		else if (ft_strchr(NUMBERS, format[i]))
			set_width(format, &i, fs);
	}
	fs->specifier = format[i];
	fs->size = (i - fs->size) + 1;
	return (fs);
}      
