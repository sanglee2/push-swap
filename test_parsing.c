/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:34:25 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/23 21:52:21 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void deq_print(t_deq* deq)
{
	//index에 관한 한 것
	t_node	*curr;

	curr = deq->a_top;
	while (curr)
	{
		printf("a_top data : %d\n", curr->content);
		curr = curr->next;
	}

	/*curr = deq->a_bot;
	while (curr)
	
		printf("a_bot data : %d\n", curr->content);
		curr = curr->prev;
	}*/
	curr = deq->b_top;
	while (curr)
	{
		printf("b_top data : %d\n", curr->content);
		curr = curr->next;
	}
	/*int i;
	i = 0;
	while (i < deq->arr_size)
	{
		printf("arr[%d] = %d\n", i, deq->arr[i]);
		i++;
	}*/
}


int main(int ac, char **av)
{
	// deq 구조체를 담는 변수 a, b 인스턴스화
    // 어떤 자료구조 유리한지 - 선택이유
    t_deq* deq_a;
    t_deq* deq_b;

    // argument 유효성 체크 부분
    if (ac < 2)
        ft_error();
	deq_a = parse(ac,av,1);	
    deq_b = NULL;

	if(check_duplicate_arg(deq_a) == 1)
	{
		ft_free_deq_a(deq_a);
		ft_error();
	}
    // // deq_a의 크기 구하기 <- 정렬 전.
    // deq_a->a_size = ft_deq_size(deq_a);
	
	// // 이미 정렬이 되어있는지 아닌지 확인작업을 하는 부분.

    // // 정렬알고리즘 사용 정렬부분.
    // sort(deq_a, deq_b);

    // // deq을 free해주는 함수 - 동적메모리할당 했기 때문에 <- 논리적 이유.
    // free_deq(deq_a);
    // free_deq(deq_b);

	deq_print(deq_a);

    return (0);
}