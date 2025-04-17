CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -I 42_libft -I includes
RM					=	rm -f
NAME				=	push_swap
 
# Libraries
LIBFT_FILE			=	42_libft/libft.a
LDFLAGS     		=	-L 42_libft -l ft
MAKE_LIB			=	make -C
 
LIST_SRC_DIR		=	list_operations
STACK_SRC_DIR		=	stack_operations
BASIC_SORT_SRC_DIR	=	basic_sorts
VALIDATION_SRC_DIR	=	validation
 
LIST_SRC			=	$(LIST_SRC_DIR)/ft_stackadd_back.c \
						$(LIST_SRC_DIR)/ft_stackclear.c \
						$(LIST_SRC_DIR)/ft_stackiter.c \
						$(LIST_SRC_DIR)/ft_stackmap.c \
						$(LIST_SRC_DIR)/ft_stacksize.c \
						$(LIST_SRC_DIR)/ft_stackadd_front.c \
						$(LIST_SRC_DIR)/ft_stackdelone.c \
						$(LIST_SRC_DIR)/ft_stacklast.c \
						$(LIST_SRC_DIR)/ft_stacknew.c

STACK_SRC			=	$(STACK_SRC_DIR)/swap.c \
						$(STACK_SRC_DIR)/push.c \
						$(STACK_SRC_DIR)/rotate.c \
						$(STACK_SRC_DIR)/r_rotate.c

BASIC_SORT_SRC		=	$(BASIC_SORT_SRC_DIR)/manual_sorting.c

VALIDATION_SRC		=	$(VALIDATION_SRC_DIR)/join_split.c \
						$(VALIDATION_SRC_DIR)/validation.c
 
PS_SRC				=	sorting.c
 
PUSH_SWAP_SRC		=	main.c \
						$(LIST_SRC) \
						$(STACK_SRC) \
						$(PS_SRC) \
						$(BASIC_SORT_SRC) \
						$(VALIDATION_SRC) 
 
PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)

all:				$(NAME)
 
#bonus:				$(CHECKER)
 
obj:

$(PUSH_SWAP_OBJ):	obj/push_swap/%.o: %.c
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@
 
$(LIBFT_FILE):
					$(MAKE_LIB) 42_libft
 
$(NAME):			$(LIBFT_FILE) $(PUSH_SWAP_OBJ)
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
