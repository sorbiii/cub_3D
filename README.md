*This project has been created as part of the 42 curriculum by mzapora, nadamczy.*

# cub3D

## Description
cub3D is a 42 school project designed to create a 3D perspective maze exploration game using the raycasting technique, heavily inspired by the classic 1992 game Wolfenstein 3D. The primary goal of this project is to understand the mathematics behind raycasting, window management, event handling, and 2D-to-3D rendering. The program parses a `.cub` configuration file to load textures, set floor/ceiling colors, validate the map layout, and then renders the scene using the internal MiniLibX graphics library.

## Instructions

### Prerequisites
To compile and run this project, especially on Linux environments (like Fedora), you will need standard C compilation tools and the dependencies required by MiniLibX:
* `minilibx: https://github.com/42paris/minilibx-linux.git` *
* `make` and `cc`
* X11 development headers (e.g., `libxext-dev`, `libx11-dev`)
* `libbsd` and `zlib`

### Compilation
The project uses a standard `Makefile` to compile the source code along with its dependencies (`libft` and `minilibx-linux`). 
To build the executable `cub3D`, simply run:
make
### EXECUTION
Ex:
./cub3D maps/good/works_2.cub
./cub3D	maps/good/matrix.cub
## Controls
* **W, A, S, D**: Move the player (forward, left, backward, right).
* **Left / Right Arrow Keys**: Rotate the camera view.
* **ESC**: Exit the game cleanly.
## Resources
* **MiniLibX Documentation**: Official 42 docs for handling window creation, image buffers, and key hooks.
* **AI Usage**: AI (Gemini) was utilized during the development of this project strictly as a debugging and optimization assistant.