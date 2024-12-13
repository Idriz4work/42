/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 05:11:11 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/13 05:51:24 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include "../ft_printf/Libft/libft.h"
# include "../ft_printf/ft_printf_bonus.h"

int pipex(int argc,char **format);
int handle_multiple_cmd(char **format);

#endif
