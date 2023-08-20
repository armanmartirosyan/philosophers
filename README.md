# Dining Philosophers Problem Solutions in C

Welcome to the Dining Philosophers Problem Solutions repository! Here, you'll find two distinct approaches to solving the classic Dining Philosophers Problem using C programming, showcasing concurrency techniques through mutexes/threads and semaphores/processes.

## Table of Contents
- [Introduction](#introduction)
- [Directory Structure](#directory-structure)
- [Running the Code](#running-the-code)
- [Program Arguments](#program-arguments)
- [Contributions](#contributions)
- [License](#license)

## Introduction
The Dining Philosophers Problem embodies the challenges of resource allocation and synchronization in multi-threaded environments. This repository offers two solutions, each demonstrating different concurrency mechanisms using mutexes/threads (`philo` directory) and semaphores/processes (`philo_bonus` directory).

## Directory Structure
- `philo`: Mutexes/Threads solution.
- `philo_bonus`: Semaphores/Processes solution.

## Running the Code
1. Clone the repository.
2. Navigate to the chosen directory: `philo` for mutexes/threads, or `philo_bonus` for semaphores/processes.
3. Open your terminal and execute the following commands:
   ```shell
   make
   ./philo
  ```
or
```shell
  make
  ./philo_bonus
```

## Program Arguments
To run the program, provide the following arguments:

- `number_of_philosophers`: Specifies the number of philosophers and forks.
- `time_to_die` (in milliseconds): Defines the maximum time a philosopher can go without eating before they perish.
- `time_to_eat` (in milliseconds): Represents the time a philosopher takes to consume a meal, holding two forks.
- `time_to_sleep` (in milliseconds): Sets the duration a philosopher spends sleeping.
- `[number_of_times_each_philosopher_must_eat]`: Optional argument. When specified, the simulation halts after all philosophers have eaten the designated number of times. If not provided, the simulation stops upon a philosopher's demise.

## Contributions
Contributions are welcomed! Feel free to open issues or submit pull requests for improvements, enhancements, or alternative solutions.

## License
This repository is licensed under the [MIT License](LICENSE). You're free to use, modify, and distribute the code in accordance with the terms of this license.

Engage in the exploration of concurrency with the Dining Philosophers Problem Solutions. Choose your preferred approach, delve into the code, and uncover the intricacies of multi-threading and synchronization. Happy coding! 🚀💻
