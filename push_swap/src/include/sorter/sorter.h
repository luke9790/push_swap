/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:24:14 by lmasetti          #+#    #+#             */
/*   Updated: 2023/02/02 11:18:49 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include <common/common.h>

int		has_tag(t_list *list, int tag);
void	prepare_five(t_mem *mem);

void	indicizza(t_list *start, t_mem *mem);

int		loop_list(t_list *list, t_list *start, int set);
int		find_biggest_loop(t_list *start, int set);

void	double_rotate(t_mem *mem, int *rot_a, int *rot_b);
void	rotate(t_mem *mem, int rot_a, int rot_b);

void	init_resolve(t_mem *mem);
int		distance_to_top(t_list *a, int tag);
int		distance_to_tag(int tag, int size);
t_list	*closest_in_group(t_list *list, int cur_group, int group_sz);
int		can_swap(t_list *list);

int		insert_distance(t_list *list, int t, int size);
void	calculate_b_rotation(t_mem *m, int max_dist, int *rot_a, int *rot_b);
void	populate_b(t_mem *m);
void	resolve(t_mem *m, int cur_group);

#endif
