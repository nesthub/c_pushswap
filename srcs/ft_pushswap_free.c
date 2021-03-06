/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 08:00:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 04:55:59 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ps_stupid2_free(t_stupid2 *stu)
{
	t_psstack	*destroy;

	while (stu->s)
	{
		destroy = stu->s;
		stu->s = stu->s->n;
		ft_memdel((void **)&destroy);
	}
	return (1);
}

void		ps_stack_free_one(t_psstack *stack)
{
	int			stop;
	t_psstack	*destroy;

	if (!stack)
		return ;
	stop = stack->val;
	stack = stack->n;
	while (stack->val != stop)
	{
		destroy = stack;
		stack = stack->n;
		ft_memdel((void **)&destroy);
	}
	ft_memdel((void **)&stack);
}

void		ps_stack_free(t_psdata *ps)
{
	t_psstack *destroy;

	ps_stack_free_one(ps->st1a);
	ps_stack_free_one(ps->st1b);
	ps_stack_free_one(ps->st2a);
	ps_stack_free_one(ps->st2b);
	ps_stack_free_one(ps->st3a);
	ps_stack_free_one(ps->st3b);
	ps_stack_free_one(ps->st4a);
	ps_stack_free_one(ps->st4b);
	ps_stack_free_one(ps->st5a);
	ps_stack_free_one(ps->st5b);
	ft_strdel(&ps->log1);
	ft_strdel(&ps->log2);
	ft_strdel(&ps->log3);
	ft_strdel(&ps->log4);
	ft_strdel(&ps->log5);
	while (ps->s)
	{
		destroy = ps->s;
		ps->s = ps->s->n;
		ft_memdel((void **)&destroy);
	}
}
