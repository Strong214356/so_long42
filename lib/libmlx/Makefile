INC	=./

UNAME = $(shell uname)
CC	= gcc
ifeq ($(UNAME),FreeBSD)
	CC = clang
endif

NAME		= libmlx.a

SRC	= mlx_init.c mlx_new_window.c mlx_pixel_put.c mlx_loop.c \
	mlx_mouse_hook.c mlx_key_hook.c mlx_expose_hook.c mlx_loop_hook.c \
	mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
	mlx_int_wait_first_expose.c mlx_int_get_visual.c \
	mlx_flush_event.c mlx_string_put.c mlx_set_font.c \
	mlx_new_image.c mlx_get_data_addr.c \
	mlx_put_image_to_window.c mlx_get_color_value.c mlx_clear_window.c \
	mlx_xpm.c mlx_int_str_to_wordtab.c mlx_destroy_window.c \
	mlx_int_param_event.c mlx_int_set_win_event_mask.c mlx_hook.c \
	mlx_rgb.c mlx_destroy_image.c mlx_mouse.c mlx_screen_size.c \
	mlx_destroy_display.c

OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
CFLAGS	= -O3 -I$(INC)

all	: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "mlx compiled !!"

clean:
	@rm -rf $(OBJ_DIR)/
	@echo "mlx clean"

fclean: clean
	@rm -rf $(NAME)
	@echo "mlx fclean"

re: fclean all

.PHONY: all clean fclean re
