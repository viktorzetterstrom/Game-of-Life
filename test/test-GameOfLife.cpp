/**
* @file test-GameOfLife.cpp
* @author Visar Ferizi (vife1700@student.miun.se)
* @brief Unit tests for the class GameOfLife.
* @version 0.1
* @date 2018-11-02
*/

#include <catch.hpp>
#include "../include/GameOfLife.h"

// Test of initialization with custom population.
SCENARIO("Run game on good 5x5 cells 'good.txt'") {
	fileName = "../test/populations/good.txt";

	GIVEN("Cells loaded from file good.txt") {
		GameOfLife gameOfLife = GameOfLife(5, "conway", "erik");
		gameOfLife.runSimulation();

		THEN("Cell at position (1, 3) should be alive and 4 years old") {
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 1, 3 }).isAlive() == true);
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 1, 3 }).getAge() == 4);
		}

		THEN("Cell at position (5, 3) should be alive and 4 years old") {
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 5, 3 }).isAlive() == true);
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 5, 3 }).getAge() == 4);
		}

		THEN("Cell at position (2, 1) should be alive and 2 years old") {
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 2, 1 }).isAlive() == true);
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 2, 1 }).getAge() == 2);
		}

		THEN("Cell at position (4, 5) should be alive and 2 years old") {
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 4, 5 }).isAlive() == true);
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 4, 5 }).getAge() == 2);
		}

		THEN("Cell at position (1, 2) should be alive and 1 years old") {
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 1, 2 }).isAlive() == true);
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 1, 2 }).getAge() == 1);
		}

		THEN("Cell at position (5, 4) should be alive and 1 years old") {
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 5, 4 }).isAlive() == true);
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 5, 4 }).getAge() == 1);
		}

		THEN("Cell at position (3, 3) should be dead") {
			REQUIRE(gameOfLife.getPopulation().getCellAtPosition(Point{ 3, 3 }).isAlive() == false);
		}
	}
}