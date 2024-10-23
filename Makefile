# Standard
NAME			= libft.a

# Directories
INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

# Compielr and Flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I
RM				= rm -f
AR				= ar rcs

# Source Files
LIBFT_DIR		=	$(SRC_DIR)ft_libft/singleton/singleton.c \
					$(SRC_DIR)ft_libft/free/free_array.c \
					$(SRC_DIR)ft_libft/handle_error/error_msg.c \
					$(SRC_DIR)ft_libft/mutex_set_get/ft_set_get_bool.c \
					$(SRC_DIR)ft_libft/mutex_set_get/ft_set_get_char.c \
					$(SRC_DIR)ft_libft/mutex_set_get/ft_set_get_short.c \
					$(SRC_DIR)ft_libft/mutex_set_get/ft_set_get_int.c \
					$(SRC_DIR)ft_libft/mutex_set_get/ft_set_get_long.c \
					$(SRC_DIR)ft_libft/time/ft_time.c \
					$(SRC_DIR)ft_libft/ft_atoi.c \
					$(SRC_DIR)ft_libft/ft_bzero.c \
					$(SRC_DIR)ft_libft/ft_calloc.c \
					$(SRC_DIR)ft_libft/ft_isalnum.c \
					$(SRC_DIR)ft_libft/ft_isalpha.c \
					$(SRC_DIR)ft_libft/ft_isascii.c \
					$(SRC_DIR)ft_libft/ft_isdigit.c \
					$(SRC_DIR)ft_libft/ft_isprint.c \
					$(SRC_DIR)ft_libft/ft_itoa.c \
					$(SRC_DIR)ft_libft/ft_memchr.c \
					$(SRC_DIR)ft_libft/ft_memcmp.c \
					$(SRC_DIR)ft_libft/ft_memcpy.c \
					$(SRC_DIR)ft_libft/ft_memmove.c \
					$(SRC_DIR)ft_libft/ft_memset.c \
					$(SRC_DIR)ft_libft/ft_putchar_fd.c \
					$(SRC_DIR)ft_libft/ft_putendl_fd.c \
					$(SRC_DIR)ft_libft/ft_putnbr_fd.c \
					$(SRC_DIR)ft_libft/ft_split.c \
					$(SRC_DIR)ft_libft/ft_strchr.c \
					$(SRC_DIR)ft_libft/ft_strdup.c \
					$(SRC_DIR)ft_libft/ft_striteri.c \
					$(SRC_DIR)ft_libft/ft_strjoin.c \
					$(SRC_DIR)ft_libft/ft_strlcat.c \
					$(SRC_DIR)ft_libft/ft_strlcpy.c \
					$(SRC_DIR)ft_libft/ft_strlen.c \
					$(SRC_DIR)ft_libft/ft_strmapi.c \
					$(SRC_DIR)ft_libft/ft_strncmp.c \
					$(SRC_DIR)ft_libft/ft_strnstr.c \
					$(SRC_DIR)ft_libft/ft_strrchr.c \
					$(SRC_DIR)ft_libft/ft_strtrim.c \
					$(SRC_DIR)ft_libft/ft_substr.c \
					$(SRC_DIR)ft_libft/ft_tolower.c \
					$(SRC_DIR)ft_libft/ft_toupper.c

PRINTF_DIR		=	$(SRC_DIR)ft_printf/ft_printf.c \
					$(SRC_DIR)ft_printf/ft_printf_char.c \
					$(SRC_DIR)ft_printf/ft_printf_int.c \
					$(SRC_DIR)ft_printf/ft_printf_len_int.c \

GNL_DIR		=	$(SRC_DIR)get_next_line/get_next_line.c \
					$(SRC_DIR)get_next_line/get_next_line_utils.c

# Concatenate all source files
SRC 			= $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

# Build rules
all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)
				@$(RM) .cache_exists

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re
