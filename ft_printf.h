/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:12:39 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/12 15:15:49 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void    ft_putchar_fd(char c);
int     intlen(int n);
int     ft_putnbr(int n);
int ft_printf(const char *fixed, ...);
unsigned long     ft_putadd(unsigned long n);

# endif
