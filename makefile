CC = g++
CPPFLAGS = -std=c++17
TGT = client
MAIN = $(TGT).o
OBJ = ./tcpip/socket.o ./tcpip/server.o ./tcpip/client.o $(MAIN)
YCM_DIR = ~/.vim/bundle/YouCompleteMe/
YCM_CONF = .ycm_extra_conf.py

$(TGT) : $(OBJ)
	$(CC) $(CPPFLAGS) -o $(TGT) $(OBJ)

init :
	cp $(YCM_DIR)$(YCM_CONF) ./$(YCM_CONF)
	echo $^

run :
	./$(TGT)

clear : 
	rm $(TGT) $(OBJ)
