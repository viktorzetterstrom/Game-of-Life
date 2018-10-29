/**
 * @file MainArguments.h
 * @author Erik Ström
 * @brief 
 * @version 0.1
 * @date 2018-10-29
 */

#ifndef GAMEOFLIFE_MAINARGUMENTS_H
#define GAMEOFLIFE_MAINARGUMENTS_H

#include "Globals.h"
#include "ScreenPrinter.h"
#include <sstream>
#include <string>

using namespace std;

/**
 * @brief Stores simulation settings.
 */
struct ApplicationValues {
    bool runSimulation = true;
    string evenRuleName, oddRuleName;
    int maxGenerations = 100;
};

/**
 * @brief Virtual baseclass for arguments
 * @details Virtual baseclass for arguments, infromation that is passed from 
 *  the user to the program when it is run from the terminal. Sets the options
 *  for the simulation.
 */
class BaseArgument {
protected:
    /**
     * @brief Contains the value of the argument
     */
    const string argValue;

    /**
     * @brief informs the user that no value was provided for the argument
     */
    void printNoValue();

public:
    /**
     * @brief Construct a new BaseArgument object, argValue is assigned.
     * 
     * @param argValue std::string with argument value
     */
    BaseArgument(string argValue) : argValue(argValue) {}

    /**
     * @brief Virtual destructor
     */
    virtual ~BaseArgument() {}

    /**
     * @brief Makes changes ApplicationValues based on the arguments provided
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param value The value provided for the argument.
     */
    virtual void execute(ApplicationValues& appValues, char* value = nullptr) = 0;

    /**
     * @brief Returns the value of the argument 
     * 
     * @return const string& Reference to argValue
     */
    const string& getValue() { return argValue; } 
};

/**
 * @brief Argument that tells the program to display the application help.
 */
class HelpArgument : public BaseArgument {
public:
    /**
     * @brief Constructor
     */
    HelpArgument() : BaseArgument("-h") {}
    /**
     * @brief Destructor
     */
    ~HelpArgument() {}

    /**
     * @brief Displays the user help and quits the application.
     * @details Runs printHelpScreen of ScreenPrinter and then returns, 
     *  simulation is not run.
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param value Argument value (not used in this child class)
     */
    void execute(ApplicationValues& appValues, char* value);
};

/**
 * @brief Allows setting the amount of generations to run the simulation.
 */
class GenerationsArgument : public BaseArgument {
public:
    /**
     * @brief Constructor
     */
    GenerationsArgument() : BaseArgument("-g") {}
    /**
     * @brief Destructor
     */
    ~GenerationsArgument() {}

    /**
     * @brief Changes the number of generations to simulate.
     * @details Changes the number of maxGeneration in appValues to generations.
     *  If no value is provided printNoValue is run and simulation does not
     *  start.
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param generations Number of generations to simulate. Standard is 100.
     */
    void execute(ApplicationValues& appValues, char* generations);
};

/**
 * @brief Allows setting the world dimensions before the simulation starts
 */
class WorldsizeArgument : public BaseArgument {
public:
    /**
     * @brief Constructor
     */
    WorldsizeArgument() : BaseArgument("-s") {}
    /**
     * @brief Destructor
     */
    ~WorldsizeArgument() {}

    /**
     * @brief Changes the world size for the simulation.
     * @details Changes the WORLD_DIMENSIONS property of appValues. If no
     *  dimensions are provided printNoValue is run and the simulation does not
     *  start.
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param dimensions Size of the simulation world in the format 
     *  width x height. Standard is (80x24).
     */
    void execute(ApplicationValues& appValues, char* dimensions);
};

/**
 * @brief Changes the starting seed of the simulation via external file.
 * @details Allows changing the starting condition as well as the size of the 
 *  simulation by using an external file. Overwrites WorldSizeArgument. If this
 *  argument is not used, starting condition of the cells are randomized.
 */
class FileArgument : public BaseArgument {
public:
    /**
     * @brief Constructor
     */
    FileArgument() : BaseArgument("-f") {}
    /**
     * @brief Destructor
     */
    ~FileArgument() {}

    /**
     * @brief Sets the filename to fileNameArg
     * @details Sets the global filename defined in Globals.h to fileNameArg.
     *  This will make the simulation use that file as input when starting the
     *  simulation.
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param fileNameArg Population seed filename
     */
    void execute(ApplicationValues& appValues, char* fileNameArg);
};

/**
 * @brief Allows setting a certain rule for even numbered generations.
 */
class EvenRuleArgument : public BaseArgument {
public:
    /**
     * @brief Constructor
     */
    EvenRuleArgument() : BaseArgument("-er") {}
    /**
     * @brief Destructor
     */
    ~EvenRuleArgument() {}

    /**
     * @brief Sets a rule to be used for even generations only.
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param evenRule Name of rule to be used.
     */
    void execute(ApplicationValues& appValues, char* evenRule);
};

/**
 * @brief Allows setting a certain rule for odd numbered generations.
 */
class OddRuleArgument : public BaseArgument {
public:
    /**
     * @brief Constructor
     */
    OddRuleArgument() : BaseArgument("-or") {}
    /**
     * @brief Destructor
     */
    ~OddRuleArgument() {}

    /**
     * @brief Sets a rule to be used for even generations only.
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param oddRule Name of rule to be used.
     */
    void execute(ApplicationValues& appValues, char* oddRule);
};

#endif //GAMEOFLIFE_MAINARGUMENTS_H
