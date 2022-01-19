/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2021/09/10 13:33:59 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*b, size_t	len)
{
	size_t	counter;
	char	*ptr;

	if (len == 0)
		return ;
	ptr = b;
	counter = 0;
	while (counter < len)
	{
		ptr[counter] = 0;
		counter++;
	}
}
