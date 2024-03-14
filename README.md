# cub3d

Small 3D game using raycastig. It only allows you to move around the map you created. So there are no enemies or an objective. During this project we learned about raycasting, rendering images, floodfill and working together with git branches. 



### Original Wolfenstein 3D:
![image](https://github.com/SuQuoc/cub3d/assets/116435885/550abaa6-026d-4bd1-bc2e-e87188c6b089)



#### Copyright Notice

The image(s) used in this project/website are derived from the Wolfenstein game, which is the copyrighted property of "id Software" and others. The use of these images is solely for educational purposes and is not intended for commercial gain.
All rights to the original content, including images, logos, and trademarks, are owned by the respective copyright holders. The inclusion of these images in this project/website does not imply endorsement or affiliation with the original creators.
If you are the copyright owner and have concerns about the use of any material, please contact us, and we will promptly address the issue.

### Our project:
![Screenshot from 2023-12-15 13-06-19](https://github.com/SuQuoc/cub3d/assets/116435885/08a31972-d669-4b68-9392-32d0a278ba47)

You have the flexibility to choose any color for the floor and ceiling by adjusting the RGB values in the map file. Additionally, you can customize wall textures by editing the map file and providing an XPM file for the desired texture.


## Instructions
Make sure you a have:
    - c-compiler cc
    - X11 library
    - minilibx_linux from 42 (https://github.com/42Paris/minilibx-linux)

1. Clone the repository
4. Run the make command to compile
5. Execute the programm: "./cubed your_map_file"
6. Have fun and good luck

Run the default map:
```
git clone git@github.com:SuQuoc/Philosophers.git
cd cub3d
make run
```


# Usage
```
./cub3d [map_file.cub]
```

In addition to the map layout you can change following attributes by editing the map file:
+ `color of the floor` 
+ `color of the ceiling` 
+ `texture of the walls in all cardinal directions`

__Example__:  
```
NO map_textures/north_texture  
WE map_textures/west_texture  
SO map_textures/south_texture  
EA map_textures/east_texture  
C 0,0,255  
F 255,0,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000N00001
1111111111111111111111111
```

## Controls
- W, A, S, D
- left and right arrow key to rotate view
- ESC and "X-button" on top right window corner to end the game



