# get_next_line

## Description
get_next_line is a project at 42 School that implements a function which reads a line from a file descriptor. The function returns the line that was read, or NULL if there is nothing else to read or if an error occurred.

## Table of Contents
- Features
- Installation
- Usage
- Functions
- Bonus Part

## Features
- Reads text from a file descriptor one line at a time
- Returns the next line (including the terminating `\n` character if present)
- Handles multiple file descriptors in the bonus version
- Memory efficient with proper memory management
- Configurable buffer size for optimal performance

## Installation
Clone the repository and include the header in your project:

```bash
git clone https://github.com/matteo-genovese/get_next_line.git
cd get_next_line
```

You can use these commands to compile:

```bash
make        # Compile the standard version
make bonus  # Compile with bonus features
make clean  # Remove object files
make fclean # Remove object files and binary/library
make re     # Recompile everything
```

## Usage
Include the header in your C files:
```c
#include "get_next_line.h"
```

To use the function in your code:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);
        
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Don't forget to free the allocated memory
    }
    
    close(fd);
    return (0);
}
```

Compile with a specific buffer size:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 your_program.c get_next_line.c get_next_line_utils.c -o your_program
```

## Functions

### Main Functions
- [`get_next_line`](get_next_line.c) - Read a line from a file descriptor

### Helper Functions
- [`fill_line`](get_next_line.c) - Fill the line with content read from file descriptor
- [`fill_line_w_left_o`](get_next_line.c) - Fill the line with leftover content from previous reads
- [`ft_strlen`](get_next_line_utils.c) - Get string length
- [`ft_strjoin`](get_next_line_utils.c) - Join two strings
- [`ft_substr`](get_next_line_utils.c) - Create substring from a string
- [`ft_check_nl`](get_next_line_utils.c) - Check if string contains newline
- [`ft_sc`](get_next_line_utils.c) - Search for character in string
- [`ft_memset`](get_next_line.c) - Fill memory with a constant byte
- [`ft_m`](get_next_line.c) - Memory management utility function

## Bonus Part
The bonus part implements handling multiple file descriptors simultaneously:

- Can manage multiple file descriptors at the same time
- For example, if you can read from fd 3, 4, and 5, get_next_line can read from each one without losing the reading thread of each file descriptor or returning a line from another file descriptor

### Bonus Files
- [`get_next_line_bonus.c`](get_next_line_bonus.c)
- [`get_next_line_bonus.h`](get_next_line_bonus.h)
- [`get_next_line_utils_bonus.c`](get_next_line_utils_bonus.c)

## Author
- [mgenoves](https://profile-v3.intra.42.fr/users/mgenoves)

![image](https://github.com/user-attachments/assets/4081360e-2884-490c-a990-002e188cfa15)
