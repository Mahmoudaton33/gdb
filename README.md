# gdb Debugging 

## first step 
This guide demonstrates how to create a simple C program with a **segmentation fault**, compile it with debugging symbols, and use **GDB** to analyze and navigate the code.

---

## 1. create a c program with a segmentation fault error 

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    int x = 10;
    int y = 20;
    int z = x + y;
    printf("The sum of %d and %d is %d\n", x, y, z);

    int *ptr;
    *ptr=10; // This will likely cause a segmentation fault
    printf("Value at ptr: %d\n", *ptr);
    return 0;
}
```
## 2. compile with debugging symbols 

--- 
```c
gcc test_main.c -g -o main.out
```
## 3. start gdb

```c
gdb ./main.out
```
## 4. View the source code in TUI Mode(terminal user interface)
inside gdb press 
```c
ctr + x then a
```
This enables TUI (Text User Interface) mode, which shows the source code and allows navigation.

## 5. start debugging 
Start the program from the beginning by writing :
```c
start 
```
Step through the code line by line:
```c
n
```
printing variable value for example x:
```c
p x
```
also you can run the code by the following:
```c
run
```
or just type
```c
r
```
### Lets see more gdb comands (step, refresh, c, finish, bt, quit, b or break & etc)
inside the TUI if you see the code not organised write the following:
```c
refresh
```
if you want to step into a function write the following:
```c
s
```
or
```c
step
```
if you want to exit the current function:
```c
finish
```
if you want to make the program to continue:
```c
c
```
if you want to exit the gdb session:
```c
quit
```
if you want to add breakpoint:
```c
b lineNUmber
example >> b 10
```
or
```c
break 10
```



### How to get know the all set breakpoints?
```c
info breakpoints
```
### How to delete breakpoint?
after doing info breakpoints you can see the Num column, so select the one you want to delete
for example
```c
delete 2
```
if you want to delete all breakpoints:
```c
delete
```

### Also you can set a breakpoint for (function name, file name , line number)
```c
b functionName
b file1.cpp:functionName // file name + function name  
b file1.cpp:25           // file name + line number 
b 20                     // line number  
```
### Also we can add conditional breakpoint like the following:
assume we have the following code
```c

void print_message(const char *message) {
    printf("Message: %s\n", message);
}
int main() {
    printf("Hello, World!\n");
    
    int i;
    for(i = 0; i < 10; i++) {
        print_message("Inside the loop\n");
    }
    return 0;
}
```
we want to add break point when i is equal to 5
```c
//b linNUmber if i==5 
b 20 if i==5
```
### If you want to print all local variables 
```c
info locals
```
### watch command
if you want to make a breakpoint at a specific variable only when its value was changed: 
```c
watch x     // puts harware breakpoint 
```
also you can make it under condition like the following:
```c
watch x==3  // put breakpoint if x value = to 3 
```

### display command 
if you want to display any variable value with every time you run any command:
```c
display x
display y
```
to see the all display variables:
```c
info display    // here you will see the all display variables and an ID for each
```
if you want to make undisplay for a specfic variable:
```c
undisplay 2     // 2 is the variable ID 
```
### How i can overwrite vraiable value?

```c
set var x=20        // set x to 20 
```
if x inside class or struct
```c
set var obj.x=50        // obj is an object from a class 
```
### calling function through gdb commands
assume function prototype is sum(x,y):
```c
call sum(5,6)   // it should execute the function  
```
### if you need to know the type of a variable or object

```c
ptype x         // vraiable name
ptype sum()     // function name 
```
or use the following
```c
whatis sum()
```
### if you need to see the code of a specific function

```c
list print_hello()
list Data::HelloWorld()     // if HelloWorld is a method from Data 
```
### if you want to show the assembly code for the source code or even for a specific function

```c
disassemble /s               // will print the whole assembly code
disassemble /s print_hello  // will print assembly code for only print_hello function 
```
 
 ### How to use backtrace command (bt)
 after program being crashed do the following:
 ```c
 bt
 ```
 or
 ```c
 backtrace
 ```
 then keep press enter to present the whole frames 
 if you want to present the code for any frame just do the following:
 ```c
 frame 1        // 1 is the frame number could be any number
 ```
 ### if you want to show the registers info 

 ```c
 info registers
 ```
 ### if you want to present the value of stack pointer (for example) rsp

 ```c
 x/32w $rsp     // 32w means 32 word you can type>>  help x/ to see the all format 
 ```
 also if you want to present the output in hexadecimal format
 ```c
 x/32wx $rsp
 ```
 ### How to attach a running process with its PID?
 first you have to get the process PID 
 ```c
 ps aux | grep processName  // for example test.out or WPEWebProcess
 ```
 then you can attach the process by two ways >> the firs. 
 ```c
 gdb
 attach PID
 ```
 or
 ```c
 gdb -p PID
 ```
 after attaching the PID you can run.
 ```c
 bt
 ```
 to see the running frames and you can go to specific frame through the following.
 ```c
 frame FrameNumber  // frame 3 ,, 3 here for frame 3 you can find the frame number after running bt command 
 ```
then you can see the source code by pressing Ctrl + x then a (if the lib was built by using the -g ).

### How to open gdb-server ?
1 - open gdbserver with specific port on the target machine. 
```c
gdbserver :1234 --attach <PID>
```

## What is gdb-multiarch?

It’s a version of GDB that supports cross-debugging for multiple architectures (ARM, MIPS, RISC-V, etc.) from your PC.

You’ll need it if you want to connect to a gdbserver that’s running code built for another CPU (like ARM firmware on a router, Raspberry Pi, etc.).

🔹 Install gdb-multiarch on Ubuntu/Debian.
```c
sudo apt update
sudo apt install gdb-multiarch
```
2 - so on the host machine run the following. 
```c
gdb-multiarch
target remote IP:PORT   // target remote 192.168.8.122:1234
```

you can do the same on the localhost through the following.
1 - open terminal and write.
```c
gdbserver localhost:1234 test.out       // test.out is an executable file
```
2 - open another terminal and write.
```c
gdb test.out
target remote localhost:1234
```

# How to create gdb file and commands?
1 - create a file without file extension for example (gdbcommands).
```c
define testcommand
	target remote localhost:1234
	b main
	c
