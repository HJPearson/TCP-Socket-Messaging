# TCP-Socket-Messaging
Two simple programs (server and client) for connection and messaging over TCP.

I have made this in such a way that it *theoretically* could be used on two different computers as opposed to simply running them both yourself over the localhost, but I have, admittedly, not tried it out that way. I can't currently be bothered to mess with cross-compilation so that it will work on my Windows PC (I coded this on MacOS/Apple Silicon). <br>

To compile, enter these commands into the terminal in order (if you aren't using Linux/Unix, then these commands will probably be different for you: <br>
- mkdir build <br>
- cd build <br>
- cmake .. <br>
- make <br>
You should then have two executables, server and client, for you to run in separate terminal windows. <br>

If you are on Windows, I don't think this code will work for you. I could be wrong, but it looks like you don't have access to sys/socket.h and should probably use [Winsock](https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-start-page-2?redirectedfrom=MSDN)
