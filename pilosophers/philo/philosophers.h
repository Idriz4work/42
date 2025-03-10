/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:36:29 by iatilla-          #+#    #+#             */
/*   Updated: 2025/03/10 01:39:18 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

#define IS_EATING -12
#define IS_SLEEPING -13
#define IS_THINKING -14

typedef struct s_philosophers
{
	/* data */
	int state;
	
} t_phi;
