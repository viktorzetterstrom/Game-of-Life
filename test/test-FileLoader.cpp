/**
* @file test-cell.cpp
* @author Visar Ferizi (vife1700@student.miun.se)
* @brief Unit tests for the class FileLoader.
* @version 0.1
* @date 2018-11-02
*/

#include <catch.hpp>
#include "../include/Support/FileLoader.h"

// Test of initialization with custom population.
SCENARIO("Loading good 5x5 cells 'good.txt'") {
	fileName = "../test/populations/good.txt";

	GIVEN("Cells loaded from file good.txt") {
		FileLoader fileLoader;
		std::map<Point, Cell> cells;
		fileLoader.loadPopulationFromFile(cells);

		THEN("Total should be (5+2)*(5+2) = 49") {
			REQUIRE(cells.size() == 49);
		}
		THEN("Cell at position (1, 2) should be alive") {
			REQUIRE(cells[Point{ 1, 2 }].isAlive() == true);
		}
		THEN("Cell at position (2, 3) should be alive") {
			REQUIRE(cells[Point{ 2, 3 }].isAlive() == true);
		}
	}
}