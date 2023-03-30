/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:38:59 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/01 11:51:48 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>
/*	
le operazioni richieste nel soggetto, si basano ovviamente 
su quelle generali per swap e push
*/
void	swap_a(t_mem *mem)
{
	swap_silenzioso(&(mem->a));
	if (mem->print)
		ft_putstr("sa");
}

void	swap_b(t_mem *mem)
{
	swap_silenzioso(&(mem->b));
	if (mem->print)
		ft_putstr("sb");
}

void	swap_b_a(t_mem *mem)
{
	swap_silenzioso(&(mem->b));
	swap_silenzioso(&(mem->a));
	if (mem->print)
		ft_putstr("ss");
}

void	push_b(t_mem *mem)
{
	push_top_x1_on_x2(&(mem->a), &(mem->b));
	if (mem->print)
		ft_putstr("pb");
}

void	push_a(t_mem *mem)
{
	push_top_x1_on_x2(&(mem->b), &(mem->a));
	if (mem->print)
		ft_putstr("pa");
}
