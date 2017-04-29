/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:00:13 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 12:00:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

int			nfa_trans(t_state *from, t_state *to, char start, char end)
{
	t_list	*trans;

	if (!(trans = nfa_new_trans_entry(start, end, to)))
		return (-1);
	nfa_add_trans(from, trans);
	return (0);
}

int			nfa_eps_trans(t_state *from, t_state *to)
{
	t_list	*eps_trans;

	if (!(eps_trans = nfa_new_eps_trans_entry(to)))
		return (-1);
	nfa_add_eps_trans(from, eps_trans);
	return (0);
}
