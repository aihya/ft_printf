/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:54:13 by aihya             #+#    #+#             */
/*   Updated: 2019/10/22 18:15:57 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <limits.h>

void	print(t_fs *fs)
{
	printf("flags: %d\n", fs->flags);
	printf("width: %d\n", fs->width);
	printf("precision: %d\n", fs->precision);
	printf("length: %d\n", fs->length);
	printf("specifier: %c\n", fs->specifier);
	printf("size: %d\n", fs->size);
}

int		main(void)
{
	printf("| %d\n", ft_printf("%-100x", 0U));
	printf("| %d\n", printf("%-100x", 0U));

//	printf("%d\n", ft_atoi("-5000"));
//	print(get_fs("%%", 1));
//	ft_printf("%l%o%l\n");
	return (0);
}
