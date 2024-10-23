/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:52:08 by allan             #+#    #+#             */
/*   Updated: 2024/10/22 21:35:12 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR 1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define VALID 0
# define NOT_VALID 1
# define DIGIT 2048
# define NOT_DIGIT 0

# define ERR_USEC "Error: Usex Paremeter is <= 0\n"
# define ERR_GET_TIME "Error: Get Time Initialisation Failed\n"
# define ERR_TIME_UNIT "Error: Wrong Type Unit Entered\n"
# define ERROR_MALLOC "Error: Malloc Initialisation Failed\n"

/* typedef enum e_type
{
	BOOL,
	S_CHAR,
	U_CHAR,
	S_SHORT,
	U_SHORT,
	S_INT,
	U_INT,
	S_LONG,
	U_LONG,
	S_LONG_LONG,
	U_LONG_LONG,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE
}	t_type; */

typedef enum e_time_unit
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_unit;

//singleton_struct
typedef enum	e_ptr_types
{
	SINGLE_PTR,
	DOUBLE_PTR
}				t_ptr_types;

typedef struct	s_node
{
	void				*data;
	t_ptr_types				type;
	struct s_node		*next;
}				t_node;

typedef struct	s_singleton
{
	t_node	*head;
}				t_singleton;
//

long			ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*get_next_word(char *str, char sep);
int				count_word(char *str, char sep);
void			ft_free(char **split);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char *s1, char const *s2);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *source, unsigned int start, size_t len);
int				ft_tolower(int ch);
int				ft_toupper(int ch);

//handle_error
void			error_msg(char *error);

//free
void			free_array(char **array);

//mutex_set_get
void			set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool			get_bool(pthread_mutex_t *mutex, bool *value);
void			set_char(pthread_mutex_t *mutex, char *dest, char value);
char			get_char(pthread_mutex_t *mutex, char *value);
void			set_u_char(pthread_mutex_t *mutex,
					unsigned char *dest, unsigned char value);
unsigned char	get_u_char(pthread_mutex_t *mutex, unsigned char *value);
void			set_short(pthread_mutex_t *mutex, short *dest, short value);
short			get_short(pthread_mutex_t *mutex, short *value);
void			set_u_short(pthread_mutex_t *mutex,
					unsigned short *dest, unsigned short value);
unsigned short	get_u_short(pthread_mutex_t *mutex, unsigned short *value);
void			set_int(pthread_mutex_t *mutex, int *dest, int value);
int				get_int(pthread_mutex_t *mutex, int *value);
void			set_u_int(pthread_mutex_t *mutex,
					unsigned int *dest, unsigned int value);
unsigned int	get_u_int(pthread_mutex_t *mutex, unsigned int *value);
void			set_long(pthread_mutex_t *mutex, long *dest, long value);
long			get_long(pthread_mutex_t *mutex, long *value);
void			set_u_long(pthread_mutex_t *mutex,
					unsigned long *dest, unsigned long value);
unsigned long	get_u_long(pthread_mutex_t *mutex, unsigned long *value);

//time
long			get_elapsed_time_microseconds(struct timeval start,
					struct timeval end);
int				ft_usleep(long usec);
long			get_time(t_time_unit time_unit);
long			print_time(long start);

//singleton
t_singleton 	*get_singleton_list();
bool			add_singleton_data(void *data, t_ptr_types data_type);
bool			free_singleton_list();
void			free_singleton_data(t_node *current);

#endif
