/**
  * @file RuleOfExistence_Conway.h
  * @author Erik Ström
  * @date October 2017
  * @version 0.1
  * @brief Functions that decide the rules with which the simulation is run.
  */

#ifndef GAMEOFLIFE_RULEOFEXISTENCE_CONWAY_H
#define GAMEOFLIFE_RULEOFEXISTENCE_CONWAY_H

#include "RuleOfExistence.h"

/**
 * @addtogroup Rules Rule functions
 * @brief Functions that decide the rules with which the simulation is run.
 * @{
 */


/*
Conway's RuleOfExistence, applying actions based on PopulationLimits on all 8 surrounding neighbours.

Concrete RuleOfExistence, implementing Conway's rule of determining alive neighbours surrounding the cell
by checking all 8 directions, 4 x Cardinal + 4 x Diagonal. PopulationLimits are set as;

*UNDERPOPULATION	< 2*	**Cell dies of loneliness**
*OVERPOPULATION		> 3*	**Cell dies of overcrowding**
*RESURRECTION		= 3*	**Cell is infused with life**
*/

/**
  * @brief RuleOfExistence derived class that follows the Conway rules
  * @details Conway's RuleOfExistence, applying actions based on PopulationLimits on all 8 surrounding neighbours.
  * Concrete RuleOfExistence, implementing Conway's rule of determining alive neighbours surrounding the cell
  * by checking all 8 directions, 4 x Cardinal + 4 x Diagonal. PopulationLimits are set as;
  * UNDERPOPULATION	    < 2*  	**Cell dies of loneliness**
  * OVERPOPULATION	    > 3*	**Cell dies of overcrowding**
  * RESURRECTION		= 3*	**Cell is infused with life**
 */
class RuleOfExistence_Conway : public RuleOfExistence
{
private:

public:
/**
 * @brief Construct a new RuleOfExistence_Conway object
 * @details Passes the cell generation it is given and applies the rule to it
 * the cell generation is then passed to base constructor together with the 
 * rule name "conway", the population limits and ALL_DIRECTIONS.
 * @param cells the cell generation that the rule will be applied on
 */
    RuleOfExistence_Conway(map<Point, Cell>& cells)
            : RuleOfExistence({ 2,3,3 }, cells, ALL_DIRECTIONS, "conway") {}
    /**
     * @brief override of the base class destructor that Destroys the RuleOfExistence_Conway object
     * 
     */
    ~RuleOfExistence_Conway() {}

    /**
     * @brief Execute rule specific for Conway
     * @details decides rules and executes them for all non rim cells
     * and sets right colors depending on cells state
     * @test should determine what the next action should be for the cells
     * @test should set the according color for the action
     * @test should take all eight neighbours into account
     */
    void executeRule();
};
/** @} */

#endif //GAMEOFLIFE_RULEOFEXISTENCE_CONWAY_H
