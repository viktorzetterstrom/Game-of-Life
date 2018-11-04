This is an implementation of [John Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) created by Erik Ström at Mittuniversitetet. Documentation and tests were written by Visar Ferizi (vife1700) and Viktor Zetterström (vize1500). Documentation was created with [Doxygen](http://www.doxygen.org) and test scripts using [Catch](https://github.com/catchorg/Catch2). Everything was made as part of the course DT042G - "Metoder och verktyg i mjuvaruprojekt" given at Mittuniversitetet during fall 2018.

# Instructions
## How to build the program
First just clone the repo from bitbucket. The program is built using CMake and the CMakeLists.txt file. If CMake is installed on your system, just navigate to the project folder and use CMake to build. To run the tests the framework Catch is needed, in the project it is included in the path $tools_include, but you can include it any way you want, but you might have to do some slight alterations.

## How to run the program
The program is run using the terminal, navigate to the folder where you build the project and type `%GameOfLife` to run.
There are several options available to customize the program, you can change the number of generations, the size of the cell-population as well as the rules. It is also possible to have different rules on even and odd generation numbers. Finally, you can create a population of your own and run the simulation by providing a file, an example of such a file has been provided, _Population_Seed.txt_.
### Command line options
* ` -h` - Displays help about the application, does not run the simulation.
* ` -g <no. of generations>` - Set number of generations to simulate.
* ` -s <size, e.g. 80x24>` - Customize the size of the board.
* ` -f <filename>` - Specify file for custom population.
* ` -er <rule>` - Set rule for even generations. See "Rules" for more info.
* ` -or <rule>` - Set rule for odd generations. See "Rules" for more info.
  
### Rules
#### `conway`
Standard Game of Life rules, cell live, die and are reborn based on status of its neighbouring cells. Depending on the amount of alive neighbours the following things can happen:
  * Less than 2 - %Cell dies of loneliness.
  * More then 3 - %Cell dies of overcrowding.
  * Exactly 3 - %Cell lives or is reborn.

####`von_neumann`
The Von Neumann rules work in the exact same way as the Conway rules, with one change: Only the neighbours in the cardinal directions are checked (north, south, east, west).

#### `erik`
Uses the same rules as Conway, but modifies cells that have lived a long time. If a cell has lived a long time its character is changed to an E, and if it lives even longer gets a special color, only one cell can get upgraded to special color per generation.

## How to test the program
All the test script were written with Catch. To run the test simply go to the folder in which you built the project and run `GameOfLife-tests`. You will notice that not all classes are currently passing all their assertions, there is still a fair amount of work to be done. You can also run tests for individual classes by for example running `GameOfLife-tests [%Cell]`, where %Cell can be replaced with the class you want to test.