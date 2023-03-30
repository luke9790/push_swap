/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:00:19 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/03 12:10:17 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sorter/sorter.h>
/*	
Funzione usata per calcolare la distanza. P e' l'ultimo elemento della lista, 
c quello attuale, cmax lo usiamo per avere il valore massimo e quello da 
ricercare. Scorriamo c e controlliamo se l'indice dell'elemento attuale e' 
minore del precedente e se il valore t(che sara' l'indice) rientra
tra i due valori(secondo ordine). In tal caso mettiamo cmax[0] 
come i(indice o tag per intenderci), 
se oltre meta' size in negativo per spingerlo in basso. Controlliamo se e' 
minore del valore cmax[1] e nel caso sovrascriviamo. Scorriamo la lista e le
 operazioni poi per tutti gli elementi, in modo tale da avere la distanza 
 massima nella lista passata. NOTA cmax[1] e' un valore alto random per poter 
 essere sovrascritto sempre(la prima volta).
In sintesi prendendo le distanze tra i vari indici della lista si calcola 
la distanza massima, quindi l'elemento piu' lontano da sistemare.
*/

int	insert_distance(t_list *list, int t, int size)
{
	t_list	*p;
	t_list	*c;
	int		c_max[2];
	int		i;

	i = 0;
	p = get_last_element(list);
	c = list;
	c_max[1] = 0xFFFFFFF;
	while (c)
	{
		if ((p->index > c->index && (t < c->index || t > p->index))
			|| (t > p->index && t < c->index))
		{
			c_max[0] = i;
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (ft_assoluto(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		i++;
	}
	return (c_max[1]);
}
/*	
Funzione usata per calcolare la rotazione da effettuare. Stabiliamo 
le variabili che ci servono: 
distanza totale, distanza di b, numero da inserire e indice. 
Associamo a temp la lista b e iniziamo a scorrere.
Calcoliamo la distanza b(il tag, negativo o positivo in base alla 
posizione nella size)
calcoliamo insert, la distanza piu' alta della lista
calcoliamo la distanza totale (con alcuni calcoli della minchia, 
in base all'essere positivi o negativi)
se la distanza totale e' minore della distanza massima, cambiamo 
i valori di maxdist e inseriamo i valori corrispondenti come puntatori
 di rot_a e rot_b, che verranno usati successivamente.
*/

void	calculate_b_rotation(t_mem *m, int max_dist, int *rot_a, int *rot_b)
{
	int	dist_total;
	int	insert;
	int	distance_b;
	int	i;

	i = 0;
	m->temp = m->b;
	while (m->temp)
	{
		distance_b = distance_to_tag(i++, m->max - m->size);
		insert = insert_distance(m->a, m->temp->index, m->size);
		dist_total = ft_assoluto(insert) + ft_assoluto(distance_b);
		if (insert > 0 && distance_b > 0)
			dist_total -= ft_minore(distance_b, insert);
		if (insert < 0 && distance_b < 0)
			dist_total += ft_maggiore(distance_b, insert);
		if (dist_total < max_dist)
		{
			max_dist = dist_total;
			*rot_a = insert;
			*rot_b = distance_b;
		}
		m->temp = m->temp->next;
	}
}
/*	
Funzione usata per mettere in ordine gli elementi da ripushare in A. 
Prima calcola la rotazione, poi la effettua, poi pusha.
*/

void	populate_b(t_mem *m)
{
	int	rot_a;
	int	rot_b;

	while (m->b)
	{
		calculate_b_rotation(m, 0xFFFFFFF, &rot_a, &rot_b);
		rotate(m, rot_a, rot_b);
		push_a(m);
		(m->size)++;
	}
	rotate(m, distance_to_top(m->a, 0), 0);
}
/*	
Funzione usata per controllare nelle due liste fake se ha senso swappare 
i due elementi. Associati gli elementi alle controparti
originali, mette a confronto i due loop piu' grandi: se il secondo e' 
piu' grande, e' meglio swappare gli elementi, 
quindi ritorna 1, altrimenti se meglio come sono ritorna 0.
*/

int	can_swap(t_list *list)
{
	t_list	fake;
	t_list	fake2;
	int		count;
	int		count2;

	fake.next = &fake2;
	fake.index = list->next->index;
	fake2.next = list->next->next;
	fake2.index = list->index;
	count = find_biggest_loop(list, 0);
	count2 = find_biggest_loop(&fake, 0);
	if (count2 > count)
		return (1);
	return (0);
}
/*	
funzione chiave del progetto, parte una volta che abbiamo indicizzato gli
 elementi della lista e risistema l'ordine secondo indice.
Definiamo la distanza e con init resolve facciamo i primi passi(troviamo 
il loop piu lungo(big), definiamo la grandezza della lista e dei gruppi).
While(finche la size dalla lista >= bigloop e il gruppo attuale rientra nel
 conteggio gruppi) ## SEMPRE VERA STA CONDIZIONE? ##
in temp mettiamo l'elemento piu' vicino del gruppo(se vuoto continue, 
cioe passa all'elemento successivo)
calcoliamo la distanza dal vertice del gruppo.
Adesso abbiamo vari casi:
1	Usiamo can_swap(vedi sopra) per controllare se swappare, 
se si lo facciamo e ricerchiamo il loop piu' grande.
2	Se la distanza e' zero pushiamo in b e diminuiamo di uno la size.
3	Se c'e' un solo gruppo facciamo rotate_b_a
4	Negli altri casi rotate, prendendo il minore tra 1 e la distanza.
Completato il ciclo, avremo spostato tutto in B, quasi nell'ordine corretto. 
 Adesso tocca a Populate_b, che controlla l'ordine 
in B, effettua alcune operazioni se necessario, e rispedisce tutti gli 
elementi in A in ordine corretto. VEDI FUNZIONE
*/

void	resolve(t_mem *m, int cur_group)
{
	int	distance;

	init_resolve(m);
	while (m->size >= m->big && cur_group <= (m->group_cnt + 1))
	{
		m->temp = closest_in_group(m->a, cur_group, m->group_sz);
		if (m->temp == NULL && ++cur_group)
			continue ;
		distance = distance_to_top(m->a, m->temp->index);
		if (m->a && can_swap(m->a))
		{
			swap_a(m);
			m->big = find_biggest_loop(m->a, 1);
		}
		else if (m->a && !m->a->keep && distance == 0)
		{
			push_b(m);
			(m->size)--;
		}
		else if (m->group_cnt == 1)
			rotate_b_a(m);
		else
			rotate(m, ft_minore(1, ft_maggiore(-1, distance)), 0);
	}
	populate_b(m);
}
