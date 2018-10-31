/**
 * @file test-cell.cpp
 * @author Viktor Zetterström (vize1500@student.miun.se)
 * @brief Unit tests for the class Cell.
 * @version 0.1
 * @date 2018-10-31
 */
#include <catch.hpp>
#include "../include/Cell_Culture/Cell.h"

SCENARIO("Using a Cell object") {
  GIVEN("Standard cell created with default values") {
    Cell cell;
    
    THEN("Its age should be 0") {
      REQUIRE(cell.getAge() == 0);
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

    WHEN("The values for next generation are changed and the cell is updated") {
      cell.setNextGenerationAction(GIVE_CELL_LIFE);
      cell.setNextColor(STATE_COLORS.LIVING);
      cell.setNextCellValue('X');
      cell.setIsAliveNext(true);

      THEN("The values should match the changes") {
        REQUIRE(cell.getNextGenerationAction() == GIVE_CELL_LIFE);
        REQUIRE(cell.isAliveNext() == true);
      }

      AND_WHEN("The state of the cell is updated") {
        cell.updateState();

        THEN("The current details of the cell should be updated") {
          REQUIRE(cell.isAlive() == true);
          REQUIRE(cell.getColor() == STATE_COLORS.LIVING);
          REQUIRE(cell.getCellValue() == 'X');
          REQUIRE(cell.isRimCell() == false);
        }
      }
    }
  }
}