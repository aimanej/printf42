/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:12:39 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/25 20:44:06 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_putchar(char c, int *r);
int		intlen(int n);
int		addlen(unsigned long n);
void	ft_putnbr(int n, int *r);
int		ft_printf(const char *fixed, ...);
void	ft_putadd(unsigned long n, int *r);
void	ft_putx(unsigned int n, int *r);
void	ft_putupperx(unsigned int n, int *r);
void	ft_putstr(char *str, int *r);
void	ft_putu(unsigned int n, int *r);

#endif
