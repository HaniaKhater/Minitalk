CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SERVER_NAME = server
CLIENT_NAME = client

SERVER_FILES = server \
	       	utils

CLIENT_FILES = client \
		utils

INCS_DIR = ./incs

SRCS_DIR = ./srcs

SERVER_SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(SERVER_FILES)))
SERVER_OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(SERVER_FILES)))

CLIENT_SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(CLIENT_FILES)))
CLIENT_OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(CLIENT_FILES)))

.c.o: $(SERVER_SRCS) $(CLIENT_SRCS) $(INCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(LIBFT_NAME) $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
