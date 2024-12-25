/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 07:50:43 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/25 08:45:55 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/ft_printf/ft_printf.h"
# include "Libft/get_next_line/get_next_line.h"
# include "Libft/libft.h"

// stack struct 
typedef struct stk
{
	t_list	a;
	t_list	b;
}			stack;

// Function to handle operations for the push_swap project
void		handle_ops(void);
void		rotate_a(void);
void		rotate_b(void);
void		rotate_anb(void);
void		reversey_ra(void);
void		reversy_rb(void);
void		reversey_rev_ranrb(void);
void		swap_a(void);
void		swap_b(void);
void		sa_ab_same(void);
void		push_a(void);
void		push_b(void);

#endif