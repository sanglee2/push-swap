/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:40:43 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/20 07:31:17 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	struct s_node *prev;
	int	content;
	int index;
	struct s_node *next;
} t_node;

typedef struct s_deq
{
	int *arr;
	t_node *a_top;
	int a_size;
	t_node *a_bot;
	t_node *b_top;
	int b_size;
	t_node *b_bot;
} t_deq;

// typedef struct s_deq
// {
// 	t_node *top;
// 	int size;
// 	t_node *bot;
// } t_deq;

int ft_abs(int num);
int check_sort(t_deq *deq);
int get_a_loc(t_deq* deq_a, int b_content);
int get_b_loc(t_deq *deq_b, int b_content);
void push_top_b(t_deq *deq, t_node *node);
void push_top_a(t_deq *deq, t_node *node);
void push_bot_a(t_deq *deq_a, t_node *node);
void push_bot_b(t_deq *deq_b, t_node *node);
t_node*	pop_top(t_deq *deq);
t_node* pop_bot(t_deq *deq);
void pa(t_deq *deq_a, t_deq *deq_b); 
void pb(t_deq *deq_a, t_deq *deq_b);
void sa(t_deq *deq_a);
void sb(t_deq *deq_b);
void ss(t_deq *deq_a, t_deq *deq_b);
void ra(t_deq *deq_a);
void rra(t_deq *deq_a);
void rb(t_deq *deq_b);
void rrb(t_deq *deq_a);
void rr(t_deq *deq_a, t_deq *deq_b);
void rrr(t_deq *deq_a, t_deq *deq_b);
int get_max_value(t_deq *deq);
int get_min_value(t_deq *deq);
void sort_two_element_a(t_deq *deq_a);
void sort_two_element_b(t_deq *deq_b);
void sort_three_element(t_deq* deq_a);
void sort_four_element(t_deq* deq_a, t_deq* deq_b);
void sort_five_element(t_deq* deq_a, t_deq* deq_b);
int find_max_idx(t_deq *deq);
void content_trans_idx(t_deq *deq);
t_deq* create();
void init_deq(t_deq *deq);
int is_empty(t_deq* deq);
t_node* init_node(int arg);
//t_deq *configuration_deq(int ac, char *av[]);
void pre_setting_deque(t_deq *deq_a, t_deq *deq_b);
void last_setting_deque(t_deq* deq_a);
int get_deq_a_size(t_deq *deq_a);
int get_deq_b_size(t_deq *deq_b);
void    sort(t_deq *deq_a, t_deq *deq_b);
void deq_print(t_deq* deq);
int find_min_loc(t_deq* deq);
void act_sort(t_deq *deq_a, t_deq *deq_b, int a_rot, int b_rot);
void get_rot_count(t_deq* deq_a, t_deq* deq_b);
void iterate_ra(t_deq* deq_a, int a_loc);
void iterate_rra(t_deq* deq_a, int a_loc);
void iterate_rb(t_deq* deq_b, int b_loc);
void iterate_rrb(t_deq* deq_b, int b_loc);

#endif
