# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 17:38:10 by rexposit          #+#    #+#              #
#    Updated: 2025/03/05 17:55:58 by rexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = push_swap

# Compilador y flags
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I./42_ft_printf

# Archivos fuente de push_swap
SRCS	= push_swap.c

# Convertimos los archivos .c en .o
OBJS	= $(SRCS:.c=.o)

# Directorio de ft_printf
PRINTF_DIR = 42_ft_printf

# Regla principal (compila el ejecutable)
all: $(NAME)

# Compilar push_swap
$(NAME): $(OBJS)
		@make -C $(PRINTF_DIR)
		@$(CC) $(CFLAGS) $(OBJS) $(PRINTF_DIR)/libftprintf.a -o $(NAME)
		@echo "Compilación completada: $(NAME)"

# Regla para compilar archivos .c en .o de push_swap
%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compilado: $<"

# Eliminar archivos .o
clean:
		@make clean -C $(PRINTF_DIR)
		@rm -f $(OBJS)
		@echo "Archivos objeto eliminados."

# Eliminar el ejecutable y los archivos objeto
fclean: clean
		@make fclean -C $(PRINTF_DIR)
		@rm -f $(NAME)
		@echo "Ejecutable eliminado."

# Recompilar desde cero
re: fclean all