/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:43 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/18 19:05:19 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/Libft/get_next_line/get_next_line.h"
# include "../includes/Libft/libft.h"
# include "../includes/ft_printf/ft_printf_bonus.h"
# include <limits.h>

// t_stk_top struct
typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
}					t_stk_top;

// algorithm
void	merge_sort(t_stk_top **stak, int left, int right);
void	merge_sort_recursion(t_stk_top **stak, int left, int right);
void	merge_sort_array(t_stk_top **stak, int left, int mid, int right);

// Function to handle operations for the push_swap project
void				print_stack(t_stk_top *stak, int a_b);
// void		handle_ops(void);
void			rotate_a(t_stk_top *stak);
void			rotate_b(t_stk_top *stak);
void			rotate_anb(t_stk_top *stak);
void			reversey_ra(t_stk_top *stak);
void			reversy_rb(t_stk_top *stak);
void			reversey_rev_rrr(t_stk_top *stak);
void			swap_a(t_stk_top *stak);
void			swap_b(t_stk_top *stak);
void			sa_ab_same(t_stk_top *stak);
void			push_a(int value, t_stk_top *stak);
void			push_b(int value, t_stk_top *stak);
void			pop_a(t_stk_top *stak);
void			pop_b(t_stk_top *stak);

#endif