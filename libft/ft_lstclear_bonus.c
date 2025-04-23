/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:26:12 by isrguerr          #+#    #+#             */
/*   Updated: 2024/10/10 12:54:37 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
