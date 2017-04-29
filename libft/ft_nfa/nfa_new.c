/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nfa_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:59:40 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/26 11:59:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

t_state			*nfa_new_state(int final, t_list *trans, t_list *eps_trans)
{
	t_state		*state;

	if (!(state = ft_memalloc(sizeof(t_state))))
		return (NULL);
	state->final = final;
	state->trans = trans;
	state->eps_trans = eps_trans;
	return (state);
}

t_nfa			*nfa_new(void)
{
	return (ft_memalloc(sizeof(t_nfa)));
}

t_nfa			*nfa_new_atom(void)
{
	t_nfa		*nfa;
	t_state		*state;

	if (!(nfa = nfa_new()))
		return (NULL);
	if (!(state = nfa_new_state(0, NULL, NULL)))
		return (NULL);
	if (nfa_add_state(nfa, state))
		return (NULL);
	nfa_set_initial(nfa, state);
	if (!(state = nfa_new_state(NFA_FINAL, NULL, NULL)))
		return (NULL);
	if (nfa_add_state(nfa, state))
		return (NULL);
	nfa_set_terminal(nfa, state);
	return (nfa);
}

void			nfa_merge(t_nfa *dest, t_nfa *origin)
{
	ft_lstadd_back(&dest->state, origin->state);
	dest->nb_state += origin->nb_state;
}
