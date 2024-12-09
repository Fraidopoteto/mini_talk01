NAME    = minitalk
SERVER  = server
CLIENT  = client
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRCS    = server.c client.c
OBJS    = $(SRCS:.c=.o)
LIBFT_DIR = ./libft
LIBFT   = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)

all: $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER): server.c minitalk.h
	$(CC) $(CFLAGS) -o $(SERVER) server.c -L$(LIBFT_DIR) -lft

$(CLIENT): client.c minitalk.h
	$(CC) $(CFLAGS) -o $(CLIENT) client.c -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

clean:
	$(RM) $(SERVER) $(CLIENT)
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all $(SERVER) $(CLIENT) clean fclean re
