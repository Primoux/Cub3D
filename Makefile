#-------------------------------- VARIABLES --------------------------------#

NAME		=	cub3D
CC		 	=	cc
CFLAGS		=	-Wall -Wextra -Werror

#-------------------------------- DIRECTORIES --------------------------------#

LIBFT_DIR		=	lib/libft
LIBMLX_DIR		=	lib/libx

INCLUDE_DIR		=	inc

SRC_DIR			=	src/
OBJ_DIR			=	.build/

#-------------------------------- INCLUDES & FLAGS --------------------------------#

INCLUDES	=	-I $(INCLUDE_DIR) \
				-I ./lib/libft/includes \
				-I $(LIBMLX_DIR)

LDFLAGS		=	-L$(LIBMLX_DIR) -lmlx \
				-lXext -lX11 -lm

#-------------------------------- LIBRARIES --------------------------------#

LIBFT		=	$(LIBFT_DIR)/libft.a
MLX			=	$(LIBMLX_DIR)/libmlx.a

#-------------------------------- SOURCE FILES --------------------------------#

SRCS		=	src/main.c

#-------------------------------- OBJECTS --------------------------------------#

OBJS			=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
DEPENDENCIES	=	$(OBJS:.o=.d)

#-------------------------------- RULES --------------------------------#


all: $(NAME)

$(LIBFT): libft

$(MLX): mlx

mlx :
	@$(MAKE) --silent -C $(LIBMLX_DIR) 

libft:
	@$(MAKE) --silent -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)  $(LIBFT) $(LDFLAGS)


$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) --silent -C $(LIBFT_DIR) clean

fclean:
	$(MAKE) -C $(LIBMLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)


re: fclean
	@$(MAKE) --silent all

print-%:
	@echo $($(patsubst print-%,%,$@))

-include $(DEPENDENCIES)

.PHONY: all clean fclean re libft mlx print-%