import socket

local_ip = '127.0.0.1'  # IP address of the local machine
server_port = 7000	# Port of the IRC server running on the local machine
client_port = 7001  # Port for the IRC client

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((local_ip, server_port))
server_socket.listen()

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.bind((local_ip, client_port))
client_socket.listen()

while True:
    server_conn, server_addr = server_socket.accept()
    print(f'Accepted connection from {server_addr} (server)')

    client_conn, client_addr = client_socket.accept()
    print(f'Accepted connection from {client_addr} (client)')

    if server_addr[0] == local_ip:
        # Forward messages from IRC server to IRC client
        while True:
            message = server_conn.recv(1024)
            if not message:
                break
            client_conn.sendall(message)
            print(f'Sent from server to client: {message}')

    else:
        # Forward messages from IRC client to IRC server
        while True:
            message = client_conn.recv(1024)
            if not message:
                break
            server_conn.sendall(message)
            print(f'Sent from client to server: {message}')

    server_conn.close()
    client_conn.close()

