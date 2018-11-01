/**
 * @file MainArguments.h
 * @author Erik Ström
 * @brief Declaration of command-line argument handlers and ApplicationValues.
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
 * @addtogroup Structs Data structures
 * @brief structs used in the application to group data together.
 * @{
 */

/**
 * @brief Stores simulation settings.
 */
struct ApplicationValues {
    /**
     * @brief Decides if the simulation is to run. True equals simulation runs.
     */
    bool runSimulation = true;

    /**
     * @brief Name of rules to be carried out in even and odd generations.
     */
    string evenRuleName, oddRuleName;

    /**
     * @brief Number of generations to simulate before stop.
     */
    int maxGenerations = 100;
};
/** @} */

/**
 * @addtogroup Arguments Argument classes
 * @brief Classes that handles the command line arguments supplied by
 *  the user.
 * @{
 */

/**
 * @brief Virtual baseclass for arguments
 * @details Virtual baseclass for arguments, infromation that is passed from 
 *  the user to the program when it is run from the terminal. Sets the options
 *  for the simulation.
 */
class BaseArgument {
protected:
    /**
     * @brief Contains the value of the argument.
     */
    const string argValue;

    /**
     * @brief informs the user that no value was provided for the argument.
     */
    void printNoValue();

public:
    /**
     * @brief Construct a new BaseArgument object, argValue is assigned.
     * 
     * @param argValue std::string with argument value.
     */
    BaseArgument(string argValue) : argValue(argValue) {}

    /**
     * @brief Virtual destructor.
     */
    virtual ~BaseArgument() {}

    /**
     * @brief Makes changes ApplicationValues based on the arguments provided.
     * 
     * @param appValues Reference to an ApplicationValues struct.
     * @param value The value provided for the argument.
     */
    virtual void execute(ApplicationValues& appValues, char* value = nullptr) = 0;

    /**
     * @brief Returns the value of the argument 
     * 
     * @return const string& Reference to argValue.
     * 
     */
    const string& getValue() { return argValue; } 
};

/**
 * @brief Argument that tells the program to display the application help.
 */
class HelpArgument : public BaseArgument {
public:
    /**
     * @brief Constructor of HelpArgument.
     */
    HelpArgument() : BaseArgument("-h") {}
    /**
     * @brief Destructor of HelpArgument.
     */
    ~HelpArgument() {}

    /**
     * @brief Displays the user help and quits the application.
     * @details Runs printHelpScreen of ScreenPrinter and then returns,
     *  simulation is not run.
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param value Argument value (not used in this child class)
     * 
     * @test Test that it correctly runs printHelpScreen.
     */
    void execute(ApplicationValues& appValues, char* value);
};

/**
 * @brief Allows setting the amount of generations to run the simulation.
 */
class GenerationsArgument : public BaseArgument {
public:
    /**
     * @brief Constructor of GenerationsArgument.
     */
    GenerationsArgument() : BaseArgument("-g") {}
    /**
     * @brief Destructor of GenerationsArgument.
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
     * 
     * @test Test that it correctly changes the number of generations, by giving
     *  some different inputs.
     */
    void execute(ApplicationValues& appValues, char* generations);
};

/**
 * @brief Allows setting the world dimensions before the simulation starts
 */
class WorldsizeArgument : public BaseArgument {
public:
    /**
     * @brief Constructor of WorldsizeArgument.
     */
    WorldsizeArgument() : BaseArgument("-s") {}
    /**
     * @brief Destructor of WorldsizeArgument.
     */
    ~WorldsizeArgument() {}

    /**
     * @brief Changes the world size for the simulation.
     * @details Changes the WORLD_DIMENSIONS property of appValues. If no
     *  dimensions are provided printNoValue is run and the simulation does not
     *  start.
     * 
     * @param appValues Reference to an ApplicationValues struct.
     * @param dimensions Size of the simulation world in the format 
     *  width x height. Standard is (80x24).
     * 
     * @test Test that it correctly changes the dimensions by giving different
     *  dimensions.
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
     * @brief Constructor of FileArgument.
     */
    FileArgument() : BaseArgument("-f") {}
    /**
     * @brief Destructor of FileArgument.
     */
    ~FileArgument() {}

    /**
     * @brief Sets the filename to fileNameArg
     * @details Sets the global filename defined in Globals.h to fileNameArg.
     *  This will make the simulation use that file as input when starting the
     *  simulation.
     * 
     * @param appValues Reference to an ApplicationValues struct.
     * @param fileNameArg Population seed filename.
     * 
     * @test Test that it sets the filename correctly.
     */
    void execute(ApplicationValues& appValues, char* fileNameArg);
};

/**
 * @brief Allows setting a certain rule for even numbered generations.
 */
class EvenRuleArgument : public BaseArgument {
public:
    /**
     * @brief Constructor of EvenRuleArgument.
     */
    EvenRuleArgument() : BaseArgument("-er") {}
    /**
     * @brief Destructor  of EvenRuleArgument.
     */
    ~EvenRuleArgument() {}

    /**
     * @brief Sets a rule to be used for even generations only.
     * 
     * @param appValues Reference to an ApplicationValues struct.
     * @param evenRule Name of rule to be used.
     * 
     * @test Test that it sets even rule correctly.
     */
    void execute(ApplicationValues& appValues, char* evenRule);
};

/**
 * @brief Allows setting a certain rule for odd numbered generations.
 */
class OddRuleArgument : public BaseArgument {
public:
    /**
     * @brief Constructor of OddRuleArgument.
     */
    OddRuleArgument() : BaseArgument("-or") {}
    /**
     * @brief Destructor of OddRuleArgument.
     */
    ~OddRuleArgument() {}

    /**
     * @brief Sets a rule to be used for even generations only.
     * 
     * @param appValues Reference to an ApplicationValues struct
     * @param oddRule Name of rule to be used.
     * 
     * @test That it sets oddrule correctly.
     */
    void execute(ApplicationValues& appValues, char* oddRule);
};/** @} */

#endif //GAMEOFLIFE_MAINARGUMENTS_H
