# 42 Common Core

All my projects from the **42 Network Common Core** curriculum, collected in one repository.
Each folder is a standalone project with its own `Makefile` (or Docker setup) and can be built independently.

| # | Project | Language / Stack | Topic |
|---|---------|------------------|-------|
| 1 | [libft](libft) | C | Re-implementation of the standard C library + linked lists |
| 2 | [ft_printf](ft_printf) | C | Re-implementation of `printf` with variadic functions |
| 3 | [get_next_line](get_next_line) | C | Reading a file line by line |
| 4 | [push_swap](push_swap) | C | Sorting algorithm with two stacks |
| 5 | [minitalk](minitalk) | C | Client/server communication with UNIX signals |
| 6 | [so_long](so_long) | C · MiniLibX | 2D graphical game |
| 7 | [Philosophers](Philosophers) | C · pthreads | Dining philosophers, threads & mutexes / processes & semaphores |
| 8 | [minishell](minishell) | C | A small bash-like shell |
| 9 | [cub3D](cub3D) | C · MiniLibX | Raycasting 3D maze engine |
| 10 | [cpp](cpp) | C++98 | C++ Piscine, modules 00 → 09 |
| 11 | [irc](irc) | C++98 | IRC server (ft_irc) + bot |
| 12 | [inception](inception) | Docker | Multi-container infrastructure with Docker Compose |
| 13 | [ft_transcendence](ft_transcendence) | Next.js · Fastify · Docker | Full-stack web app with real-time Pong & chat |

---

## libft
My own C library, re-coding functions from `libc` (`ft_strlen`, `ft_memcpy`, `ft_atoi`, `ft_split`, `ft_itoa`, …) plus a set of linked-list helpers (`ft_lstnew`, `ft_lstadd_back`, `ft_lstmap`, …) as a bonus. It is reused in many later projects.

```bash
cd libft && make        # make bonus for the list functions
```

## ft_printf
My own version of `printf`, built as the static library `libftprintf.a` using variadic arguments (`va_list`). It supports the conversions `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` and `%%`, and returns the number of characters printed.

```bash
cd ft_printf && make
cc main.c -L. -lftprintf
```

## get_next_line
A function that returns one line at a time from a file descriptor, using a static buffer and any `BUFFER_SIZE`. The bonus version handles multiple file descriptors at once.

```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

## push_swap
Sorts a list of integers using two stacks (`a` and `b`) and a limited set of operations (`sa`, `pb`, `ra`, `rrr`, …) with the fewest moves possible. The bonus is a `checker` program that verifies a list of instructions.

```bash
cd push_swap && make && ./push_swap 3 2 5 1 4
```

## minitalk
A `server` and a `client` that exchange messages using only `SIGUSR1` and `SIGUSR2`, sending the string bit by bit. The bonus adds an acknowledgment from the server for each received message.

```bash
cd minitalk && make
./server                 # prints its PID
./client <PID> "Hello"
```

## so_long
A small 2D game made with **MiniLibX**: collect every coin (`C`) and reach the exit (`E`). Maps are `.ber` files built from `0` (floor), `1` (wall), `C`, `E` and `P` (player). The bonus adds sprite animations (player and coins) and a move counter on screen.

```bash
cd so_long && make && ./so_long maps/map1.ber
```

## Philosophers
The classic *dining philosophers* problem. `philo` uses **threads and mutexes**, `philo_bonus` uses **processes and semaphores**. The simulation stops when a philosopher dies or everyone has eaten enough.

```bash
cd Philosophers/philo && make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [meals_each]
```

## minishell
A simplified shell inspired by **bash**: prompt and history, pipes, redirections (`<`, `>`, `>>`), heredoc (`<<`), environment variable expansion (`$VAR`, `$?`), quotes, signal handling (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`) and the builtins `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.

```bash
cd minishell && make && ./minishell
```

## cub3D
A first-person 3D maze rendered with **raycasting** (inspired by Wolfenstein 3D) using MiniLibX. It reads a `.cub` scene file (textures, colors, map) and includes doors, a menu and wall textures.

```bash
cd cub3D && make && ./cub3D maps/manda.cub
```

## cpp — C++ Piscine
Ten modules introducing object-oriented programming in **C++98**:

| Module | Topics |
|--------|--------|
| 00 | Namespaces, classes, member functions, iostreams (PhoneBook, Account) |
| 01 | Memory allocation, references, pointers to members, `switch` (Zombie, Weapon, Harl) |
| 02 | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form (Fixed, BSP) |
| 03 | Inheritance (ClapTrap, ScavTrap, FragTrap, DiamondTrap) |
| 04 | Subtype polymorphism, abstract classes, interfaces (Animal, Brain, Materia) |
| 05 | Repetition and exceptions (Bureaucrat, Forms, Intern) |
| 06 | C++ casts (ScalarConverter, Serializer, type identification) |
| 07 | Templates (`swap`/`min`/`max`, `iter`, `Array`) |
| 08 | Templated containers, iterators, algorithms (easyfind, Span, MutantStack) |
| 09 | STL (BitcoinExchange, RPN, PmergeMe — Ford-Johnson sort) |

```bash
cd cpp/module_0X/ex0Y && make
```

## irc (ft_irc)
An **IRC server** in C++98 using non-blocking sockets and `poll()`. Supports authentication (`PASS`, `NICK`, `USER`), channels and messages (`JOIN`, `PART`, `PRIVMSG`, `TOPIC`, `INVITE`, `KICK`, `MODE`). It works with real IRC clients like `irssi` or `nc`. The `CBOT` folder holds a bot that connects to the server.

```bash
cd irc && make && ./ircserv <port> <password>
```

## inception
A small infrastructure built with **Docker Compose**, each service in its own container built from a custom Dockerfile:
- **NGINX** with TLS (the only entry point)
- **WordPress** + php-fpm
- **MariaDB**
- Bonus: **Redis** cache, **FTP** server, **Adminer**, **cAdvisor** and a static **portfolio** site

```bash
cd inception && make
```

> Secrets (`secrets/` and `srcs/.env`) are not committed. Create them locally before running.

## ft_transcendence
The final Common Core project: a full-stack web app for playing **Pong** online.
- **Frontend:** Next.js, TypeScript, Tailwind CSS, Radix UI
- **Backend:** Node.js, Fastify, Socket.IO, SQLite
- **Auth:** JWT, Google OAuth2, bcrypt
- **Infra:** Docker Compose, NGINX reverse proxy, HashiCorp Vault for secrets
- Features: real-time games, live chat, friends, user profiles and avatars

```bash
cd ft_transcendence && docker compose up --build
```

> `backend/.env` and the SQLite database are not committed. Create them locally before running.

---

## Requirements
- `cc` / `c++` and `make`
- [MiniLibX](https://github.com/42Paris/minilibx-linux) for `so_long` and `cub3D` (macOS: OpenGL + AppKit)
- Docker & Docker Compose for `inception` and `ft_transcendence`

## Author
**aabouqas** — student at 42 / 1337
