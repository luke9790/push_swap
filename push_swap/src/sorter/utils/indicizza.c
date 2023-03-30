/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indicizza.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:07:41 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/02 11:18:59 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>
/*	
la funzione serve per inserire l'indice nella lista gia' ordinata, in modo 
tale da poter poi calcolare la sequenza di numeri successivi piu' lunga e
 gestire l'ordinamento degli elementi nel modo migliore,
col minore numero di operazioni possibili.  
*/
void	indicizza(t_list *start, t_mem *mem)
{
	int	i;

	i = 0;
	while (start)
	{
		start->index = i++;
		start = start->next_sort;
	}
	mem->max = i;
}
