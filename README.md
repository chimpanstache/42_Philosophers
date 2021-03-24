# 42_Philosophers
This project is an implementation of [the dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).
It enables us to work with concurring thread and processes.
There is 3 declinations of the solution.
Philo_one : 
* Each Philosopher is represented with a thread
* Memory access and syscalls are protected with mutexes
Philo_two : 
* Each Philosopher is represented by a thread
* Memory access and syscalls are protected with semaphores
Philo_three : 
* Each Philosopher is represented by a process
* Memory access and syscalls are protected with semaphores

More details are available in the subject here attached

## Getting started
This project is built on macOS, so you have to run it on a mac environment.
On your terminal, execute in the repository of your choice:
```
git clone https://github.com/ehafidi/ft_printf.git
cd philo_one
make 
./philo_one [number of philosophers (<= 200 ms)] [lifetime (ms)] [time to eat (ms)] [time to sleep (ms)]
```
example : ./philo_two 5 600 200 200
