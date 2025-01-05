/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:43 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/05 12:34:01 by iatilla-         ###   ########.fr       */
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

// Function to handle operations for the push_swap project
void				print_stack(t_stk_top *stak, int a_b);
// void		handle_ops(void);
t_stk_top			*rotate_a(t_stk_top *stak);
t_stk_top			*rotate_b(t_stk_top *stak);
t_stk_top			*rotate_anb(t_stk_top *stak);
t_stk_top			*reversey_ra(t_stk_top *stak);
t_stk_top			*reversy_rb(t_stk_top *stak);
t_stk_top			*reversey_rev_ranrb(t_stk_top *stak);
t_stk_top			*swap_a(t_stk_top *stak);
t_stk_top			*swap_b(t_stk_top *stak);
t_stk_top			*sa_ab_same(t_stk_top *stak);
t_stk_top			*push_a(int value, t_stk_top *stak);
t_stk_top			*push_b(int value, t_stk_top *stak);
t_stk_top			*pop_a(t_stk_top *stak);
t_stk_top			*pop_b(t_stk_top *stak);

#endif