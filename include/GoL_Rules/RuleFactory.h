/*
 * Filename    RuleFactory.h
 * Author      Erik Ström
 * Date        October 2017
 * Version     0.1
*/

#ifndef RULEFACTORY_H
#define RULEFACTORY_H

#include "GoL_Rules/RuleOfExistence.h"

/**
 * @addtogroup Rules Rule functions
 * @brief Functions that decide the rules with which the simulation is run.
 * @{
 */

// Singleton class to handle creation of RulesOfExistence objects.
class RuleFactory
{
private:
    RuleFactory() {}

public:
    static RuleFactory& getInstance();
    RuleOfExistence* createAndReturnRule(map<Point, Cell>& cells, string ruleName = "conway");
};

/** @} */

#endif