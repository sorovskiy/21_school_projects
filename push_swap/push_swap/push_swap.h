/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:51:13 by                   #+#    #+#             */
/*   Updated: 2021/12/13 09:53:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_values
{
	int	upwards;
	int	downwards;
	int	value;
}	t_values;

int		ft_atoi(char *str);
void	ft_push(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_pop(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
int		ft_swap(t_list **lst);
int		ft_rotate(t_list **lst);
int		ft_reverse_rotate(t_list **lst);
void	swap_a(t_list **lst);
void	swap_b(t_list **lst);
void	swap_swap(t_list **lst_a, t_list **lst_b);
void	rotate_a(t_list **lst_a);
void	rotate_b(t_list **lst_a);
void	rotate_rotate(t_list **lst_a, t_list **lst_b);
void	reverse_rotate_a(t_list **lst);
void	reverse_rotate_b(t_list **lst);
void	reverse_rotate_rotate(t_list **lst_a, t_list **lst_b);
void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_a, t_list **lst_b);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	sort_stack_b(t_list **stack_b, t_list **stack_a, t_values val);
void	bulka_sort(t_list **stack_a, t_list **stack_b, const int n, int left);
void	rotate_max_elem_up(t_list **stack_b, int size, int i);
void	sort_for_3(t_list **stack);
void	sort_for_5(t_list **stack_a, t_list **stack_b, int size);
void	show_error_and_exit(void);
void	rotate(t_list **stack_a, t_list **stack_b, int position, t_values vals);
int		check_sorting(t_list **stack1);

#endif //PUSH_SWAP_H
