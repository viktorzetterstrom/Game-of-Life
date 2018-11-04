/**
  * @file RuleOfExistence_Erik.h
  * @author Erik Ström
  * @date October 2017
  * @version 0.1
  * @brief Erik's RuleOfExistence, based on Conway's rule while also differentiate the appearance of cells based on their age.
  */

#ifndef GAMEOFLIFE_RULEOFEXISTENCE_ERIK_H
#define GAMEOFLIFE_RULEOFEXISTENCE_ERIK_H

#include "RuleOfExistence.h"

/**
 * @addtogroup Rules Rule classes
 * @brief Functions that decide the rules with which the simulation is run.
 * @{
 */


/**
 * @class RuleOfExistence_Erik derrived from RuleOfExistence
 * @brief Concrete Rule of existence, implementing Erik's rule.
 * @details 
 * Sentient lifeforms is rarely created, but once in a while a cell has lived enough generations to become as wise as Erik.

- Once a cell has survived a minimum amount of generations it will recieve a color to distinguish itself from younger ones.
- If such a cell would then survive another set amount of generations, it will be marked with a value of **E**.
- In the extreme case, where the cell has achieved above requirements and is determined to be the oldest living cell, it will
  become a **prime elder**, and have its color changed once again. A generation may only have one such elder.
Uses same population limits as Conway rule.
 */
class RuleOfExistence_Erik : public RuleOfExistence
{
private:
    char usedCellValue;	/*!< char value to differentiate very old cells */ 
    Cell* primeElder;

    /**
     * @brief determines the visualation of the passed cell population according to current state based on passed ACTION
     * 
     * @param cell current cell generation
     * @param action action to be taken
     */
    void erikfyCell(Cell& cell, ACTION action);
    void setPrimeElder(Cell* newElder); /*!< visualises the set Prime Elder */ 

public:
    /**
     * @brief Construct a new RuleOfExistence_Erik object
     * @details Passes the cell generation it is given and applies the rule to it
     * the cell generation is then passed to base constructor together with the 
     * rule name "erik", the population limits and global const ALL_DIRECTIONS and the character 'E' to mark the Elder.
     * 
     * @param cells cell generation on which the rule will be set
     */
    RuleOfExistence_Erik(map<Point, Cell>& cells)
            : RuleOfExistence({2,3,3}, cells, ALL_DIRECTIONS, "erik"), usedCellValue('E') {
        primeElder = nullptr;
    }
     /**
     * @brief override of the base class destructor that Destroys the RuleOfExistence_Erik object
     * 
     */
    ~RuleOfExistence_Erik() {}

    /**
     * @brief Execute the rule specific for Erik
     * @details decides rules and executes them for all non rim cells
     * and sets right colors depending on cells state
     * @test should determine what the next action should be for the cells
     *       should set the according color for the action
     *       should take all eight neighbours into account
     *       cells with age >4 & <10 are considered as old and are colored with cyan
     *       cells with age >9 will get the character 'E' as visualisation 
     *       if a cell is considered 'old' and is marked with 'E' and is the oldest cell, it will be set as Prime Elder and change color to magenta
     *       their should only be one Prime Elder in every generation
     *       
     */
    void executeRule();
};
/** @} */

#endif //GAMEOFLIFE_RULEOFEXISTENCE_ERIK_H
