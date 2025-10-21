#-------------------------------- VARIABLES --------------------------------#

NAME		=	cub3D
CC		 	=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
DEPS		=	-MMD -MP

#-------------------------------- DIRECTORIES --------------------------------#

LIBFT_DIR		=	lib/libft
LIBMLX_DIR		=	lib/libx

INCLUDE_DIR		=	inc/

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

MAIN_SRCS		:=	main.c \

INIT_SRCS		:=	init/init.c \
					init/init_base.c \
					init/init_player.c \
					init/init_map.c \
					init/init_texture.c \
					init/init_ray.c \
					init/init_img.c \
					init/init_keys.c \
					init/init_mlx.c

PARSING_SRCS	:=	parsing/parsing.c \
					parsing/check_name.c \
					parsing/read_and_fill_map_informations.c \
					parsing/read_params.c	\
					parsing/read_map.c	\
					parsing/check_map_validity.c	\
					parsing/char_compare.c	\
					parsing/color.c	\

MLX_SRCS		:=	mlx/mlx_handler.c \
					mlx/hook_keys.c \
					mlx/my_mlx_put_pixel.c

UTILS_SRCS		:=	utils/free_all.c \
					utils/print_map.c

EXEC_SRCS		:=	exec/minimap.c \
					exec/check_n_correct.c \
					exec/raycast.c \
					exec/movement.c \
					exec/print_texture.c

ERROR_SRCS		:=	error/print_error_asset.c \

SRCS			:=	$(addprefix $(SRC_DIR), \
					$(MAIN_SRCS) \
					$(INIT_SRCS) \
					$(PARSING_SRCS) \
					$(EXEC_SRCS) \
					$(MLX_SRCS) \
					$(UTILS_SRCS) \
					$(ERROR_SRCS) \
)

#-------------------------------- OBJECTS --------------------------------------#

OBJS			=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
DEPENDENCIES	=	$(OBJS:.o=.d)

#-------------------------------- RULES --------------------------------#


all: $(NAME)

$(LIBFT): libft

$(MLX): mlx

mlx :
	$(MAKE) -C $(LIBMLX_DIR) 

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)  $(LIBFT) $(LDFLAGS)


$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEPS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) --silent -C $(LIBFT_DIR) clean

fclean:
	$(MAKE) -C $(LIBMLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)


re: fclean
	$(MAKE) -j all

print-%:
	@echo $($(patsubst print-%,%,$@))

-include $(DEPENDENCIES)

.PHONY: all clean fclean re libft mlx print-%
