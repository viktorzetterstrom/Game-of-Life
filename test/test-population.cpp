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

// Test of initialization with good small population.
SCENARIO("Using good 5x5 population 'good.txt'") {
  fileName = "test/populations/good.txt";

  GIVEN("Population is initialized by file good.txt with default rule 'conway'") {
    Population pop;
    pop.initiatePopulation("conway");
    
    THEN("Total should be (5+2)*(5+2) = 49") {
      REQUIRE(pop.getTotalCellPopulation() == 49);
    }
    THEN("Cell at position (0, 0) should be dead and a rimcell") {
      Point p;
      p.x = 0;
      p.y = 0;
      REQUIRE(pop.getCellAtPosition(p).isAlive() == false);
      REQUIRE(pop.getCellAtPosition(p).isRimCell() == true);
    }
    THEN("Cell at position (3, 3) should be dead") {
      Point p;
      p.x = 3;
      p.y = 3;
      REQUIRE(pop.getCellAtPosition(p).isAlive() == false);
    }
    THEN("Cell at position (1, 2) should be alive") {
      Point p;
      p.x = 1;
      p.y = 3;
      REQUIRE(pop.getCellAtPosition(p).isAlive() == false);
    }
  }
}

// Test of initialization with good larger population
SCENARIO("Using good 10x10 population 'good2.txt'") {
  fileName = "test/populations/good2.txt";

  GIVEN("Population is initialized by file good2.txt with default rule 'conway'") {
    Population pop;
    pop.initiatePopulation("conway");
    
    THEN("Total should be (10+2)*(10+2) = 144") {
      REQUIRE(pop.getTotalCellPopulation() == 144);
    }
    THEN("Cell at position (0, 0) should be dead and a rimcell") {
      Point p;
      p.x = 0;
      p.y = 0;
      REQUIRE(pop.getCellAtPosition(p).isAlive() == false);
      REQUIRE(pop.getCellAtPosition(p).isRimCell() == true);
    }
    THEN("Cell at position (3, 3) should be alive") {
      Point p;
      p.x = 3;
      p.y = 3;
      REQUIRE(pop.getCellAtPosition(p).isAlive() == true);
    }
    THEN("Cell at position (10, 10) should be dead") {
      Point p;
      p.x = 10;
      p.y = 10;
      REQUIRE(pop.getCellAtPosition(p).isAlive() == false);
    }
  }
}

// Test with empty file and non-existing file
SCENARIO("If empty or non-existing file is given error should be thrown") {
  GIVEN("Empty file is given at program start") {
    fileName = "test/populations/empty.txt";
    Population pop;
    
    THEN("Error should be thrown when initializing the population") {
      REQUIRE_THROWS(pop.initiatePopulation("conway"));
    }
  }

  GIVEN("Non-existing file is given at program start") {
    fileName = "test/populations/doesNotExist.txt";
    Population pop;

    THEN("Error should be thrown when initializing the population") {
      REQUIRE_THROWS(pop.initiatePopulation("conway"));
    }
  }
}

// Test with bad files
SCENARIO("File with bad/corrupted input is given") {
  GIVEN("File with bad input is given at program start") {
    fileName = "test/populations/bad.txt";
    Population pop;
    
    THEN("Error should be thrown when initializing the population") {
      REQUIRE_THROWS(pop.initiatePopulation("conway"));
    }
  }

  GIVEN("File with another bad input is given at program start") {
    fileName = "test/populations/bad2.txt";
    Population pop;
    
    THEN("Error should be thrown when initializing the population") {
      REQUIRE_THROWS(pop.initiatePopulation("conway"));
    }
  }
}