end
```
2 - run the following.
```c
gdb thread.out -x gdbcommands   // -x to tell gdb that you will run the commands inside gdbcommands file
testcommand                     // here you tell gdb start running the commands, you can delete (define testcommand) then the commands will be run directly after entered to the gdb terminal 
```
Note: if you forget to pass the gdbcommands file at the beginning you can source it inside gdb terminal as the following.
```c
source gdbcommands
```

### Very good practice point 
if you have an issue randomly happened and you want to catch it.
1 - run gdb. 
2 - put breakepoint at the exit function (the function that alwayes being run after code being crashed and before process get finished) every c or c++ programm has exit function.
3 - using the breakpoint number assume it 2, run the following.
```c
commands 2
run         // you can type any command for example info registers & you can write any number of commands you want 
end         // you should write this command at the end of the commands 
```
4 - after that run.
```c
c       // for continue 
```
## Write shell commands inside the gdb terminal

inside the gdb terminal you can the following.
```c
shell ls                // shell then any command
pipe p x | grep size    // also after pipe you can write what you want
| p x | grep size 
! ls
```
also you can modify the code and compile it again from the gdb terminal no need to exit from the gdb terminal.
```c
shell g++ -g thread.cpp -o thread.out
run 
```
## print the PID from the gdb terminal 

```c 
python
import os
print(os.getpid())
end
```
or
```c
shell ps -aux | grep gdb
```
## How i can set a breakpoints at every function in the source code?

```c
rbreak thread.cpp       // recurseve breakpoint 
```
if you want to save the output inside logfile do the following:
```c
set logging file ./test.log
set logging on
```

### CoreDump files 
1 - first you have to check the coredump limitation through the following:
```c
ulimit -a
ulimit -c unlimited
```
make sure that your target was set coredump file to unlimited.
2 - how i can get the path of the coredump files?
```c
cat /proc/sys/kernel/core_pattern
```
3 - how i can use the codedump file?
```c
gdb WPEWebProcess
core PATH/TO/coredump/file
```

### the differences between (thread apply all bt) and (bt)
bt (short for backtrace)

Shows the call stack (stack frames) of the current thread only.

Useful if:

Your program is single-threaded.

Or you’re only interested in the thread where execution stopped (e.g. at a breakpoint or crash).
```c
(gdb) bt
#0  foo() at test.cpp:10
#1  bar() at test.cpp:5
#2  main() at test.cpp:15
```
This means the current thread is inside foo(), called from bar(), called from main().

thread apply all bt

Runs bt for all threads in the program, not just the current one.

You get a backtrace per thread, labeled with its thread ID and system ID.

Essential when debugging multi-threaded programs (e.g. C++11 threads, pthreads, OpenMP, etc.), because the crash might not be in the thread you’re currently stopped in.
```c
(gdb) thread apply all bt

Thread 3 (Thread 0x7ffff7fc7700 (LWP 1235)):
#0  __pthread_mutex_lock (mutex=0x5555557570) at pthread_mutex_lock.c:67
#1  worker_thread() at worker.cpp:42
#2  ...

Thread 2 (Thread 0x7ffff7fc6700 (LWP 1234)):
#0  sleep () at ../sysdeps/unix/syscall-template.S:84
#1  logger_thread() at logger.cpp:20
#2  ...

Thread 1 (Thread 0x7ffff7fc5700 (LWP 1233)):
#0  main() at main.cpp:15
```
Here you see all threads’ stacks at once — very helpful when one thread is deadlocked, waiting, or crashed while others are still running.