/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_bubble3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 09:16:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			ps_bubble3_rotate(t_psdata *ps)
{
	int			ip;
	int			in;
	t_psstack	*x;

	if (!ps->st1a)
		return (1);
	ip = 0;
	in = 0;
	x = ps->st1a;
	while (x->val != ps->min && ++ip)
		x = x->p;
	x = ps->st1a;
	while (x->val != ps->min && ++in)
		x = x->n;
	if (ip <= in)
		while (ip--)
			ps_move1(ps, ra);
	else
		while (in--)
			ps_move1(ps, rra);
	return (1);
}

void		ps_bubble3_isok(t_psdata *ps)
{
	if (ps_issolved(ps, ps->st1a) && ps_bubble3_rotate(ps))
		return ;
	ps->nb1 = INT_MAX;
	ps_verbose(ps, 33);
}

void		ps_bubble3_run(t_psdata *ps)
{
	t_psstack	*last;
	t_psstack	*prev;
	int			loop;

	ps->i = 10;
	loop = ps->count;
	while (ps->i--)
	{
		if ((ps_issolved(ps, ps->st1a) && ps_bubble3_rotate(ps))
			|| (ps->nb1 > ps->nb2 || ps->nb1 > ps->nb3 || ps->nb1 > ps->nb4))
			break ;
		last = ps->st1a;
		prev = last->p;
		if (last->val > prev->val)
			ps_move1(ps, sa);
		if (ps_issolved(ps, ps->st1a) && ps_bubble3_rotate(ps))
			break ;
		ps_move1(ps, ra);
		if (--loop < 2)
		{
			loop = ps->count;
			ps_move1(ps, ra);
		}
	}
	ps_bubble3_isok(ps);
}

int			ps_bubble3(t_psdata *ps)
{
	if (!ps->st1a)
		return (1);
	if (ps_issolved(ps, ps->st1a) && ps_bubble3_rotate(ps))
		return (1);
	ps_move1(ps, rra);
	ps_move1(ps, rra);
	ps_bubble3_run(ps);
	return (1);
}
