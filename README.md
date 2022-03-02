# Basic Info

This is a concurrent computing server based on process pool, which is used to solve any order inverse matrix for clients in parallel.

# Compile

Compile three projects separately.

```shell
cd Client
g++ -o client client.cpp
```

```shell
cd ProcessPoolServer
g++ -o process_pool_server process_pool_server.cpp
```

```shell
cd ComputingService/build
cmake ..
make
```

# Use

Copy the binary "client" to the client machine.

Copy the binary "process_pool_server" and "ComputingSrv" to the client machine.

Make sure that the location of "ComputingSrv" is right. Otherwise, change the `file_name` in process_pool_server.cpp and then compile again.

Then you must make sure that server and client can "ping":

Client machine:

```shell
ping serverIP
```

If it can "ping", then do the following steps:

1. In server machine:

```shell
./process_pool_server IP Port
```

2. In client machine:

```shell
./client serverIP serverPort
```

# Project mind map

waitting...