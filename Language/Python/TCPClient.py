#encoding:utf-8
from socket import *

server_name = '10.249.147.133'
server_port = 12000
# 使用IPV4，套接字为TCP
client_socket = socket(AF_INET, SOCK_STREAM)
# 得先创建TCP连接
client_socket.connect((server_name, server_port))
while 1:
	sentence = raw_input('Input lowercase sentence: ')
	client_socket.send(sentence)
	modified_sentence = client_socket.recv(1024)
	print 'From server: ', modified_sentence
client_socket.close()