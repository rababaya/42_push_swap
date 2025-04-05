CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	rm -f
PUSH_SWAP			=	push_swap
NAME				=	$(PUSH_SWAP)
 
# Libraries
LIBFT				=	libft.a
LIBFT_NAME			=	ft
LIBFT_DIR			=	libs/libft
LIBFT_FILE			=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I $(LIBFT_DIR)/include -I includes
 
LDFLAGS     		=	-L$(LIBFT_DIR) -l$(LIBFT_NAME)
 
MAKE_LIB			=	make -C
 
STACK_SRC_DIR		=	srcs/stack
PUSH_SWAP_SRC_DIR	=	srcs/push_swap
VALIDATION_SRC_DIR	=	srcs/validation
STACK_INC			=	includes/stack.h #headerner@ ara
PUSH_SWAP_INC		=	$(STACK_INC) includes/push_swap.h
 
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
 
PUSH_SWAP_SRC		=	main.c \
						$(STACK_SRC) \
						$(VALIDATION_SRC) \
						$(PS_SRC)
 
all:				$(PUSH_SWAP)
 
#bonus:				$(CHECKER)
 
obj:
					mkdir -p obj
 
LIB					=	$(LIBFT_FILE)
PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)
 
$(PUSH_SWAP_OBJ):	obj/push_swap/%.o: %.c
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@
 
$(LIBFT_FILE):
					$(MAKE_LIB) $(LIBFT_DIR)
 
$(PUSH_SWAP):		$(LIB) $(PUSH_SWAP_OBJ)
					$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LDFLAGS) -o $@
 
lib_clean:
					$(MAKE_LIB) $(LIBFT_DIR) clean
 
lib_fclean:
					$(MAKE_LIB) $(LIBFT_DIR) fclean
 
clean:				lib_clean
					rm -rf obj
 
fclean:				clean lib_fclean
					$(RM) $(NAME)
 
re:					fclean all
 
.PHONY:				all bonus lib_clean lib_fclean clean fclean re
