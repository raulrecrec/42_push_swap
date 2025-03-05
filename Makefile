# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 17:38:10 by rexposit          #+#    #+#              #
#    Updated: 2025/03/05 18:48:55 by rexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = push_swap

# Directorios de librerías
LIBFT_DIR = 42_libft
PRINTF_DIR = 42_ft_printf

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Archivos fuente de push_swap
SRCS = push_swap.c

# Convertimos los archivos .c en .o
OBJS = $(SRCS:.c=.o)

# Archivos de librerías
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# Regla principal (compila el ejecutable)
all: $(NAME)

# Compilar push_swap
$(NAME): $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)
	@echo "Compilación completada: $(NAME)"

# Compilar libft y ft_printf si es necesario
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

# Regla para compilar archivos .c en .o de push_swap
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compilado: $<"

# Eliminar archivos .o
clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@rm -f $(OBJS)
	@echo "Archivos objeto eliminados."

# Eliminar el ejecutable y los archivos objeto
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@rm -f $(NAME)
	@echo "Ejecutable eliminado."

# Recompilar desde cero
re: fclean all