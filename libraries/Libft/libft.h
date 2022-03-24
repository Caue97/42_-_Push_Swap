/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:24:09 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/06 13:30:00 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int			ft_isalnum(int verify);
int			ft_isalpha(int receive);
int			ft_isascii(int verify);
int			ft_isdigit(int receive);
int			ft_isprint(int verify);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
int			ft_atoi(const char *to_convert);
int			ft_memcmp(const void *bf_01, const void *bf_02, size_t c_size);
int			ft_strncmp(const char *str_1, const char *str_2, size_t n_comp);
void		*ft_memcpy(char *copy, const void *original, size_t length);
void		*ft_memmove(char *move, char *original, size_t length);
void		*ft_memset(void *memory, int value, size_t length);
void		*ft_memchr(const void *where_s, int what_s, size_t length_s);
void		ft_bzero(void *memory, size_t length);
void		*ft_calloc(size_t n_locate, size_t n_array_size);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strchr(const char *strin, int char_search);
char		*ft_strnstr(const char *l_txt, const char *see_th, size_t serc_len);
char		*ft_strrchr(char *strin, int search);
char		*ft_strdup(const char *strin_g);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcat(char *contat, const char *original, size_t size);
size_t		ft_strlcpy(char *copy, const char *original, size_t size);
size_t		ft_strlen(const char *str);

#endif