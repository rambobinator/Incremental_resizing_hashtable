#include "chained_list.h"

void		list_append_front(t_list **lst, void *data)
{
	t_list	*tmp;

	tmp = list_new_node(data);
	tmp->next = *lst;
	*lst = tmp;
}

void		list_map(t_list *lst, void (*f)(t_list, void *), void *args)
{
	t_list	*it;

	it = lst;
	while (it)
	{
		f(*it, args);
		it = it->next;
	}
}

t_list		*list_new_node(void *data)
{
	t_list	*new_node;

	if (!(new_node = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void		list_remove_node(t_list *head, t_list *node)
{
	t_list	*it;

	it = head;
	while (it)
	{
		if (it->next == node)
		{
			it->next = node->next;
			free(node);
			break ;
		}
		it = it->next;
	}
}
