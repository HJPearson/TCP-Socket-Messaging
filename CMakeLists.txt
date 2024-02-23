cmake_minimum_required(VERSION 3.0)

project(TCPSocketMessaging)

# Set the C++ standard to C++11. Necessary for threads
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files for the server
set(SERVER_SOURCES
    src/server-code/server.cpp
    src/server-code/main.cpp
    )

# Add source files for the client
set(CLIENT_SOURCES
    src/client-code/client.cpp
    src/client-code/main.cpp
    )

# Set include directory
include_directories(/include)

# Add the executables for both programs
add_executable(server ${SERVER_SOURCES})
add_executable(client ${CLIENT_SOURCES})