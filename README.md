<!-- Readme file made by Coder 1 -->

# Game of Life

In this repository, we include the code necessary to run the game of life specified in the Embedded & Real Time Systems course taught at the MS in Automatic Control and Robotics @ UPC.

## Contents

1. [Rules](#1-rules)
2. [How to run](#2-how-to-run)
3. [Troubleshooting](#3-troubleshooting)

## 1. Rules

- Any live cell with **fewer than two live neighbours dies**, as if caused by under-population.
- Any live cell with **two or three live neighbours lives on** to the next generation
- Any live cell with **more than three live neighbours dies**, as if by over-population.
- Any **dead cell with exactly three live neighbours becomes a live cell**, as if by reproduction.

**Series of patterns**

Because of the rules specified previously, different structures get generated. They are categorized into three main groups depending if they are static(`still lifes`), if they don't move but change pattern (`oscillators`), and the last ones are those that move (`spaceships`).

<center>
<table border= 1px width  ="70%">
    <thead>
        <tr> 
            <th colspan=2><center>Still Lives</th>
            <th colspan=2><center>Oscillators</th>
            <th colspan=2><center>Spaceships</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Block</td>
            <td><img alt="block gif" src="https://upload.wikimedia.org/wikipedia/commons/9/96/Game_of_life_block_with_border.svg" />
            </td>
            <td>Blinker (period 2)</td>
            <td><img alt="block gif" src="https://upload.wikimedia.org/wikipedia/commons/9/95/Game_of_life_blinker.gif" />
            </td>
            <td>Glider</td>
            <td><img alt="block gif" src="https://upload.wikimedia.org/wikipedia/commons/f/f2/Game_of_life_animated_glider.gif" />
            </td>
        </tr>
        <!-- Row 2 -->
        <tr> 
            <td>Bee-hive</td>
            <td><img alt="Beehive gif" src="https://upload.wikimedia.org/wikipedia/commons/6/67/Game_of_life_beehive.svg" />
            </td>
            <td>Toad (period 2)</td>
            <td><img alt="Toad gif" src="https://upload.wikimedia.org/wikipedia/commons/1/12/Game_of_life_toad.gif" />
            </td>
            <td>Light-weight spaceship (LWSS)</td>
            <td><img alt="LWSS gif" src="https://upload.wikimedia.org/wikipedia/commons/3/37/Game_of_life_animated_LWSS.gif" />
            </td>
        </tr>
        <!-- Row 3 -->
        <tr>
            <td>Loaf</td>
            <td><img alt="Loaf gif" src="https://upload.wikimedia.org/wikipedia/commons/f/f4/Game_of_life_loaf.svg" />
            </td>
            <td>Beacon (period 2)</td>
            <td><img alt="Beacon gif" src="https://upload.wikimedia.org/wikipedia/commons/1/1c/Game_of_life_beacon.gif" />
            </td>
            <td>Middle-weight spaceship (MWSS)</td>
            <td><img alt="MWSS gif" src="https://upload.wikimedia.org/wikipedia/commons/4/4e/Animated_Mwss.gif" />
            </td>
        </tr>
        <!-- Row 4 -->
        <tr>
            <td>Boat</td>
            <td><img alt="Boat gif" src="https://upload.wikimedia.org/wikipedia/commons/7/7f/Game_of_life_boat.svg" />
            </td>
            <td>Pulsar (period 3)</td>
            <td><img alt="Pulsar gif" src="https://upload.wikimedia.org/wikipedia/commons/0/07/Game_of_life_pulsar.gif" />
            </td>
            <td>Heavy-weight spaceship (HWSS) </td>
            <td><img alt="HWSS gif" src="https://upload.wikimedia.org/wikipedia/commons/4/4f/Animated_Hwss.gif" />
            </td>
        </tr>
        <!-- Row 5 -->
        <tr>
            <td>Tub</td>
            <td><img alt="Tub gif" src="https://upload.wikimedia.org/wikipedia/commons/3/31/Game_of_life_flower.svg" />
            </td>
            <td>Penta-decathlon (Period 15)</td>
            <td><img alt="Penta-decathlon gif" src="https://upload.wikimedia.org/wikipedia/commons/f/fb/I-Column.gif" />
            </td>
        </tr>
    </tbody>
</table>
</center>


## 2. How to run
Start by git cloning this repository locally:
```
mkdir -p ~/git && cd ~/git
git clone https://github.com/JaumeAlbardaner/gameOfLife.git
```

Compile the C code:
```
make
```

Run it :tada:

``` 
cd ~/git/gameOfLife && ./gameDyn
```

Once you run it, you may select the dimensions of the world as well as what structure you want to simulate from:

<center>
<table border= 1px>
    <thead>
        <tr> 
            <th><center>Name</th>
            <th><center>Command #</th>
            <th><center>Preview</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><center>The R-Pentomino</td>
            <td><center>1</td>
            <td><center><img alt="block gif" src="https://upload.wikimedia.org/wikipedia/commons/1/1c/Game_of_life_fpento.svg" />
            </td>
        </tr>
        <tr>
            <td><center>Diehard</td>
            <td><center>2</td>
            <td><center><img alt="block gif" src="https://upload.wikimedia.org/wikipedia/commons/9/99/Game_of_life_diehard.svg" />
            </td>
        </tr>
        <tr>
            <td><center>Acorn</td>
            <td><center>3</td>
            <td><center><img alt="block gif" src="https://upload.wikimedia.org/wikipedia/commons/b/b9/Game_of_life_acorn.svg" />
            </td>
        </tr>
        <tr>
            <td><center>Random</td>
            <td><center>else</td>
            <td><center>-
            </td>
        </tr>
    </tbody>
</table>
</center>

## 3. Troubleshooting

So far only the **gameDyn** executable has been used enough to find any issues.

* The only issue that has been found is that requesting a large grid size may result in the Game of Life not appearing in its entirety on the screen. 

    **Fix** Set a smaller size for the board, or try rerunning the game (maybe it was just a bad unlucky initialization).