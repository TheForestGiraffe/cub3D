*This project has been created as part of the 42 curriculum by pecavalc and
tcunha.*

# cub3D
<P align="center">
	<img width="720" alt="game screenshot" src="https://github.com/user-attachments/assets/6de4df39-cb16-4c87-a1d9-32d7d779925f" />
<p/>

## Description

### General Description

	cub3D is a raycasting-based 3D game engine written in C, inspired by the
	original Wolfenstein 3D. Given a map file, the program renders a
	first-person perspective of the environment using the DDA (Digital
	Differential Analysis) raycasting algorithm. Each wall face can have a
	distinct XPM texture (North, South, West, East), and the floor and ceiling
	are rendered with solid RGB colors.

	The bonus version adds a top-down minimap overlay rendered directly on the
	game window.

### Project structure

	cub3D/
	├── include/             # Public headers
	├── src/
	│   ├── game/            # Game setup, loop and teardown
	│   ├── minimap_bonus/   # Bonus minimap rendering
	│   ├── mlx_wrapper/     # MiniLibX abstraction layer
	│   ├── parser/          # .cub file parser and validator
	│   ├── player_movement/ # Movement and rotation logic
	│   ├── raycaster/       # DDA raycasting engine
	│   ├── render/          # Wall, floor and ceiling rendering
	│   └── utils/           # Error handling
	├── libs/
	│   ├── libft/           # Custom C standard library
	│   └── mlx/             # MiniLibX graphics library
	├── maps/                # Sample map files
	├── textures/            # XPM wall textures
	└── test/                # Unit tests and test maps

## Instructions

### Compilation

	| cmd --------| Result --------------------------------|
	| ------------| ---------------------------------------|
	| make -------| build the mandatory version -----------|
	| make bonus -| build the bonus version (with minimap) |
	| make clean -| remove object files -------------------|
	| make fclean | remove object files and the executable |
	| make re ----| recompile from scratch ----------------|

### Execution

	To use the program run:

	./cub3D <path/to/map.cub>

	Examples:
	./cub3D maps/spaceship.cub

### Controls

	| Key --| Action -------------|
	|-------|---------------------|
	| `W` --| Move forward -------|
	| `S` --| Move backward ------|
	| `A` --| Strafe left --------|
	| `D` --| Strafe right -------|
	| `←` --| Rotate camera left -|
	| `→` --| Rotate camera right |
	| `ESC` | Exit ---------------|

### Testing/Debug rules

	| Cmd ----------------| Result ---------------------|
	| make test_parser ---| run parser unit tests ------|
	| make test_raycaster | run raycaster unit tests ---|
	| make test_norm -----| check norminette compliance |

### Map file format (.cub)

	The map file has two sections: scene configuration and the map grid.

	Scene configuration (order does not matter, must appear before the map):

	| Id --| Value ---------------------------| Example ------------------|
	|------|----------------------------------|---------------------------|
	| `NO` | Path to North wall texture (XPM) | `NO ./textures/north.xpm` |
	| `SO` | Path to South wall texture (XPM) | `SO ./textures/south.xpm` |
	| `WE` | Path to West wall texture (XPM) -| `WE ./textures/west.xpm` -|
	| `EA` | Path to East wall texture (XPM) -| `EA ./textures/east.xpm` -|
	| `F` -| Floor color (R,G,B) -------------| `F 220,100,0` ------------|
	| `C` -| Ceiling color (R,G,B) -----------| `C 225,30,0` -------------|

	Map grid (must be the last element in the file):

	| Char -----------------| Meaning -----------------------------------|
	|-----------------------|--------------------------------------------|
	| `1` ------------------| Wall --------------------------------------|
	| `0` ------------------| Empty floor -------------------------------|
	| `N` / `S` / `E` / `W` | Player start position and facing direction |

	The map must be fully enclosed by walls (`1`). Exactly one player start
	position must be present.

	Simple example of a `.cub` file:

	NO ./textures/north.xpm
	SO ./textures/south.xpm
	WE ./textures/west.xpm
	EA ./textures/east.xpm

	F 220,100,0
	C 225,30,0

	111111
	100001
	1001N1
	100001
	111111

## Resources

	[MiniLibX 42 Docs]
	(https://harm-smits.github.io/42docs/libs/minilibx)

	[Lode's Computer Graphics Tutorial — Raycasting]
	(https://lodev.org/cgtutor/raycasting.html)

	[Permadi's Ray-Casting Tutorial]
	(http://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)

## AI Usage

	A Claude project was created with the name "Computer Science Professor" and
	the following description "A professor of computer science who guides the
	user in computer science learning". The project is instructed to act as an
	expert senior software engineer and computer science educator, with
	expertise in C programming, software architecture, data structures, and
	algorithms. The goal of the project is to guide the user to their own
	solution through Socratic teaching. The project must prioritize deep
	conceptual understanding over quick fixes. Strict operational constraints
	where given to (i) not provide full code solutions or complete snippets;
	(ii) if a user asks for code, provide pseudocode, logic flows, or
	architectural diagrams first. Only provide syntax help after the user
	demonstrates they understand the logic; (iii) when referencing functions or
	tools, refer to standard documentation (e.g., C standard library, POSIX
	standards).

	This Claude project was used to discuss computer science concepts, search
	for relevant sources and help with the overall code structure. All logic
	and code resulting from these discussions were manually implemented, tested,
	and verified against the project requirements. Unit tests were not all
	manually written.

  ## Credits

  Some of the textures are a courtesy of https://www.areyep.com/  
