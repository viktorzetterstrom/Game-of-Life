/**
 * @file MainArgumentsParser.h
 * @author Erik Ström
 * @brief Static functions that parses the starting arguments for the application.
 * @version 0.1
 * @date 2018-10-29
 */

#ifndef mainArgumentsParserH
#define mainArgumentsParserH

#include "MainArguments.h"
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


/**
 * @brief Class which parses the arguments passed by the user
 * @details The arguments are provided by the user before the launch of the 
 *  program. The -h argument will show the arguments
 *
 * @test Argument -h should be able  to parse all arguments by using 
 *  ScreenPrinter::printHelpScreen() 
 */
class MainArgumentsParser {
public:
    /**
     * @brief Parses the passed arguments by the user
     * @details When arguments are given by the command line, it goes through 
     *  those arguments and excecutes its function.
     *
     * @param argv[] the arguments provided by the user in Command-line
     * @param length Number of arguments
     *
     * @test Given valid arguments, after finding its value, it should return the
     *  reference to an ApplicationValues struct ccorresponding the right argument. If the argument is -h, it should excecute the app directly. 
     * @bug it does not return warning when passed argument is not found.
     */
    ApplicationValues& runParser(char* argv[], int length);

private:
    /**
     * @brief Application settings.
     */
    ApplicationValues appValues;

    /**
     * @brief Checks if provided argument exists
     * @details Looking for the option by searching through the passed 
     *  characters
     *
     * @param begin Start of characters.
     * @param end End of characters.
     * @param option The value of the option that should be searched for.
     *
     * @test Should return true if passed option is found, false if not.
     */
    bool optionExists(char** begin, char** end, const std::string& option);

    /**
     * @brief Gets the given option value
     * @details iterates through the options and returns the passed option if 
     *  found.
     *
     * @param begin Start of characters.
     * @param end End of characters.
     * @param option The value of the option that should be searched for.
     *
     * @test Should return a pointer to the value of the given option, if not it
     *  returns 0
     */
    char* getOption(char** begin, char** end, const std::string& option);
};

#endif
