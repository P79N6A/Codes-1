#encoding:utf-8
from socket import *

server_port = 12000
server_socket = socket(AF_INET, SOCK_DGRAM)
# 显式地为套接字分配一个端口
server_socket.bind(('', server_port))
print 'Ther server is ready to receive.'
while True:
	message, client_address = server_socket.recvfrom(2048)
	modified_message = message.upper()
	server_socket.sendto(modified_message, client_address)