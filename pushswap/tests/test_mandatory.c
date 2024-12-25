/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:32:15 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/25 08:39:14 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main()
{
	push_swap("./a.out");
	push_swap("./a.out 0");
	push_swap("./a.out d");
	push_swap("./a.out 2 0");
	push_swap("./a.out 1 2 0");
	push_swap("./a.out 1 2 3");
	push_swap("./a.out 3 2 1");
	push_swap("./a.out 23 3 0 33");
	push_swap("./a.out 22 10 2");
	push_swap("./a.out 4 0 2");
	push_swap("./a.out 1 2 3 2 10 99 23 22 -1 0 999");
	
}