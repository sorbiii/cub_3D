/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:15:25 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/13 02:54:35 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && nmemb != 0)
		if (SIZE_MAX / nmemb <= size)
			return (NULL);
	p = malloc(size * nmemb);
	if (p == NULL)
		return (p);
	ft_bzero(p, size * nmemb);
	return (p);
}
