
# snake_game_project hello

In this project we had created a single player snake game using c language and graphics.h library. In this game, snake will eat the food and become long. Obstacles will leads to snake death and also when snake eats itself.


## Installation

 - ### CodeBolcks Installation
    1. Go to the link given below and download the file "codeblocks-20.03mingw-setup.exe"
    http://www.codeblocks.org/downloads/binaries/#imagesoswindows48pnglogo-microsoft-windows
    
     2. Open the setup (mostly present in the downloads of your PC) .
     3. Give licence agreement. Click on next option for choose component part. 
     4. At the end give destination folder for codeblocks setup Installation.
 - ### graphics.h Installation
    1. Go to the link given below and downloads the zip file. https://drive.google.com/file/d/16xZBvFXf7yFjxwTpuyevK1KPuLgUeZFh/view
    
    2. Extract the files
    3. Copy the  files "graphics.h" and "winbgim.h" from the folder and paste it into codeblocks -> MinGW -> include (This codeblock folder is in windows drive ,inside windows go to Program Files, there mostly will be the codeblocks folder). Copy "libbgi.a" file to the codeblocks -> MinGW -> lib.
    4. Now again go to the link https://jmeubank.github.io/tdm-gcc/ and download "MinGW.org based  tdm-gcc-10.3.0.exe, 60.2 MB" file.
    5. Open setup and select new TDM-GCC Installation and uncheck the box for the updated files.
    6. Click on next and then install.
    7. Again copy the  files "graphics.h" and "winbgim.h" and paste into TDM-GCC-32 -> include, also copy "libbgi.a" file and paste into TDM-GCC-32 -> lib. (TDM-GCC-32 is present in windows drive)
    8. Now open CodeBlocks, go to settings then compiler then toolchain exetcutables then in compiler's Installation directory and give the path of TDM-GCC-32 file .
    9. Go to linker setting and copy the given flag below in other linker option box.
   " -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 " . (Exclude inverted comma)
  - ### Game setup
 1. Download the zip file of our project by going in code option in github.
 2. Extract the files.
 3. Open the CodeBlocks click on open existing project then go to that folder where you had extracted all files.
 4. Select  "main_code.cbp" file.
 5. Run the code.

   




## Game control and rules

- ### Controls
1. Press up arrow key to move up the snake.
2. Press down arrow key to move down the snake.
3. Press right arrow key to move right the snake.
4. Press left arrow key to move left the snake.

- ### Rules
1. If snake move out of the boundry from one side then it will again comes from opposite side.
2. If snake eats itself then snake will die and player will be out.
3. If snake hit itself with obstacles then Player will be out.
4. There are foods which will be randomly genereted. If snake eat these foods then score will increase and also it's length.
5. If score becomes 100 then player will win, else player should try to keep their score as maximum as possible. 
6. Press "esc" to exit the game.
## Screenshots and Demo 
- ### Screenshots
![Loading](https://github.com/tushar3318/snake_game_project/assets/129083230/8419566c-2993-4c39-bebb-06f90a0be4ef)

                                               Loading screen

![playing](https://github.com/tushar3318/snake_game_project/assets/129083230/fe0f5c8d-10e5-419b-8742-cdd465a5fada)
                                               Playing screen
                                               
![player out](https://github.com/tushar3318/snake_game_project/assets/129083230/9f1ec02c-2586-4cea-a2c1-78de8ca7d8a5)
                                             Player out screen



- ### Demo Video
https://drive.google.com/file/d/1L7QM9O3-ZLDatHqoqofTSvd11X9Sj9J2/view?usp=drive_link

