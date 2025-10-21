# Operating-Systems-----Project-1
The repository contains the following files:
1) producer.c - Contains the producer implmentation of the Producer-Consumer problem using semaphores and threads.
2) consumer.c - Contains the consumer implementation that works with producer.c to consume data in the buffer.

Usage Instructions

Before compiling, make sure you are working in a Linux environment.
For example, this project was tested on the Kent State University servers (wasp/hornet).
Once you get into the Linux environment you need to create both the producer and consumer files by doing:
     - touch producer.c
     - touch consumer.c
Then copy the provided code into each respective file.

Compilation

Once the code has been copied over, type the following commands in the terminal:

     - gcc producer.c -pthread -lrt -o producer
     
     - gcc consumer.c -pthread -lrt -o consumer
     
These commands compile both files.

Execution

Once compiled, run the programs with:

     - ./producer & ./consumer &
     
This command will run the program.
