/**
 * @file main.cpp
 * @author Erik Ström
 * @brief Main application file.
 * @version 0.1
 * @date 2018-10-30
 */

/**
 * @mainpage Game of Life
 * Implementation of 
 * <a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life">John Conways game of life</a>
 * created by Erik Ström at Mittuniverstietet. Documentation and tests are
 * written by Visar Ferizi (vife1700) and Viktor Zetterström (vize1700).
 * 
 * Everything was made as part of the course DT042G - "Metoder och verktyg i 
 * mjuvaruprojekt" given at Mittuniversitetet during fall 2018.
 */

#include <iostream>
#include "GameOfLife.h"
#include "Support/MainArgumentsParser.h"

#ifdef DEBUG
#include <memstat.hpp>
#endif

using namespace std;

/**
 * @brief Main function for applicaton.
 * @details Parses command line arguments that are passed and then creates an
 *  ApplicationValues object which is used for setting up the simulation which
 *  is then executed.
 * 
 * @param argc Number of commandline arguments.
 * @param argv Command line arguments.
 * @return int Application returnvalue.
 */
int main(int argc, char* argv[]) {

    MainArgumentsParser parser;
    ApplicationValues appValues = parser.runParser(argv, argc);

    if (appValues.runSimulation) {
        // Start simulation
        try {
            GameOfLife gameOfLife = GameOfLife(appValues.maxGenerations, appValues.evenRuleName, appValues.oddRuleName);
            gameOfLife.runSimulation();
        }
        catch(ios_base::failure &e){}

    }

    cout << endl;
    return 0;
}
