/**
 * @file test-cell.cpp
 * @author Viktor Zetterström (vize1500@student.miun.se)
 * @brief Unit tests for the class Cell.
 * @version 0.1
 * @date 2018-10-31
 */
#include <catch.hpp>
#include "../include/Cell_Culture/Cell.h"

// Scenario when using a normal cell object and making changes to it.
SCENARIO("Using a Cell object") {
  GIVEN("Standard cell created with default values") {
    Cell cell;
    
    THEN("Its age should be 0") {
      REQUIRE(cell.getAge() == 0);
    }
    THEN("It should be dead") {
      REQUIRE(cell.isAlive() == false);
    }
    THEN("Its value should be '#'") {
      REQUIRE(cell.getCellValue() == '#');
    }
    THEN("It should not be a rimcell") {
      REQUIRE(cell.isRimCell() == false);
    }
    THEN("Its color should be DEAD") {
      REQUIRE(cell.getColor() == STATE_COLORS.DEAD);
    }
    THEN("The next action should be DO_NOTHINg") {
      REQUIRE(cell.getNextGenerationAction() == DO_NOTHING);
    }

    WHEN("The cell value is changed and it is updated to live") {
      cell.setNextGenerationAction(GIVE_CELL_LIFE);
      cell.setNextColor(STATE_COLORS.LIVING);
      cell.setNextCellValue('X');
      cell.setIsAliveNext(true);

      THEN("The next action should be for the cell to live") {
        REQUIRE(cell.getNextGenerationAction() == GIVE_CELL_LIFE);
      }
      THEN("The cell should come alive next generation") {
        REQUIRE(cell.isAliveNext() == true);
      }

      AND_WHEN("The state of the cell is updated") {
        cell.updateState();
      
        THEN("Cell should be alive") {
          REQUIRE(cell.isAlive() == true);
        }
        THEN("The color should be LIVING") {
          REQUIRE(cell.getColor() == STATE_COLORS.LIVING);
        }
        THEN("The cell value should be updated") {
          REQUIRE(cell.getCellValue() == 'X');
        }
        THEN("It should have aged") {
          REQUIRE(cell.getAge() == 1);
        }
        THEN("It should still not be a rim cell") {
          REQUIRE(cell.isRimCell() == false);
        }
      }
    }

    WHEN("The cell is updated do die and updated") {
      cell.setNextGenerationAction(KILL_CELL);
      cell.setIsAliveNext(false);
      cell.setNextColor(STATE_COLORS.DEAD);

      cell.updateState();

      THEN("It should be dead") {
        REQUIRE(cell.isAlive() == false);
      }
      THEN("Its color should be DEAD") {
        REQUIRE(cell.getColor() == STATE_COLORS.DEAD);
      }
    }
  }
}

// Scenario when using a rim cell.
SCENARIO("Using a rim cell") {
  GIVEN("A rim cell") {
    Cell rimCell(true);

    THEN("It should identify as a rim cell") {
      REQUIRE(rimCell.isRimCell() == true);
    }
    THEN("It should be dead") {
      REQUIRE(rimCell.isAlive() == false);
    }
    THEN("It should have color DEAD") {
      REQUIRE(rimCell.getColor() == STATE_COLORS.DEAD);
    }
    
    WHEN("Changes are tried to be made and the cell updated") {
      rimCell.setNextCellValue('X');
      rimCell.setNextGenerationAction(GIVE_CELL_LIFE);
      rimCell.setNextColor(STATE_COLORS.ELDER);
      rimCell.setIsAliveNext(true);

      rimCell.updateState();

      THEN("The cell should have the same value") {
        REQUIRE(rimCell.getCellValue() == '#');
      }
      THEN("The cell should still be dead") {
        REQUIRE(rimCell.isAlive() == false);
      }
      THEN("The cell color should still be DEAD") {
        REQUIRE(rimCell.getColor() == STATE_COLORS.DEAD);
      }
      THEN("The cell should still be a rim cell") {
        REQUIRE(rimCell.isRimCell() == true);
      }
      THEN("The cell should not have aged") {
        REQUIRE(rimCell.getAge() == 0);
      }
    }
  }
}