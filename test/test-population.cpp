/**
 * @file test-cell.cpp
 * @author Viktor Zetterström (vize1500@student.miun.se)
 * @brief Unit tests for the class Population.
 * @version 0.1
 * @date 2018-10-31
 */

#include <catch.hpp>
#include "../include/Cell_Culture/Population.h"

// Test of board size and standard initialization.
SCENARIO("Using a default population size 80x24 (defined in globals.cpp") {
  GIVEN("Default population that is initialized with default rule 'conway'") {
    Population pop;
    pop.initiatePopulation("conway");

    THEN("Total should be (80+2)*(24+2) = 2132 (Extra 2 added for rim cells)") {
      REQUIRE(pop.getTotalCellPopulation() == 2132);
    }
  }
}

// Test of initialization with custom population.
SCENARIO("Using good 5x5 population 'good.txt'") {
  fileName = "test/populations/good.txt";

  GIVEN("Population is initialized by file good.txt") {
    Population pop;
    pop.initiatePopulation("conway");
    
    THEN("Total should be (5+2)*(5+2) = 49") {
      REQUIRE(pop.getTotalCellPopulation() == 49);
    }
    THEN("Cell at position (0, 1) should be alive") {
      Point p;
      p.x = 0;
      p.y = 1;
      REQUIRE(pop.getCellAtPosition(p).isAlive() == true);
    }
    THEN("Cell at position (1, 2) should be alive") {
      Point p;
      p.x = 2;
      p.y = 1;
      REQUIRE(pop.getCellAtPosition(p).isAlive() == true);
    }
  }
}