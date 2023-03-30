/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:35:43 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/02 11:13:29 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>
/*	
creiamo le strutture per la memoria e per la gestione della 
lista tag(da vedere nel dettaglio)
Con read args prendiamo i dati passati come arg e li immettiamo nella lista
 a in mem, controllando che siano dati validi.
Se non sono gia' ordinati, usiamo la lista tag insieme alla funzione di 
ordinamento della lista.
Nel caso ci siano solo 5 numeri usiamo la funzione semplificata, altrimenti 
usiamo resolve per i casi lunghi.
Resolve fa il grosso e stampa operazioni a schermo. Una volta finita liberiamo 
la memoria nelle due strutture usate.
*/
int	main(int argc, char **argv)
{
	t_mem	mem;
	t_list	*start_tag;

	mem.a = NULL;
	mem.b = NULL;
	mem.print = 1;
	if (argc <= 1)
		return (0);
	read_args(argc, argv, &mem);
	if (!is_ordered(&mem))
	{
		start_tag = (mem.a);
		ft_ordinalista(&start_tag);
		indicizza(start_tag, &mem);
		if (mem.max == 5)
			prepare_five(&mem);
		resolve(&mem, 1);
	}
	clear_all(&mem);
	start_tag = NULL;
	return (0);
}
