/**
 * @file GameOfLife.cpp
 * @author Erik Ström
 * @brief Implementation of GameOfLife, main simulation class.
 * @version 0.1
 * @date 2018-10-30
 * @copyright Copyright (c) 2018
 */

#include "GameOfLife.h"
#include <thread>
#include <chrono>
#include "GoL_Rules/RuleFactory.h"

GameOfLife::GameOfLife(int nrOfGenerations, string evenRuleName, string oddRuleName)
        : nrOfGenerations(nrOfGenerations), screenPrinter(ScreenPrinter::getInstance()) {

    // initiate population
    population.initiatePopulation(evenRuleName, oddRuleName);
}

/*
* Run the simulation for as many generations as been set by the user (default = 500).
* For each iteration; calculate population changes and print the information on screen.
*/
void GameOfLife::runSimulation() {

    // Clears the terminal
    screenPrinter.clearScreen();

    // Print generation zero
    screenPrinter.printBoard(population);

    // For each generation
    while (population.calculateNewGeneration() < nrOfGenerations) {
        // Print the calculated generation
        screenPrinter.printBoard(population);

        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}