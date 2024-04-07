# Internet Relay Chat (IRC) server

## Description

### What

IRC provides a way of communicating, with large groups of users (much like Discord
or Slack). It pioneered real-time communication for large groups of users, by
introducing chat and IRC protocol technology.

### How

A Linux or MacOS system is necessary to run this program.
To properly test or just use this IRC server you also need an IRC client. The ones
being used to test the server are LimeChat and Adium.

## Installation

To compile the program simply run
```bash
make
```

## Usage

Start the server like so:
```bash
./ircserv port password 

# port is port number, on which server will wait for new connections.
# provide any password you like to the IRC server, which will be required from
# IRC clients to join.
```

To stop it, simply press
```Ctrl - C```

To remove object files
```bash
make clean
```
or
```bash
make fclean
```
