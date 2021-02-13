Exercise 2 - Theory questions
-----------------------------

### What is an atomic operation?
> An atomic operation in concurrent programming is a conseptual operation that
> * Run completely independent of other tasks / program operations
> * It does not rely on other tasks
> * The data it relies on cannot change during execution. It can only change if the atomic operation changes it, and should not be     visible until execion is finished.   
> * As far as other tasks are conserned, it is indivisible and instantaneous. Effects on the systen is as if they were interleaved.

### What is a critical section?
> In concurrent programming where we have a shared resource between two threads, in order to not get any erros we have to protect the access to the shared resource. This protected section of the program is called a critical secton and can only be accessed by a single thread at a time. 

### What is the difference between race conditions and data races?
> A race condition is a condition where the system relies on other uncontrollable tasks and the timing of these tasks greatly impact the behaviour of the system. A data race is special case of a race condition where instructions from two threads try accessing the same memory location at the same time, with at least one of them trying to modify the data.

### What are the differences between semaphores, binary semaphores, and mutexes?
> Semaphores are shared variables betweeen threads used to control access to common resources. A binary semaphore is such a semaphore, but can only represnet two values. (open or locked) (0,1). A mutex lock makes sure two threads dont access the same memory by making sure only the thread that locked the resource can open it. 


### What are the differences between channels (in Communicating Sequential Processes, or as used by Go, Rust), mailboxes (in the Actor model, or as used by Erlang, D, Akka), andd queues (as used by Python)? 
> A channel works kind of like radio. You can have multiple sender and recievers on the same channel. Mailbox model messages are directed towards a single reciver, using adresses. A queue, as used by python, is a LIFO or FIFO queue that can be safely extracted and inserted to by multiple threads. 

### List some advantages of using message passing over lock-based synchronization primitives.
> Message passing allows for more control of the shared resources between threads, since it's intuitive and systematic and we spesifically have to share data manually across threads, as opposed to shared resources where every thread potentially can modify the shared resources. With message passing there also aren't any limitation as to where the memory of the different threads are stored, which means that its possible in principle to have threads running on different computers across the world if we wanted to. 

### List some advantages of using lock-based synchronization primitives over message passing.
> It's a simple method that dont need a lot of extra resources work, and because of this it is faster than message passing. Directly editing memory adresses means we also dont need to copy data which also saves memory and time. 