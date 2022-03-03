/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:32:45 by gbreana           #+#    #+#             */
/*   Updated: 2021/11/10 20:30:34 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
/*
 * Includes
 */
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

/*
 * Macroses
 */
# define LLONGMAX 		9223372036854775807ull

/*
 * Structs
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
 * Part 1 Functions
 */
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	**ft_split(char const *str, char c);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int num, int fd);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
 * For ft_printf
 */
int	ft_printf(const char *format, ...);
static int	ft_parser(const char *str, va_list args);
static int	ft_type_handler(int c, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int num);
int	ft_puthex(unsigned long num, int c);
int	ft_putptr(uintptr_t num);
int	ft_putunbr(unsigned int num);
int	ft_strchri(const char *str, int c);

#endif