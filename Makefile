CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -I 42_libft
RM					=	rm -f
NAME				=	push_swap
 
# Libraries
LIBFT_FILE			=	42_libft/libft.a
LDFLAGS     		=	-L 42_libft -l ft
MAKE_LIB			=	make -C
 
STACK_SRC_DIR		=	srcs/stack
PUSH_SWAP_SRC_DIR	=	srcs/push_swap
VALIDATION_SRC_DIR	=	srcs/validation
 
STACK_SRC			=	$(STACK_SRC_DIR)/stack_init.c \
						$(STACK_SRC_DIR)/stack_init_helper.c \
						$(STACK_SRC_DIR)/stack_utils.c \
						$(STACK_SRC_DIR)/operations/push.c \
						$(STACK_SRC_DIR)/operations/swap.c \
						$(STACK_SRC_DIR)/operations/rotate.c \
						$(STACK_SRC_DIR)/operations/r_rotate.c 
 
VALIDATION_SRC		=	$(VALIDATION_SRC_DIR)/validation_main.c \
						$(VALIDATION_SRC_DIR)/validation_numbers.c \
						$(VALIDATION_SRC_DIR)/validation_duplicates.c \
						$(VALIDATION_SRC_DIR)/string_parsing.c \
						$(VALIDATION_SRC_DIR)/validation_quoted.c \
						$(VALIDATION_SRC_DIR)/validation_limits.c \
						$(VALIDATION_SRC_DIR)/error_handling.c
 
PS_SRC				=	$(PUSH_SWAP_SRC_DIR)/default_sorts.c
 
PUSH_SWAP_SRC		=	main.c #\
						#$(STACK_SRC) \
						#$(VALIDATION_SRC) \
						#$(PS_SRC) 
 
LIB					=	$(LIBFT_FILE)
PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)

all:				$(NAME)
 
#bonus:				$(CHECKER)
 
obj:

$(PUSH_SWAP_OBJ):	obj/push_swap/%.o: %.c
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@
 
$(LIBFT_FILE):
					$(MAKE_LIB) 42_libft
 
$(NAME):			$(LIB) $(PUSH_SWAP_OBJ)
					$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LDFLAGS) -o $@
 
lib_clean:
					$(MAKE_LIB) 42_libft clean
 
lib_fclean:
					$(MAKE_LIB) 42_libft fclean
 
clean:				lib_clean
					rm -rf obj
 
fclean:				clean lib_fclean
					$(RM) $(NAME)
 
re:					fclean all
 
.PHONY:				all bonus lib_clean lib_fclean clean fclean re
