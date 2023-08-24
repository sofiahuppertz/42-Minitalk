SERVER = server
CLIENT = client
LIBFT = 42-Libft/libft/libft.a

INCLUDE = -I./ -I/42-Libft/Libft
CFLAGS = -Wall -Wextra -Werror

SERVER_SRCS = $(addprefix srcs/, server.c server_utils.c common_utils.c)
CLIENT_SRCS = $(addprefix srcs/, client.c client_utils.c common_utils.c)

C_OBJS =  $(CLIENT_SRCS:.c=.o)
S_OBJS = $(SERVER_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER) : $(LIBFT) $(S_OBJS)
	cc -g $(CFLAGS) $(S_OBJS) -L42-Libft/libft -lft -o $(SERVER)

$(CLIENT) : $(LIBFT) $(C_OBJS)
	cc -g $(CFLAGS) $(C_OBJS) -L42-Libft/libft -lft -o $(CLIENT)

%.o: srcs/%.c
	cc -g $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C 42-Libft/libft

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	
clean: 
	rm -f $(C_OBJS)
	rm -f $(S_OBJS)
	make clean -C 42-Libft/libft

re: fclean all

.PHONY: all clean fclean re