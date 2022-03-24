/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:29:47 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:55:36 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "../libraries/Libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define PRINT_SORT 1

typedef struct s_list
{
	struct s_info	*content;
	struct s_list	*next;
}	t_list;

typedef struct s_info {
	int				value;
	int				index;
	int				tag_keep;
	struct s_list	*next_ordered;
}	t_info;

typedef struct s_content {
	struct s_list	*stack_a;
	struct s_list	*stack_b;
	struct s_list	*stack_a_ref;
	int				biggest_sequence;
	int				length;
	int				total_nb;
	int				groups;
	int				groups_len;
	int				is_string_params;
}	t_content;

//check_args.c =============================================================

/**
 * @brief Check the arguments to see if they are 
 * inside the accepted parameters
 * 
 * @param argc The numbers of arguments received 
 * @param argv The arguments received
 * @param content The content that will be used to sort the two stacks
 */
void	check_args(int argc, char **argv, t_content *content);

//error_clean.c =============================================================

/**
 * @brief 
 * 
 * @param content 
 */
void	clean(t_content *content);
/**
 * @brief 
 * 
 * @param content 
 */
void	error(t_content *content);
/**
 * @brief 
 * 
 * @param content 
 * @param inf 
 * @param argv 
 * @param i 
 */
void	validation_error(t_content *content, t_info *inf, char **argv, int i);

//utils_01.c =============================================================

/**
 * @brief 
 * 
 * @param content 
 * @param argv 
 * @param inf 
 * @param i 
 * @return int 
 */
int		atoi_safe(t_content *content, char **argv, t_info *inf, int i);
/**
 * @brief 
 * 
 * @param nb_1 
 * @param nb_2 
 * @return int 
 */
int		max(int nb_1, int nb_2);
/**
 * @brief 
 * 
 * @param nb_1 
 * @param nb_2 
 * @return int 
 */
int		min(int nb_1, int nb_2);
/**
 * @brief 
 * 
 * @param nb 
 * @return int 
 */
int		abs(int nb);

//sequence&content_info.c ==================================================

/**
 * @brief Checks if the stack passed is already a sequence
 * 
 * @param list_a the stack passed to check
 * @return 1 If the stack is sequence, 0 if not
 */
int		is_sequence(t_list *list_a);
/**
 * @brief
 * 
 * @param content 
 */
void	set_content_info(t_content *content);
/**
 * @brief 
 * 
 * @param start 
 * @param tag 
 * @return int 
 */
int		biggest_seq_tag(t_list *start, int tag);

//index_manager.c =============================================================

/**
 * @brief Finds and counts the index of the list passed to help sorting
 * 
 * @param list_init The list passed
 */
void	ft_index(t_list *list_init);

//start_sorting.c =============================================================

/**
 * @brief Starts the sorting process
 * 
 * @param content Content of both stacks
 */
void	sorting(t_content *content);

//utils__sort_01.c =============================================================

/**
 * @brief Get the closest group object
 * 
 * @param list 
 * @param actual_group 
 * @param group_total 
 * @return t_list* 
 */
t_list	*get_closest_group(t_list *list, int actual_group, int group_total);
/**
 * @brief Set the rotation object
 * 
 * @param cont Content of both stacks
 * @param max_dist Max size of numbers in stacks.
 * @param a_rot Define the rotation of stack A
 * @param b_rot Define the rotation of stack B
 */
void	set_rotation(t_content *cont, int max_dist, int *a_rot, int *b_rot);
/**
 * @brief Calculates the distance to the index of the list
 * 
 * @param list List used to calculate
 * @param index Index to be used
 * @return The distance to the index
 */
int		distance_to_index(t_list *list, int index);

//utils__sort_02.c =============================================================

/**
 * @brief Rotates the stacks acording to parameters passed
 * 
 * @param content Content of both stacks
 * @param a_rot How much and in which direction to rotate stack A
 * @param b_rot How much and in which direction to rotate stack B
 */
void	rotate(t_content *content, int a_rot, int b_rot);

//utils__sort_03.c =============================================================

/**
 * @brief Swap the first two elements of a stack
 * 
 * @param init_ref The stack to swap
 */
void	swap(t_list **init_ref);
/**
 * @brief Take the first element from the top of a stack and 
 * put on top of another stack
 * 
 * @param init_ref_1 The stack to push the element from
 * @param init_ref_2 The stack to push the element to
 */
