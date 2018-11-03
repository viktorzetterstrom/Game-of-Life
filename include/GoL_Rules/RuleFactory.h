/**
 * @file RuleFactory.h
 * @author Erik Ström
 * @brief Definition of RuleFactory, class that handles RulesOfExistence.
 * @version 0.1
 * @date 2018-10-30
 */

#ifndef RULEFACTORY_H
#define RULEFACTORY_H

#include "GoL_Rules/RuleOfExistence.h"

/**
 * @addtogroup Rules Rule classes
 * @brief Functions that decide the rules with which the simulation is run.
 * @{
 */

// Singleton class to handle creation of RulesOfExistence objects.
class RuleFactory
{
private:
    /**
     * @brief Empty private constructor
     */
    RuleFactory() {}

public:
    /**
     * @brief Returns the singleton instance of the class.
     *
     * @return RuleFactory& Reference to the static instance.
     */
    static RuleFactory& getInstance();

    /**
     * @brief Returns a pointer to a RuleOfExistence based on given cell map
     *  and ruleOfExistence.
     * @todo Add error message and handling if bad rulename is given. Default
     *  value 'conway' is never used.
     *
     * @param cells Reference to std::map with Cells mapped against Points
     * @param ruleName std::string with rulename to be used. Standard is "conway"
     * @return RuleOfExistence*
     */
    RuleOfExistence* createAndReturnRule(map<Point, Cell>& cells, string ruleName = "conway");
};

/** @} */

#endif
