### Language choice thoghts
> This is a small document containing thoughs about the elevator project
## General thoughs
> At the current time I'm thinking at least three goroutines. One for networking, one for hardware_IO and one for the state machine. However, it might be useful to have more too. Multithreading for IO is a must because we want to be able to listen for network messages/button inputs and do useful things in the mean time as well. The state machine needs to function in it's own goroutine to be able to switch states and do useful stuff. If the states are stored in the memory of the state machine, then it can send messages to the other goroutines, sharing what needs to be shared. 

## Network
>Setting up communitcation through IP is something that should exist a lot of libraries for, and is something that should work fairly straigh of of the box. At least in python it is. Unfortunately I've heard GO has a lack of support for UDP which is very strange, but running on top of linux, I believe these issues have been solved by others and there are answers online. UDP are especially useful for broadcasting, however for GO, it might be useful to use both protocols. 

## IDE
>VSCode provides a lot of extensions for compiler help, debugging and more. Working in a linux environment, gdb is a familiar debugger and can also help. However, multithreading is hard to debug. My plan is to set up the elevator server (provided) and use it frequently to test the elevator throughout the project. 

