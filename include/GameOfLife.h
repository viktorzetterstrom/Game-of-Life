/**
 * @file GameOfLife.h
 * @author Erik Ström
 * @brief Definition of GameOfLife, main simulation class.
 * @version 0.1
 * @date 2018-10-30
 */

#ifndef GameOfLifeH
#define GameOfLifeH

#include "Cell_Culture/Population.h"
#include "ScreenPrinter.h"
#include <string>

/**
 * @brief The heart of the simulation, interconnects the main execution with 
 *  the graphical presentation.
 * 
 * @details Creates and manages Population and the ScreenPrinter instances. Will
 *  instruct the Population of cells to keep updating as long as the specified
 *  number of generations is not reached, and for each iteration instruct
 *  ScreenPrinter to write the information on screen.
 */
class GameOfLife {

private:
    /**
     * @brief Population representing and managing the cells.
     */
    Population population;

    /**
     * @brief Screenprinter object for managing screen output.
     */
    ScreenPrinter& screenPrinter;

    /**
     * @brief Number of generations simulated.
     */
    int nrOfGenerations;

public:
    /**
     * @brief Constructor
     * @details Initiates the population with the given number of generations
     *  and the rules supplied.
     * 
     * @param nrOfGenerations Number of generations to simulate.
     * @param evenRuleName Rule of existence for even generations.
     * @param oddRuleName Rule of existence for odd generations.
     */
    GameOfLife(int nrOfGenerations, string evenRuleName, string oddRuleName);

    /**
     * @brief Runs the simulation.
     * @details Until the set number of generations is reached the simulation is
     *  continuously clearing the screen, printing the population and updating
     *  the population.
     */
    void runSimulation();

};

#endif
