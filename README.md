CMPE322 Project1 

This project is an implementation of a shell. Core implementation has been made with c++. 

For using the shell, simply open a terminal and type "make".

Compiled project output is named as Project1. This will be inside the created folder build.

There are two sub classes and one main object. The subclasses contains operations and input controlling mechanism. 

The currently supported commands are;

listdir -> lists all elements in current directory
mycomputername -> shows hostname of the os
whatsmyip -> shows the local ip
printfile (fileName) -> prints file with enter press -> E.G.: printfile input.txt
printfile (fileName) > (newFileName) -> copies the contained string to another file.  E.G.: printfile input.txt > output.txt
dididothat -> checks whether user used this command or not in his/her last 15 commands. E.G.: dididothat "printfile"
hellotext -> opens gedit text editor for user to write.
exit -> exits the shell.
# MyShell
