/**
  * @file RuleOfExistence_VonNeumann.h
  * @author Erik Ström
  * @date October 2017
  * @version 0.1
  * @brief Von Neumann's RuleOfExistence, differs from Conway in that only 4 neighbours are accounted for.
  */

#ifndef GAMEOFLIFE_RULEOFEXISTENCE_VONNEUMANN_H
#define GAMEOFLIFE_RULEOFEXISTENCE_VONNEUMANN_H

#include "RuleOfExistence.h"

/**
 * @addtogroup Rules Rule classes
 * @brief Functions that decide the rules with which the simulation is run.
 * @{
 */




/**
 * @class RuleOfExistence_VonNeumann derrived from RuleOfExistence
 * @brief Concrete Rule of existence, implementing Von Neumann's rule.
 * @details Only difference from Conway is that neighbours are determined using only cardinal directions (N, E, S, W).
 */
class RuleOfExistence_VonNeumann : public RuleOfExistence
{
private:

public:
/**
     * @brief Construct a new RuleOfExistence_VonNeumann object
     * @details Passes the cell generation it is given and applies the rule to it
     * the cell generation is then passed to base constructor together with the 
     * rule name "von_neumann", the population limits and global const CARDINAL.
     * 
     * @param cells cell generation on which the rule will be set
     */
    RuleOfExistence_VonNeumann(map<Point, Cell>& cells)
            : RuleOfExistence({ 2,3,3 }, cells, CARDINAL, "von_neumann") {}

    /**
     * @brief override of the base class destructor that Destroys the RuleOfExistence_VonNeumann object
     * 
     */
    ~RuleOfExistence_VonNeumann() {}

   /**
     * @brief Execute the rule specific for VonNeumann
     * @details decides rules and executes them for all non rim cells
     * and sets right colors depending on cells state
     * @test should determine what the next action should be for the cells
     * @test should set the according color for the action
     * @test should take only the four diagonal neighbours into account
     */
    void executeRule();
};
/** @} */

#endif //GAMEOFLIFE_RULEOFEXISTENCE_VONNEUMANN_H
