/**
 * @file ScreenPrinter.h
 * @author Erik Ström
 * @brief Declaration of ScreenPrinter, class that handles output to screen.
 * @ details: Uses submodule terminal to print simulation in the terminal.
 * @version 0.1
 * @date 2018-10-29
 */

#ifndef screenPrinterH
#define screenPrinterH


#include "../terminal/terminal.h"
#include "Cell_Culture/Population.h"

/**
 * @brief Responsible for visually representing the simulation world on screen.
 * @details Singleton class that uses a Terminal object from submodule Terminal 
 * to visually represent the simulation..
 */
class ScreenPrinter {

private:
    /**
     * @brief Terminal object handling screen output.
     */
    Terminal terminal;

    /**
     * @brief Empty private constructor.
     */
    ScreenPrinter() {}

public:
    /**
     * @brief Returns the ScreenPrinter singleton instance.
     * 
     * @return ScreenPrinter& Reference to ScreenPrinter instance.
     */
    static ScreenPrinter& getInstance() {
        static ScreenPrinter instance;
        return instance;
    }

    /**
     * @brief Prints Population to screen.
     * @todo Change type of WindowHeight and WindowWidth to Dimensions.
     * 
     * @param population Reference to Population object.
     */
    void printBoard(Population& population);

    /**
     * @brief Prints the help screen.
     */
    void printHelpScreen();

    /**
     * @brief Prints std::string supplied as input.
     * @param message String containting message.
     */
    void printMessage(string message);

    /**
     * @brief Clears the screen.
     */
    void clearScreen();
};

#endif
