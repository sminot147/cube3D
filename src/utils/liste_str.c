/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:11:17 by sminot            #+#    #+#             */
/*   Updated: 2025/04/08 12:11:19 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/**
 * Clear the linked list str
 * @note lst_str->content and lst_str is free.
 */
void	clear_lst_str(t_lststr **lst_str)
{
	t_lststr	*current;
	t_lststr	*tmp;

	if (!lst_str)
		return ;
	current = *lst_str;
	while (current)
	{
		tmp = current->next;
		free(current->content);
		free(current);
		current = tmp;
	}
}

/**
 * @return New node, with the content
*/
static t_lststr	*new_node(char *content)
{
	t_lststr	*node;

	node = ft_calloc(1, sizeof(t_lststr));
	if (node == NULL)
	{
		free(content);
		return (NULL);
	}
	node->content = content;
	return (node);
}

/**
 * Add back a node to the linked liste of string
*/
static void	add_lst_str(t_lststr **lst_str, t_lststr *new_node)
{
	t_lststr	*current;

	if (!*lst_str)
	{
		*lst_str = new_node;
		return ;
	}
	current = *lst_str;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

t_bool	add_content_lst(t_lststr **lst_str, char *new_content)
{
	t_lststr	*node;

	node = new_node(new_content);
	if (!node)
		return (FALSE);
	add_lst_str(lst_str, node);
	return (TRUE);
}

size_t	len_lst(t_lststr **lst_str)
{
	size_t		len;
	t_lststr	*current;

	len = 0;
	current = *lst_str;
	while (current)
	{
		current = current->next;
		++len;
	}
	return (len);
}
