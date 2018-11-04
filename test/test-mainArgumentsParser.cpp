/**
 * @file test-mainArgumentsParser.cpp
 * @author Viktor Zetterström
 * @author Visar Ferizi
 * @brief Test scripts for testing the class MainArgumentsParser
 * @details The parser does not check the actual argument values provided with
 *  the argument, this is therefore not tested. Only that the correct values are 
 *  set based upon the argument provided. Non-existing argument is tested.
 * @version 0.1
 * @date 2018-11-01
 */

#include <catch.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include "Support/MainArgumentsParser.h"

// Om win, använd _strdup istället för strdup
#ifdef _WIN32
  #define strdup _strdup
#endif


SCENARIO("Testing MainArgumentsParser", "[MainArgumentsParser]") {
  GIVEN("Instance of MainArgumentsParser") {
    MainArgumentsParser parser;

    WHEN("It is passed -f, file argument") {
      // Create own argc and argv to parse.
      int argc = 3;
      char* argv[] = {strdup("./GameOfLife"), strdup("-f"), strdup("Population_Seed.txt")};

      // Run parser.
      ApplicationValues appValues = parser.runParser(argv, argc);
      
      THEN("Filename should be set to argument value and simulation should run") {
        REQUIRE(fileName == "Population_Seed.txt");
        REQUIRE(appValues.runSimulation == true);
      } 
    }

    WHEN("It is passed -h, help argument") {
      // See what is printed with ostringstream and streambuf.
      std::ostringstream outStream;
      std::streambuf* outBuffer = std::cout.rdbuf();
      std::cout.rdbuf(outStream.rdbuf());
      
      // Create own argc and argv to parse.
      int argc = 2;
      char* argv[] = {strdup("./GameOfLife"), strdup("-h")};

      // Run parser.
      ApplicationValues appValues = parser.runParser(argv, argc);

      // Restore buffer.
      std::cout.rdbuf(outBuffer);

      THEN("Options should be printed and simulation should not run"){
        REQUIRE(outStream.str().length() > 0);
        REQUIRE(appValues.runSimulation == false);
      }
    }

    WHEN("It is passed -s, size argument.") {
      // Create own argc and argv to parse.
      int argc = 3;
      char* argv[] = {strdup("./GameOfLife"), strdup("-s"), strdup("10x10")};

      // Run parser.
      ApplicationValues appValues = parser.runParser(argv, argc);

      THEN("The dimensions should be updated and simulation should run.") {
        REQUIRE(WORLD_DIMENSIONS.WIDTH == 10);
        REQUIRE(WORLD_DIMENSIONS.HEIGHT == 10);
        REQUIRE(appValues.runSimulation == true);
      }
    }

    WHEN("It is passed -g, number of generations argument") {
      // Create own argc and argv to parse.
      int argc = 3;
      char* argv[] = {strdup("./GameOfLife"), strdup("-g"), strdup("1337")};

      // Run parser.
      ApplicationValues appValues = parser.runParser(argv, argc);

      THEN("The generations should be updated and simulation should run.") {
        REQUIRE(appValues.maxGenerations == 1337);
        REQUIRE(appValues.runSimulation == true);
      }
    }

    WHEN("It is passed -er, even rule argument") {
      // Create own argc and argv to parse.
      int argc = 3;
      char* argv[] = {strdup("./GameOfLife"), strdup("-er"), strdup("von_neumann")};

      // Run parser.
      ApplicationValues appValues = parser.runParser(argv, argc);

      THEN("Even generation should be updated and simulation should run.") {
        REQUIRE(appValues.evenRuleName == "von_neumann");
        REQUIRE(appValues.runSimulation == true);
      }
    }

    WHEN("It is passed -or, odd rule argument") {
      // Create own argc and argv to parse.
      int argc = 3;
      char* argv[] = {strdup("./GameOfLife"), strdup("-or"), strdup("von_neumann")};

      // Run parser.
      ApplicationValues appValues = parser.runParser(argv, argc);

      THEN("Odd generation should be updated and simulation should run.") {
        REQUIRE(appValues.oddRuleName == "von_neumann");
        REQUIRE(appValues.runSimulation == true);
      }
    }

    WHEN("It is passed -x, invalid argument") {
      // See what is printed with ostringstream and streambuf.
      std::ostringstream outStream;
      std::streambuf* outBuffer = std::cout.rdbuf();
      std::cout.rdbuf(outStream.rdbuf());
      
      // Create own argc and argv to parse.
      int argc = 2;
      char* argv[] = {strdup("./GameOfLife"), strdup("-x")};

      // Run parser.
      ApplicationValues appValues = parser.runParser(argv, argc);

      // Restore buffer.
      std::cout.rdbuf(outBuffer);

      THEN("Error message should be printed and simulation should not run"){
        REQUIRE(outStream.str().length() > 0);
        REQUIRE(appValues.runSimulation == false);
      }
    }

    WHEN("It is passed a valid argument type but no value for it") {
      // See what is printed with ostringstream and streambuf.
      std::ostringstream outStream;
      std::streambuf* outBuffer = std::cout.rdbuf();
      std::cout.rdbuf(outStream.rdbuf());
      
      // Create own argc and argv to parse.
      int argc = 2;
      char* argv[] = {strdup("./GameOfLife"), strdup("-f")};

      // Run parser.
      ApplicationValues appValues = parser.runParser(argv, argc);

      // Restore buffer.
      std::cout.rdbuf(outBuffer);

      THEN("Error message should be printed and simulation should not run"){
        REQUIRE(outStream.str().length() > 0);
        REQUIRE(appValues.runSimulation == false);
      }
    }
  }
}

