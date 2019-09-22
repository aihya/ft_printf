/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:25:43 by aihya             #+#    #+#             */
/*   Updated: 2019/09/22 21:49:35 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		interpret_format(const char *format, va_list ap)
{
//	char	*s;

	ft_putendl(format);
	(void)ap;
/*	while ((s = va_arg(ap, char *)))
	{
		ft_putendl(s);
	}*/
	return (1);
}


