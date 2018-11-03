/**
 * @file test-RuleOfExistence_VonNeumann.cpp
 * @author Visar Ferizi (vife1700@student.miun.se)
 * @brief Unit tests for the class RuleOfExistence_VonNeumann
 * @version 0.1
 * @date 2018-10-02
 */

#include <catch.hpp>
#include "GoL_Rules/RuleFactory.h"
#include "GoL_Rules/RuleOfExistence_VonNeumann.h"

SCENARIO("RuleOfExistence_VonNeumann testcase1", "[von_neumann]")
{
	GIVEN("Spare population upgrade")
	{
		std::map<Point, Cell> cells;
		RuleFactory test = RuleFactory::getInstance();

		WHEN("Cell values are set as [0 0;1 0]")
		{
			cells[Point{ 0, 0 }] = Cell(true);
			cells[Point{ 0, 1 }] = Cell(true);
			cells[Point{ 0, 2 }] = Cell(true);
			cells[Point{ 0, 3 }] = Cell(true);
			cells[Point{ 3, 0 }] = Cell(true);
			cells[Point{ 3, 1 }] = Cell(true);
			cells[Point{ 3, 2 }] = Cell(true);
			cells[Point{ 3, 3 }] = Cell(true);
			cells[Point{ 1, 0 }] = Cell(true);
			cells[Point{ 2, 0 }] = Cell(true);
			cells[Point{ 1, 3 }] = Cell(true);
			cells[Point{ 2, 3 }] = Cell(true);

			cells[Point{ 1, 1 }] = Cell(false, IGNORE_CELL);
			cells[Point{ 1, 2 }] = Cell(false, DO_NOTHING);
			cells[Point{ 2, 1 }] = Cell(false, GIVE_CELL_LIFE);
			cells[Point{ 2, 2 }] = Cell(false, KILL_CELL);

			RuleOfExistence_VonNeumann* rule = dynamic_cast<RuleOfExistence_VonNeumann*> (test.createAndReturnRule(cells, "von_neumann"));
			
			THEN("Cell at position (1, 1) should be dead") {
				REQUIRE(cells[Point{ 1, 1 }].isAlive() == false);
			}
			THEN("Cell at position (1, 2) should be dead") {
				REQUIRE(cells[Point{ 1, 2 }].isAlive() == false);
			}
			THEN("Cell at position (2, 1) should be alive") {
				REQUIRE(cells[Point{ 2, 1 }].isAlive() == true);
			}
			THEN("Cell at position (2, 1) should be 1 year old") {
				REQUIRE(cells[Point{ 2, 1 }].getAge() == 1);
			}
			THEN("Cell at position (2, 2) should be dead") {
				REQUIRE(cells[Point{ 2, 2 }].isAlive() == false);
			}

			rule->executeRule();
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					cells[Point{ i, j }].updateState();
				}
			}

			THEN("Cell at position (2, 1) should be dead") {
				REQUIRE(cells[Point{ 2, 1 }].isAlive() == false);
			}
		}
	}
}

SCENARIO("RuleOfExistence_VonNeumann testcase2", "[von_neumann]")
{
	GIVEN("Dense population upgrade")
	{
		std::map<Point, Cell> cells;
		RuleFactory test = RuleFactory::getInstance();

		WHEN("Cell values are set as [1 1;1 0]")
		{
			cells[Point{ 0, 0 }] = Cell(true);
			cells[Point{ 0, 1 }] = Cell(true);
			cells[Point{ 0, 2 }] = Cell(true);
			cells[Point{ 0, 3 }] = Cell(true);
			cells[Point{ 3, 0 }] = Cell(true);
			cells[Point{ 3, 1 }] = Cell(true);
			cells[Point{ 3, 2 }] = Cell(true);
			cells[Point{ 3, 3 }] = Cell(true);
			cells[Point{ 1, 0 }] = Cell(true);
			cells[Point{ 2, 0 }] = Cell(true);
			cells[Point{ 1, 3 }] = Cell(true);
			cells[Point{ 2, 3 }] = Cell(true);

			cells[Point{ 1, 1 }] = Cell(false, GIVE_CELL_LIFE);
			cells[Point{ 1, 2 }] = Cell(false, GIVE_CELL_LIFE);
			cells[Point{ 2, 1 }] = Cell(false, GIVE_CELL_LIFE);
			cells[Point{ 2, 2 }] = Cell(false, KILL_CELL);

			RuleOfExistence_VonNeumann* rule = dynamic_cast<RuleOfExistence_VonNeumann*> (test.createAndReturnRule(cells, "von_neumann"));

			rule->executeRule();
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					cells[Point{ i, j }].updateState();
				}
			}

			THEN("Cell at position (2, 1) should be dead") {
				REQUIRE(cells[Point{ 2, 1 }].isAlive() == false);
			}
		}
	}
}


