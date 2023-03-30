/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:37:08 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/01 15:50:21 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>
/*	
la funzione serve per prendere l'input dei valori singolarmente e inserirsi 
nella lista a, con indice -1 (per ora) last e' l'ultimo elemento presente
(il primo della lista stack) e ci serve per poter inserire i next dell'ultimo 
elemento(futuro) elem inizializza il singolo elemento che passiamo
(gli int dell av, value), che ci permette poi di controllare nei casi
 successivi al primo la presenza di doppioni. Il tag serve per operazioni 
successive, per ora e' fisso -1, il resto e' inizializzato NULL. Se la lista e' 
vuota(last == NULL) mettiamo subito neutro, senno scorriamo last e lo 
inseriamo come last next finale.
*/
void	init(t_list **stack, int value, int tag, t_mem *mem)
{
	t_list	*elem;
	t_list	*last;

	last = *stack;
	if (list_controllodoppioni(*stack, value))
		exit_error(mem);
	elem = malloc(sizeof(t_list));
	if (!elem)
		exit_error(mem);
	elem->next = NULL;
	elem->next_sort = NULL;
	elem->value = value;
	elem->index = tag;
	if (last == NULL)
	{
		*stack = elem;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = elem;
	last->next_sort = elem;
}
/*	
terzo = il terzo elemento della lista per mantenere ordine, poi facciamo 
lo swap tra il primo e il secondo elemento con temp
*/

void	swap_silenzioso(t_list **stack)
{
	t_list	*temp;
	t_list	*terzo;

	if (!*stack || !(*stack)->next)
		return ;
	terzo = (*stack)->next->next;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	temp->next = terzo;
}

/*	
top copia x1, x1 diventa il successivo, se gia presente qualcosa in x2 
lo sposto come next, senno e' vuoto
*/
void	push_top_x1_on_x2(t_list **x1, t_list **x2)
{
	t_list	*top;

	if (!*x1)
		return ;
	top = *x1;
	*x1 = top->next;
	if (*x2)
		top->next = (*x2);
	else
		top->next = NULL;
	*x2 = top;
}
/*	
uso top per copiare il valore iniziale x, x diventa il successivo, 
uso temp per scorrere in fondo e riassocio top e il valore nullo
*/

void	put_top_to_bottom(t_list **x)
{
	t_list	*top;
	t_list	*temp;

	if (!*x || !(*x)->next)
		return ;
	top = *x;
	*x = (*x)->next;
	temp = *x;
	while (temp->next)
		temp = temp->next;
	temp->next = top;
	top->next = NULL;
}
/*	
uso last per scorrere la lista, x(che e' top) diventa last next
(secondo elemento), x prende il valore dell'ultimo elemento, 
il next precedente diventa nullo (ora ultimo elemento) 
*/

void	put_bottom_to_top(t_list **x)
{
	t_list	*last;
	t_list	*prev;

	if (!*x || !(*x)->next)
		return ;
	last = *x;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = (*x);
	*x = last;
	prev->next = NULL;
}
