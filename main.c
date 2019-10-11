/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:54:13 by aihya             #+#    #+#             */
/*   Updated: 2019/10/11 22:55:38 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

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
	printf("1: %d\n", printf("%23.5o|%-23.5o|%#23.5o|%023.5o\n", 0U, 0U, 0U, 0U));
	printf("2: %d\n", ft_printf("%23.5o|%-23.5o|%#23.5o|%023.5o\n", 0U, 0U, 0U, 0U));

//	printf("%d\n", ft_atoi("-5000"));
//	print(get_fs("%%", 1));
//	ft_printf("%l%o%l\n");
	return (0);
}
