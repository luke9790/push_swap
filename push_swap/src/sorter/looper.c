/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:11:06 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/02 16:23:52 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>
/*	
La funziona cerca il loop nella lista. Max tag parte dal valore minimo e 
si aggiorna per il massimo indice trovato nel loop e
aumenta il counter ogni volta che si trova indici successivi. Set si usa 
per la variabile keep, 0 di default, 1 se l'elemento
e' da mantenere nel loop. Il valore di set e' 0 per le liste di utilita', 
1 per quelle valide(vedi funzione dopo).
Se il loop e' nullo si riassocia alla lista, se corrisponde allo start si 
fa un break (siamo ripartiti da capo)
Il valore di ritorno e' il conteggio degli elementi consecutivi del loop.
*/
int	loop_list(t_list *list, t_list *start, int set)
{
	t_list	*loop;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	loop = start;
	while (loop)
	{
		if (set)
			loop->keep = 0;
		if (loop->index > max_tag)
		{
			max_tag = loop->index;
			count++;
			if (set)
				loop->keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = list;
		if (loop == start)
			break ;
	}
	return (count);
}
/*	
La funzione serve per trovare il loop della lista piu' grande possibile.
 Si esegue loop_list per ogni elemento della lista start (copiata in t)
e si associa il massimo valore di elementi consecutivi in max, mentre 
max_keep corrisponde all'elemento da cui partire per il loop di max.
Una volta fatto il primo ciclo eseguiamo loop_list per il max_keep nella 
lista start data come parametro.
NOTA BENE: prima chiamo loop_list con set a 0, quindi non salva i valori
(la uso per trovare il loop migliore),dopo 1 per tenere i keep a 1(usarli poi).
Il valore di ritorno e' il valore di max, quindi il loop piu' grande.
*/

int	find_biggest_loop(t_list *start, int set)
{
	t_list		*t;
	int			max;
	int			count;
	t_list		*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = loop_list(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (set)
		loop_list(start, max_keep, 1);
	return (max);
}