void	push_top(t_list **init_ref_1, t_list **init_ref_2);
/**
 * @brief Shift up all elements of the stack by one.
 * The first element becomes the last one.
 * 
 * @param init_ref The stack to rotate
 */
void	shift_up(t_list **init_ref);
/**
 * @brief Shift down all elements of the stack by one.
 * The last element becomes the first one.
 * 
 * @param init_ref The stack to reverse rotate
 */
void	shift_down(t_list **init_ref);

//sort_operation_p_.c ==========================================================

/**
 * @brief Pushes the top of stack B and put onto the top of A
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	pa(t_content *content, int print);
/**
 * @brief Pushes the top of stack A and put onto the top of B
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	pb(t_content *content, int print);

//sort_operation_s_.c ==========================================================

/**
 * @brief Swap the first two elements of stack A
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	sa(t_content *content, int print);
/**
 * @brief Swap the first two elements of stack B
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	sb(t_content *content, int print);
/**
 * @brief Swap the first two elements of stack A and of stack B
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	ss(t_content *content, int print);

//sort_operation_r_.c ==========================================================

/**
 * @brief Rotates the elements of stack A. 
 * Shifts up the stack
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	ra(t_content *content, int print);
/**
 * @brief Rotates the elements of stack B. 
 * Shifts up the stack
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	rb(t_content *content, int print);
/**
 * @brief Rotates the elements of stack A and stack B. 
 * Shifts up the stacks
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	rr(t_content *content, int print);

//sort_operation_rr_.c =========================================================

/**
 * @brief Reverse rotates the elements of stack A. 
 * Shifts down the stack
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	rra(t_content *content, int print);
/**
 * @brief Reverse rotates the elements of stack B. 
 * Shifts down the stack
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	rrb(t_content *content, int print);
/**
 * @brief Reverse rotates the elements of stack B and stack A. 
 * Shifts down the stacks
 * 
 * @param content Content of both stacks
 * @param print If prints operation
 */
void	rrr(t_content *content, int print);

//utils_lists_01.c =============================================================

/**
 * @brief Adds the element ’new’ at the end of the list
 * 
 * @param lst The address of a pointer to the first link of a list
 * @param new The address of a pointer to the element to be added to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Adds the element ’new’ at the beginning of the list.
 * 
 * @param lst The address of a pointer to the first link of a list
 * @param new The address of a pointer to the element to be added to the list
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Deletes and frees the given element and every 
 * successor of that element, using the function ’del’ and free(3). 
 * Finally, the pointer to the list must be set to NULL.
 * 
 * @param lst The adress of a pointer to an element
 * @param del The adress of the function used to 
 * delete the content of the element
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));
/**
 * @brief Takes as a parameter an element and frees the 
 * memory of the element’s content using the function 
 * ’del’ given as a parameter and free the element. 
 * The memory of ’next’ must not be freed
 * 
 * @param lst The element to free
 * @param del The address of the function used to delete the content
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));
/**
 * @brief Iterates the list ’lst’ and applies the function 
 * ’f’ to the content of each element
 * 
 * @param lst The adress of a pointer to an element
 * @param f The adress of the function used to iterate on the list
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

//utils_lists_02.c =============================================================

/**
 * @brief Returns the last element of the list
 * 
 * @param lst The beginning of the list
 * @return Last element of the list
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief Iterates the list ’lst’ and applies the function 
 * ’f’ to the content of each element. Creates a new 
 * list resulting of the successive applications of 
 * the function ’f’. The ’del’ function is used to 
 * delete the content of an element if needed.
 * 
 * @param lst The adress of a pointer to an element
 * @param f The adress of the function used to iterate on the list
 * @param del The adress of the function used to delete 
 * the content of an element if needed
 * @return The new list. NULL if the allocation fails
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/**
 * @brief Allocates (with malloc(3)) and returns a new 
 * element. The variable ’content’ is initialized
 * with the value of the parameter ’content’. The
 * variable ’next’ is initialized to NULL.
 * 
 * @param content The content to create the new element with
 * @return The new element 
 */
t_list	*ft_lstnew(void *content);
/**
 * @brief Counts the number of elements in a list
 * 
 * @param lst The beginning of the list
 * @return Length of the list
 */
int		ft_lstsize(t_list *lst);
#endif