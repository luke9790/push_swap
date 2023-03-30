/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:52:32 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/01 11:50:45 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>
/*	
le operazioni richieste nel soggetto, si basano ovviamente su quelle generali 
per ruotare top e bottom (avendo spazio pure una generica per stampare errori)
*/
void	rotate_b_a(t_mem *mem)
{
	put_top_to_bottom(&(mem->a));
	put_top_to_bottom(&(mem->b));
	if (mem->print)
		ft_putstr("rr");
}

void	ft_puterr(char *str)
{
	int		i;
	char	n;

	i = 0;
	while (str[i])
		i++;
	n = '\n';
	write(2, str, i);
	write(2, &n, 1);
}
