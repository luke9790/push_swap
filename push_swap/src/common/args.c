/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:01:12 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/01 16:06:05 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>
/*	
la funzione serve per prendere i char passati come argomenti nel programma, 
trasformarli in int e inserirsi nella lista a (mem->a)
usiamo spaziovuoto come flag e poi come spazio vero e proprio. 
Scorrendo le stringhe degli argomenti controlliamo se ci sono elementi 
diversi da spazio, +,- o dei numeri, nel caso riportiamo errore.
Appurato questo, se troviamo un numero lo inseriamo nella lista. Continuiamo 
a scorrere e fintanto non troviamo uno spazio, spaziovuoto non torna 1,
evitando dunque di prendere numeri a caso. 
Scritta cosi' spaziovuoto e' vero, cioe 1, se argv[i][j] corrisponde a ' ',
 altrimenti e' 0. (Limite 15 linee, maledetto Norminette)
*/
void	read_args(int argc, char **argv, t_mem *mem)
{
	int	j;
	int	i;
	int	spaziovuoto;

	i = 1;
	spaziovuoto = 1;
	while (i < argc)
	{
		spaziovuoto = 1;
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' '
				&& !ft_isdigit(argv[i][j]))
				exit_error(mem);
			if (spaziovuoto == 1 && argv[i][j] != ' ')
			{
				init(&(mem->a), ftatois(argv[i] + j, mem), -1, mem);
				spaziovuoto = 0;
			}
			spaziovuoto = argv[i][j] == ' ';
		}
		i++;
	}
}
