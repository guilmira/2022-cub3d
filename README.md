# # cub3d - @42Born2Code
The project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. The goal its to explore ray-casting with our own libraries. The result is a dynamic view inside a maze, in which the player will have to find their way.

This ReastDME is dedicated to our long devoted fans. Enjoy our CUBE.

![](https://github.com/GuilleMira/cub3d/blob/newguille/gif/show_off.gif)

## About

Raycasting project of 42 Madrid

Developed in C by Guille and Joan as part of the common core.

Guillermo Mira [a.k.a. guilmira] Github: https://github.com/GuilleMira
Joan Sanfelipe [a.k.a. jsanfeli] Github: https://github.com/KiriamBlu

### Requirements
The only requirements are:
- GNU make (v3.81)
- GCC (v4.2.1)
- MLX (v2.2.0) 
- glfw library

Those versions are the ones used during development.

### Building the program

Only available for Linux´s main distributions.

1. Download/Clone this repo
        git clone https://github.com/GuilleMira/cub3d.git
2. `cd` into the root directory
        cd cub3d
3. `make install` to install all requirements
        make install


### Running the program

## First run (default)

-For Darwin(default)
	Just by executing `make exe` for Darwin distribution will compile and run the program. Enjoy.
		make exe

	-For Arch
		make ARCH

	-Rest of Linux distributions
		make LINUX

## Custom run

After building the source, run `./cub3D main_map.cub` from the project root.
This will execute the CUBE with the default map built by developers. This is a middle-size map that shows
all the basic features of the pproject such as, raycasted walls, collisions, player movement and minimap.


### Customizing your own map
`main_map.cub` is nothing but an argument. If the user wants to build their own custom map, the rules to built it are the following:

# Type of file:
	Nothing more than a simple text file. The extension should be ".cub". For example: "map.cub"
# Texture:
	In the folder textures, you can include whatever .png file that u wish. In order to include it in the file, u must add the extension in the text file. For example
		north textures/example_texture1.png
    	south textures/example_texture2.png
   		east textures/example_texture3.png
    	west textures/example_texture4.png
# Map rules:
	The perimeter map must be fully closed by walls. And the only elements allowed are the following:
	1				means wall.
	0				means playeable space.
	'N' 'E' 'W' 'S'	means player orientation. 
# Player position and orientation:
	'N' 'E' 'W' 'S'	means player orientation. 
# Sky colour and sky floor:
	RGB means red, green and blue. Values given as a parameter can only go from 0 to 255 in all cases.
	A value of (255, 0, 0) means full red.

	You have to add the colours by following the RGB standard as in the example:
	C 40,40,40
	F 151,151,151

# Controls:
	W A S D ▶️ to move through the map
	⬅ ⭕ ➡️ to rotate the camera
	
## Example:
	north textures/first_brick_layer.png
	south textures/second_brick_layer.png
   	east textures/third_brick_layer.png
    west textures/fourth_brick_layer.png
      
    F 151,151,151
	C 40,40,40

	1111111
	1000011
	1000011
	10N0111
	1000111
	1000111
	11111

As you can see from the example above, the map does not have to be necessarily a regular square.


