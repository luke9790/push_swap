/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:06:25 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/01 12:01:59 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

int	list_size(t_list *l)
{
	int	i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_list	*get_last_element(t_list *l)
{
	if (l == NULL)
		return (NULL);
	while (l->next)
	{
		l = l->next;
	}
	return (l);
}
/*	
nella lista ho una variabile che tiene il valore, quindi controlliamo 
con il valore dato se e' gia presente
*/

int	list_controllodoppioni(t_list *l, int value)
{
	while (l)
	{
		if (l->value == value)
			return (1);
		l = l->next;
	}
	return (0);
}
/*	
controlla se la lista e' gia ordinata, se il valore 
precedente e' > del successivo, da due tipi di errore?
*/

int	is_ordered(t_mem *m)
{
	int		prev;
	t_list	*l;

	if (m->b)
		return (0);
	if (!m->a)
		return (1);
	l = m->a;
	prev = l->value;
	while (l)
	{
		if (prev > l->value)
			return (0);
		prev = l->value;
		l = l->next;
	}
	return (1);
}
