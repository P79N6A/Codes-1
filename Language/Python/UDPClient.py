#encoding:utf-8
from socket import *

server_name = '10.249.147.133'
server_port = 12000
# 使用IPV4，套接字为UDP
client_socket = socket(AF_INET, SOCK_DGRAM)
message = raw_input('Input lowercase sentence: ')
client_socket.sendto(message, (server_name, server_port))
# 取缓存长度2048
modified_message, server_address = client_socket.recvfrom(2048)
print modified_message
print server_address[0]
client_socket.close()