CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f
HDR = minitalk.h
CLT_OBJ = mandatory/client.o
SRV_OBJ = mandatory/server.o
UTLS_OBJ = utils.o
CLT_OBJ_BONUS = bonus/client_b.o
SRV_OBJ_BONUS = bonus/server_b.o

mandatory/%.o : mandatory/%.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

all : client server

client : $(CLT_OBJ) $(UTLS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

server : $(SRV_OBJ) $(UTLS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bonus : client_b server_b

client_b : $(CLT_OBJ_BONUS) $(UTLS_OBJ)
		$(CC) $(CFLAGS) $^ -o $@	

server_b : $(SRV_OBJ_BONUS) $(UTLS_OBJ)
		$(CC) $(CFLAGS) $^ -o $@	
	

clean :
		$(RM) $(CLT_OBJ_BONUS) $(UTLS_OBJ) $(SRV_OBJ_BONUS) $(CLT_OBJ) $(SRV_OBJ)

fclean : clean
	$(RM) server client server_b client_b 

re : fclean all bonus
