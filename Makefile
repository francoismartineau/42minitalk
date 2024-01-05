CLIENT_NAME = client
SERVER_NAME = server
NAME = name

LIBFT_DIR = libft/
CLIENT_DIR = client/
SERVER_DIR = server/
COMMON_DIR = common/
SRC_DIR = srcs/
OBJS_DIR = objs/
INCLUDE_DIR = include/

CLIENT_SRCS = main.c \
	sigactions.c \
	util.c
CLIENT_SRCS := $(addprefix $(SRC_DIR)$(CLIENT_DIR), $(CLIENT_SRCS))
CLIENT_OBJS = $(CLIENT_SRCS:$(SRC_DIR)%.c=$(OBJS_DIR)%.o)
CLIENT_DEPS = $(CLIENT_OBJS:%.o=%.d)	
SERVER_SRCS = exit.c \
	messages1.c \
	messages2.c \
	main.c \
	sigactions.c
SERVER_SRCS := $(addprefix $(SRC_DIR)$(SERVER_DIR), $(SERVER_SRCS))
SERVER_OBJS = $(SERVER_SRCS:$(SRC_DIR)%.c=$(OBJS_DIR)%.o)
SERVER_DEPS = $(SERVER_OBJS:%.o=%.d)

CC = gcc
IQUOTES = $(addprefix -iquote, $(LIBFT_DIR) $(INCLUDE_DIR))
CFLAGS = -Wall -Wextra -Werror -MMD -g -fsanitize=address
LDFLAGS = $(addprefix -L, $(LIBFT_DIR))
LDLIBS = -lft

all: $(NAME)

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

bonus: all

$(SERVER_NAME): $(SERVER_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(IQUOTES) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(CLIENT_NAME): $(CLIENT_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(IQUOTES) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(OBJS_DIR)$(SERVER_DIR)%.o: $(SRC_DIR)$(SERVER_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IQUOTES) -c -o $@ $<

$(OBJS_DIR)$(CLIENT_DIR)%.o: $(SRC_DIR)$(CLIENT_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IQUOTES) -c -o $@ $<

clean:
	rm -rf $(SERVER_OBJS) $(SERVER_DEPS) \
		$(CLIENT_OBJS) $(CLIENT_DEPS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) $@
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PONY: all bonus clean fclean re

-include $(SERVER_DEPS) $(CLIENT_DEPS) $(COMMON_DEPS)