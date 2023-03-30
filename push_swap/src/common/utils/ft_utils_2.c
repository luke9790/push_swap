/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:54:38 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/02 11:13:29 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_swap_list(t_list **prevnext, t_list *last)
{
	t_list	*swap;

	swap = *prevnext;
	*prevnext = last->next_sort;
	swap->next_sort = last->next_sort->next_sort;
	(*prevnext)->next_sort = swap;
}
/*	
funzione utilizzata con starttag == mem.a
usiamo prev come posizione precedente a quella attuale 
e last come ultima(su cui ci troviamo)
Scorriamo la lista nel while, se il valore attuale e' maggiore del prossimo
 (attuale - prossimo > 0) scambiamo i valori, altrimenti continuiamo a 
mettere i puntatori al prossimo elemento nell'ordine in cui li troviamo. 
Alla fine avremo la lista in mem.a (che gia' aveva i valori numerici)
anche coi puntatori agli elementi successivi in modo ordinato.
*/

void	ft_ordinalista(t_list **begin_list)
{
	t_list	*last;
	t_list	*prev;

	prev = NULL;
	last = *begin_list;
	while (last && last->next_sort)
	{
		if (last->value - last->next_sort->value > 0)
		{
			if (prev == NULL)
				ft_swap_list(begin_list, last);
			else
				ft_swap_list(&(prev->next_sort), last);
			last = *begin_list;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next_sort;
		}
	}
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	ft_free_list(t_list **list)
{
	t_list	*l;
	t_list	*next;

	l = *list;
	while (l)
	{
		next = l->next;
		free(l);
		l = next;
	}
	*list = NULL;
}
