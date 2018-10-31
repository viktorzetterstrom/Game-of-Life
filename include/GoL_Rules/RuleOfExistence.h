/**
  * @file RuleOfExistence.h
  * @author Erik Ström
  * @date October 2017
  * @version 0.1
  * @brief rules to determine the fate of the cells
  */
#ifndef RULEOFEXISTENCE_H
#define RULEOFEXISTENCE_H

#include<string>
#include<map>
#include<vector>
#include "Cell_Culture/Cell.h"
#include "Support/Globals.h"
using namespace std;


/**
  * @addtogroup Rules Rule functions
  * @brief Functions that decide the rules with which the simulation is run.
  * @{
  */


/**
  *@struct PopulationLimits
  *@brief Data structure for storing population limits. Used by rules to determine what ACTION to make.
  */
struct PopulationLimits {
    int UNDERPOPULATION, /*!< cell dies of loneliness */
            OVERPOPULATION, /*!< cell dies of over crowding */
            RESURRECTION; /*!< cell lives on / is resurrected */
};

/**
  *@struct Directions
  *@brief Data structure for storing directional values. Used by rules to determine neighbouring cells.
  */
struct Directions {
    int HORIZONTAL, VERTICAL;
};

/**
  *@brief Vector containing all possible directions (neighbouring cells)
  *@details Directions N, E, S, W, NE, SE, SW, NW
  */
const vector<Directions> ALL_DIRECTIONS{ { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 },{ 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } };

/**
  *@brief Vector containing the cardinal directions
  *@details Directions N, E, S, W
  */
const vector<Directions> CARDINAL{ { 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 } };

/**
  *@brief Vector containing the diagonal directions
  *@details Directions NE, SE, SW, NW
  */
const vector<Directions> DIAGONAL{ { 1,-1 },{ 1,1 },{ -1,1 },{ -1,-1 } };

/**
  *@class RuleOfExistence
  *@brief Abstract base class, upon which concrete rules will derive.
  *@details The derivations of RuleOfExistence is what determines the culture of Cell Population. Each rule implements
  *specific behaviours and so may execute some parts in different orders. In order to accommodate this
  *requirement RuleOfExistence will utilize a **Template Method** desing pattern, where all derived rules
  *implements their logic based on the virtual method executeRule().
  */

class RuleOfExistence {
protected:
    string ruleName;
    map<Point, Cell>& cells; /*!< Reference to the population of cells */
    const PopulationLimits POPULATION_LIMITS; /*!< Amounts of alive neighbouring cells, with specified limits */
    const vector<Directions>& DIRECTIONS; /*!< The directions, by which neighbouring cells are identified */
   
    /**
     * @brief Checks how many alive neighbours of a cell that exist
     * @param currentPoint The struct Point/position of a certain cell whos neighbours should be checked
     * @return Returns an int with the amount of neighbouring cells that are alive
     * @test should return the amount of alive neighbouring cells
     */
    int countAliveNeighbours(Point currentPoint);

    /**
     * @brief Determines the next action that should happen for the current cell
     * @details Based on the alive neighbouring cells and the limit for
     * populations in the chosen rule, it should determine what action should be taken
     * @param aliveNeighbours amount of alive neighbours
     * @param isAlive true if cell is alive, false if not
     * @return enum ACTION with the action that should be taken next
     * @test the return should harmonize with the applied rule
     */
    ACTION getAction(int aliveNeighbours, bool isAlive);

public:

    /**
     * @brief Construct a new Rule Of Existence object
     * @param limits the limit of the population to be used
     * @param cells the cell population
     * @param DIRECTIONS directions to neighbours
     * @param ruleName the rule that is applied
     */
    RuleOfExistence(PopulationLimits limits, map<Point, Cell>& cells, const vector<Directions>& DIRECTIONS, string ruleName)
            : POPULATION_LIMITS(limits), cells(cells), DIRECTIONS(DIRECTIONS), ruleName(ruleName) {}
    
    /**
     * @brief Destroy the Rule Of Existence object
     */
    virtual ~RuleOfExistence() {}

    // Execute rule, in order specific to the concrete rule, by utilizing template method DP
    /**
     * @brief Execute rule, in order specific 
     * to the concrete rule, by utilizing template method DP
     * @details Pure Virtual function that will be used by one of the derived classes
     */
    virtual void executeRule() = 0;

    string getRuleName() { return ruleName; }
};

/** @} */

#endif