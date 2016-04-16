/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 06:45:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/11 15:42:49 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ps_stack_print_full(t_psdata *ps, t_psstack *root)
{
	t_psstack *stack;

	stack = root;
	if (stack)
	{
		ft_printf("%s%-6s ", ps->cblu, "[STACK] ");
		while (stack)
		{
			ft_printf("%-3d ", stack->val);
			stack = stack->next;
		}
		ft_printf("%s\n", ps->cwhi);
	}
}