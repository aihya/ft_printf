/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:44:11 by aihya             #+#    #+#             */
/*   Updated: 2019/09/21 22:21:04 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_printf(const char * str)
{
//	va_list	va;

//	va_start(ap, str);
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	return (0);
}
