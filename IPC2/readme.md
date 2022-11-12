<p> About Pipe : The pipe() system function is used to open file descriptors, which are used to communicate between different UNIX processes. the pipe() function creates a unidirectional data channel for inter-process communication. </p>

### 1. Write a C program where the parent and a child process will exchange their information through PIPE IPC. 
### 2. Write a C program where the main process and the threading processes will exchange their data through pipe IPC. 
### 3. Write another C program where the parent process will create a child and then replace it with an existing process from the hard disk storage by calling the EXEC family functions. 
<p> The main process and the new process will now communicate with the PIPE IPC. The main process will open a pipe and will pass the descriptors through the suitable EXEC family functions to the new process for IPC. </p>
