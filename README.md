# Practical Session: Debugging

Follow the instructions from the practical session page: [https://github.com/sc-camp/2015-debug](https://github.com/sc-camp/2015-debug)


## 0 - Pre-requisites

### Configure your connection to Guane cluster

Edit the file `~/.ssh/config` (create it if it does not already exist) and adding the following entries:
 
```
	Host toctoc
	        User *yourlogin*
	        Hostname toctoc.sc3.uis.edu.co
	        ForwardX11 yes

	Host guane
	        User *yourlogin*
	        Hostname guane
	        ForwardX11 yes
	        ProxyCommand ssh -q toctoc "nc -q 0 %h %p"
```


Now you shall be able to issue the following command to connect to the cluster and obtain the welcome banner: 

		(laptop)$> ssh guane

In the sequel, we assume these aliases to be defined. 

### Connect to a node of the Guane cluster

The first step is the reservation of a resource. Connect to the cluster frontend

    (laptop)$> ssh guane

Once connected to the user frontend, book 1 core for 3 hours

    jdoe@guane:~$ oarsub -I -l core=1,walltime="03:00:00"

When the job is running, you can start the practical session.



## 1 - GDB Tutorial


Tutorial from [A GDB Tutorial with Examples](http://www.cprogramming.com/gdb.html)


## 2 - Valgrind Tutorial


Tutorial from [Using Valgrind to Find Memory Leaks and Invalid Memory Use](http://www.cprogramming.com/debugging/valgrind.html)


 
## 3 - Bug Hunting

A list of programs demonstrating the different kind of bus are available in the `exercises` directory.
Try the different debugging tools on every example to see how they behave and find the bugs.

Run the following command to download all the exercices:
```
git clone https://github.com/sc-camp/2015-debug.git sc-camp-2015-debug
```

### Notes:

  - You can compile each program manually using `gcc` or `icc`. You are encouraged to try both to see how differently they behave. Example: `gcc program.c -o program`. Add any additional parameter you might need.

  - Some program required additional options to be compiled. They are indicated in comment at the beginning of each source file.
  
  
 
