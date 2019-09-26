/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:25:43 by aihya             #+#    #+#             */
/*   Updated: 2019/09/26 13:00:46 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		interpret_format(const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			
		}
		i++;
	}
	return (1);
}
/*
t_fs	new_fs(const char *format, int start_index)
{
	int		i;

	i = start_index;
	while (format[i])
	{
		i++;
	}
}*/
