/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:12:29 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/01 12:03:36 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>
/*	
funzioni per liberare la memoria, sia che vada tutto bene che in caso di errori
*/
void	clear_all(t_mem *mem)
{
	ft_free_list(&(mem->a));
	ft_free_list(&(mem->b));
}

void	exit_error(t_mem *mem)
{
	ft_puterr("Error");
	clear_all(mem);
	exit(EXIT_FAILURE);
}
