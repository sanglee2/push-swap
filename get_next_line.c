/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:47:39 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/25 21:22:03 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "push_swap.h"

t_list	*check_lst_storage(t_list *lst, char **ret, int fd)
{
	*ret = 0;
	while (fd != lst->fd)
	{
		if (lst->next == NULL)
		{
			lst->next = ft_lstnew(fd);
			if (!(lst -> next))
				return (NULL);
			(lst->next)->prev = (lst);
		}
		lst = lst->next;
	}
	if (lst->storage != NULL)
	{
		*ret = lst->storage;
		lst->storage = NULL;
	}
	return (lst);
}

int	check_ret(char **ret, t_list **lst, t_list **lst_fd, char **temp)
{
	*temp = ft_strchr(*ret, '\n');
	if (*temp)
	{
		if (*(++(*temp)))
		{
			(*lst_fd)->storage = ft_strjoin((*lst_fd)->storage, *temp);
			if (!((*lst_fd)-> storage))
			{
				all_free(lst, ret);
				return (0);
			}
			**temp = '\0';
			*temp = ft_strjoin(*ret, NULL);
			if (!(*temp))
			{
				all_free(lst, ret);
				return (0);
			}
			free(*ret);
			*ret = *temp;
		}
		return (0);
	}
	return (1);
}

int	append_line(t_list **lst, char **ret, char *buf, ssize_t output)
{
	char	*addr;

	buf[output] = '\0';
	addr = ft_strjoin(*ret, buf);
	if (!addr)
	{
		all_free(lst, ret);
		return (1);
	}
	if (*ret)
		free(*ret);
	*ret = addr;
	return (0);
}

int	get_char(char **ret, t_list **lst_fd, int fd, t_list **lst)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	output;

	output = read(fd, buf, BUFFER_SIZE);
	if (output <= 0)
	{
		ft_free1(ret, lst_fd, output, lst);
		return (1);
	}
	else
		return (append_line(lst, ret, buf, output));
}

char	*get_next_line(int fd)
{
	char			*ret;
	static t_list	*lst;
	t_list			*lst_fd;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	if (!lst)
	{
		lst = ft_lstnew(-1);
		if (!lst)
			return (NULL);
	}
	lst_fd = check_lst_storage(lst, &ret, fd);
	if (!(lst_fd))
	{
		all_free(&lst, &ret);
		return (NULL);
	}
	while (check_ret(&ret, &lst, &lst_fd, &temp))
	{
		if (get_char(&ret, &lst_fd, fd, &lst))
			break ;
	}
	return (ret);
}
