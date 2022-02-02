/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 19:16:58 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ptrn(char const *s, char c)
{
	size_t	ptrn;
	size_t	counter;

	ptrn = 0;
	counter = 0;
	if (s[0] == '\0')
		return (0);
	if (s[counter] != c)
		ptrn++;
	counter++;
	while (s[counter] != '\0')
	{
		if ((s[counter - 1] == c) && (s[counter] != c))
			ptrn++;
		counter++;
	}
	return (ptrn);
}

static char	**ft_suballoc(char const *s, char c, char **ptr)
{
	size_t	c1;
	size_t	c2;
	size_t	len;

	c1 = 1;
	c2 = 0;
	len = 0;
	if (s[0] != c)
		len++;
	while (s[c1] != '\0')
	{
		if (s[c1] != c)
			len++;
		if (s[c1] == c && s[c1 - 1] != c)
		{
			ptr[c2] = malloc(len + 1);
			c2++;
			len = 0;
		}
		c1++;
	}
	if (s[c1 - 1] != c)
		ptr[c2] = malloc(len + 1);
	return (ptr);
}

static char	**ft_subcpy(char const *s, char c, char **ptr)
{
	size_t	c1;
	size_t	c2;
	size_t	c3;

	c1 = 1;
	c2 = 0;
	c3 = 0;
	if (s[0] != c)
		ptr[c2][c3++] = s[0];
	while (s[c1] != '\0')
	{
		if (s[c1] != c)
			ptr[c2][c3++] = s[c1];
		if (s[c1] == c && s[c1 - 1] != c)
		{
			ptr[c2][c3] = '\0';
			c2++;
			c3 = 0;
		}
		c1++;
	}
	if (s[c1] == '\0' && s[c1 - 1] != c)
		ptr[c2][c3] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	ptrn;

	ptrn = ft_ptrn(s, c);
	ptr = malloc((ptrn + 1) * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	ptr[ptrn] = (char *) '\0';
	if (*s == '\0')
		return (ptr);
	ptr = ft_suballoc(s, c, ptr);
	return (ft_subcpy(s, c, ptr));
}
