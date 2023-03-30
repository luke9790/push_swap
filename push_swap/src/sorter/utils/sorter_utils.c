/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:05:14 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/02 12:13:18 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>
/*	
Prima parte della funzione resolve. Appoggiamo nella struttura mem le 
variabili chiave come il loop piu' lungo, la lunghezza della lista
il numero di gruppi in cui dividere la lista(minimo 1) e la dimensione dei
 gruppi. Mem->max e' l'indice piu' alto(trovato prima), quindi 
il numero di elementi da ordinare.  
## VALUTARE SE CAMBIARE IL NUMERO 150 E FARE GRUPPI PIU PICCOLI ##
*/
void	init_resolve(t_mem *mem)
{
	mem->big = find_biggest_loop(mem->a, 1);
	mem->size = list_size(mem->a);
	mem->group_cnt = ft_maggiore(1, (int)(mem->max / 150.0));
	mem->group_sz = mem->max / mem->group_cnt;
}
/*	
Funzione per calcolare la distanza dalla cima della lista, scorre la lista 
finche indice e tag non coincidono(o se e' oltre meta size va in negativo)
*/

int	distance_to_top(t_list *a, int tag)
{
	int	i;
	int	size;

	i = 0;
	size = list_size(a);
	while (a)
	{
		if (a->index == tag)
			break ;
		a = a->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}
/*	
Nel caso in cui il tag sia oltre meta' della lista va reso negativo 
dato che facciamo il passaggio inverso
*/

int	distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}
/*	
Funzione per calcolare l'elemento piu' vicino in un determinato gruppo. 
Mettiamo per la distanza massima un valore molto alto random.
Scorriamo una copia della lista e controlliamo se l'indice dell'elemento
 rientra nel gruppo(group size * cur_group, ex 30 x1 prende i primi 30 elementi,
succesivamente quelli minori di 60 ma i primi 30 sono gia' presi e cosi via).
Se l'elemento corrisponde al gruppo, calcoliamo la distanza dal vertice del
 gruppo(positivo o negativo) e l'associamo a distance,
mentre closest diventa l'elemento attuale. 
Se la distanza e' zero significa che l'elemento e' gia' il piu' vicino 
altrimenti scorriamo la lista.
*/

t_list	*closest_in_group(t_list *list, int cur_group, int group_sz)
{
	t_list	*closest;
	t_list	*cur;
	int		distance;
	int		cur_dist;

	distance = 0xFFFFFFF;
	closest = NULL;
	cur = list;
	while (cur)
	{
		if (cur->index <= group_sz * cur_group && !cur->keep)
		{
			cur_dist = distance_to_top(list, cur->index);
			if (ft_assoluto(cur_dist) < ft_assoluto(distance))
			{
				distance = cur_dist;
				closest = cur;
				if (distance == 0)
					break ;
			}
		}
		cur = cur->next;
	}
	return (closest);
}
