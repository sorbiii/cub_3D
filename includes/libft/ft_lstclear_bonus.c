/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:00:07 by mzapora           #+#    #+#             */
/*   Updated: 2024/12/15 21:46:07 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	list = *lst;
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
