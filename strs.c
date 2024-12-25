/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:25:35 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/25 18:25:49 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c, int *r)
{
	write(1, &c, 1);
	(*r)++;
}

void	ft_putstr(char *str, int *r)
{
	if (!str)
	{
		write(1, "(null)", 6);
		(*r) += 6;
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, r);
		str++;
	}
}
