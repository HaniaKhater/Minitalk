CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SERVER = server
CLIENT = client

SHARED_FILES = messages.c libft_utils.c
SRC_SERVER = $(SHARED_FILES) server.c
SRC_CLIENT = $(SHARED_FILES) client.c
S_OBJ = $(SRC_SERVER:%.c=%.o)
C_OBJ = $(SRC_CLIENT:%.c=%.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(S_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(C_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) $^ -c

clean:
	$(RM) *.o *.gch

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
