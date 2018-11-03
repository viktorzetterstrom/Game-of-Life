/**
 * @file test-RuleFactory.cpp
 * @author Visar Ferizi (vife1700@student.miun.se)
 * @brief Unit tests for the class RuleFactory.
 * @version 0.1
 * @date 2018-10-31
 */

#include <catch.hpp>
#include "GoL_Rules/RuleFactory.h"
#include "GoL_Rules/RuleOfExistence_Conway.h"
#include "GoL_Rules/RuleOfExistence_Erik.h"
#include "GoL_Rules/RuleOfExistence_VonNeumann.h"

SCENARIO("Functions of the RuleFactory class", "[RuleFactory]")
{
    GIVEN("Getting an RuleFactory object by getInstance()")

    {
        std::map<Point, Cell> cellGeneration;
        RuleFactory test = RuleFactory::getInstance();

        WHEN("No rule name/invalid rule name is given")
        {
            RuleOfExistence_Conway* conway = dynamic_cast<RuleOfExistence_Conway*> (test.createAndReturnRule(cellGeneration));

            THEN("The default RuleOfExistence_Conway should be returned")
            {
                REQUIRE(conway->getRuleName() == "conway");
            }
        }

        WHEN("Rule name 'erik' is given")
        {
            RuleOfExistence_Erik* erik = dynamic_cast<RuleOfExistence_Erik*> (test.createAndReturnRule(cellGeneration, "erik"));

            THEN("The return of getRuleName should equal erik")
            {
                REQUIRE(erik->getRuleName() == "erik");
            }
        }

        WHEN("Rule name 'von_neumann' is given")
        {
             RuleOfExistence_VonNeumann* von_neumann = dynamic_cast<RuleOfExistence_VonNeumann*> (test.createAndReturnRule(cellGeneration, "von_neumann"));

            THEN("The return of getRuleName should equal von_neumann")
            {
                REQUIRE(von_neumann->getRuleName() == "von_neumann");
            }
        }
    }
}


