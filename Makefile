CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -I 42_libft -I includes
RM					=	rm -f
NAME				=	push_swap
 
# Libraries
LIBFT_FILE			=	42_libft/libft.a
LDFLAGS     		=	-L 42_libft -l ft
MAKE_LIB			=	make -C
 
STACK_SRC_DIR		=	list_operations
PUSH_SWAP_SRC_DIR	=	srcs/push_swap
VALIDATION_SRC_DIR	=	srcs/validation
 
STACK_SRC           =	$(STACK_SRC_DIR)/ft_stackadd_back.c \
						$(STACK_SRC_DIR)/ft_stackclear.c \
						$(STACK_SRC_DIR)/ft_stackiter.c \
						$(STACK_SRC_DIR)/ft_stackmap.c \
						$(STACK_SRC_DIR)/ft_stacksize.c \
						$(STACK_SRC_DIR)/ft_stackadd_front.c \
                        $(STACK_SRC_DIR)/ft_stackdelone.c \
						$(STACK_SRC_DIR)/ft_stacklast.c \
						$(STACK_SRC_DIR)/ft_stacknew.c 
 
VALIDATION_SRC		=	$(VALIDATION_SRC_DIR)/validation_main.c \
						$(VALIDATION_SRC_DIR)/validation_numbers.c \
						$(VALIDATION_SRC_DIR)/validation_duplicates.c \
						$(VALIDATION_SRC_DIR)/string_parsing.c \
						$(VALIDATION_SRC_DIR)/validation_quoted.c \
						$(VALIDATION_SRC_DIR)/validation_limits.c \
						$(VALIDATION_SRC_DIR)/error_handling.c
 
PS_SRC				=	$(PUSH_SWAP_SRC_DIR)/default_sorts.c
 
PUSH_SWAP_SRC		=	main.c \
						$(STACK_SRC) #\
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
