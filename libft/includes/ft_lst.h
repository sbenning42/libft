/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 10:39:25 by sbenning          #+#    #+#             */
/*   Updated: 2017/04/25 09:27:41 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include "ft_header.h"
# include "ft_mem.h"

struct				s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel_if(t_list **alst, void *ref, \
									int (*f)(void *, void *, size_t), \
									void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *elem);
void				ft_lstadd_back(t_list **alst, t_list *elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
