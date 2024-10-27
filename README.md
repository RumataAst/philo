Philo is a Unix-based project at 42 focused on building a program that simulates the classic Dining Philosophers Problem, which explores synchronization, deadlock, and resource-sharing challenges in concurrent programming. This project involves creating and managing multiple threads to represent philosophers who alternate between thinking, eating, and sleeping, sharing limited resources (forks) without causing deadlock or starvation.

Through this project, I learned how to:

-Manage multiple threads using pthread library functions

-Implement mutexes to prevent data races and manage shared resources

-Simulate real-world concurrency problems and address issues like deadlock and starvation

-Use timers to control thread execution and ensure timing constraints are met


Program takes the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
