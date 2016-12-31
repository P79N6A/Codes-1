#encoding:utf-8
from socket import *

server_port = 12000
server_socket = socket(AF_INET, SOCK_STREAM)
# 显式地为套接字分配一个端口
server_socket.bind(('', server_port))
# 请求连接的最大数
server_socket.listen(1)
print 'Ther server is ready to receive.'
connection_socket, client_address = server_socket.accept()
while True:
	modified_message = connection_socket.recv(1024).upper()
	connection_socket.send(modified_message)
connection_socket.close()