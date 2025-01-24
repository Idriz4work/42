/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:43 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/24 07:53:44 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/Libft/get_next_line/get_next_line.h"
# include "../includes/Libft/libft.h"
# include "../includes/ft_printf/ft_printf_bonus.h"
# include <limits.h>

typedef struct s_stack
{
	t_list			*a;
	t_list			*b;
}					t_stack_top;

// algorithm
void				osman_sort_algorithm(t_stack_top **stacks);

void				merge(t_stack_top *stak, int left[], int right[]);
void				merge_sort(t_stack_top **stacks);
// void	merge_sort_recursion(t_stack_top **stak, int left, int right);
void				merge_sort_array(t_stack_top **stak, int left, int mid,
						int right);

// Function to handle operations for the push_swap project
void				print_stack(t_stack_top **stak, int a_b);
// void		handle_ops(void);
void				rotate_a(t_stack_top **stacks);
void				rotate_b(t_stack_top **stacks);
void				rotate_anb(t_stack_top **stacks);
void				reversey_ra(t_stack_top **stacks);
void				reversy_rb(t_stack_top **stacks);
void				reversey_rev_rrr(t_stack_top **stacks);
void				swap_a(t_stack_top **stacks);
void				swap_b(t_stack_top **stacks);
void				sa_ab_same(t_stack_top **stacks);
void				push_a(int value, t_stack_top **stacks);
void				push_b(int value, t_stack_top **stacks);
void				pop_a(t_stack_top **stacks);
void				pop_b(t_stack_top **stacks);

// utils
int					check_sorted(t_stack_top **stacks);
int					initialize_stack(t_stack_top **stak, t_list **nodes);
static int			is_valid_number(char *str);
int					handle_ops(char **argv);

#endif