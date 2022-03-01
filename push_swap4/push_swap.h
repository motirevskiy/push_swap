/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:46:48 by truthe            #+#    #+#             */
/*   Updated: 2022/03/01 18:10:35 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct k_list
{
	int				content;
	int				index;
	int				flag;
	struct k_list	*next;
}					t_list;

typedef struct stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		next;
}			t_stacks;

//libft
int		ft_atoi(char *str);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	list_delete(t_list *list);
t_list	*ft_last_list(t_list *stack);
char	**ft_split(char const *s, char c);
void	print_stacks(t_list *a, t_list *b);
t_list	*ft_lstlast(t_list *lst, t_list *new);
int		ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strncmp(const char *string1, const char *string2, size_t num);

//check
void	error(void);
int		ft_isdigit(char c);
int		check_next(t_stacks *s);
int		ft_validation(char *argv);

//comand
void	ft_sa(t_list **stack_a, int flag);
void	ft_sb(t_list **stack_b, int flag);
void	ft_ss(t_list **a, t_list	**b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a, int flag);
void	ft_rb(t_list **stack_b, int flag);
void	ft_rr(t_list **stack_b, t_list **stack_a);
void	ft_rra(t_list **stack_a, int flag);
void	ft_rrb(t_list **stack_b, int flag);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
t_list	*argv_add_to_list(int argc, char **argv);

//sort
void	ft_sort_five(t_stacks *s);
void	sort_stack(t_stacks *s);
void	ft_sort_three(t_stacks *s);
t_list	*sort_check(t_list *lst);
void	small_sort(t_stacks *s);
t_list	*make_index(t_list *lst, t_list *new);
#endif
