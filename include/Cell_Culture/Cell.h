/**
 * @file Cell.h
 * @author Erik Ström
 * @brief Definition of Cell, class that represents a cell in the Game of Life.
 * @version 0.1
 * @date 2018-10-30
 */

#ifndef cellH
#define cellH

#include "../../terminal/terminal.h"

/**
 * @brief Data structure holding colors to visualize the state of cells.
 * @details The color enum is defined in the submodule terminal.
 */
struct StateColors {
    COLOR LIVING, // Representing living cell
            DEAD, // Representing dead cell
            OLD,  // Representing old cell
            ELDER;// Representing very old cell
}

/**
 * @brief Default color values.
 */
const STATE_COLORS = { COLOR::WHITE, COLOR::BLACK, COLOR::CYAN, COLOR::MAGENTA };

/**
 * @brief Enumeration of possible cell actions. Determined by rule.
 */
enum ACTION { KILL_CELL, IGNORE_CELL, GIVE_CELL_LIFE, DO_NOTHING };

/**
 * @brief Cells represents a certain combination of row and column of the 
 * simulated world.
 * 
 * @details Cells may be of two types; rim cells, those representing the outer 
 * limits of the world, or non-rim cells. The first cell type are immutable, 
 * exempt from the game's rules, and thus their values may not be changed. The 
 * latter type, however, may be changed and editedin ways specified by the 
 * rules.
 * 
 * @todo Make sure details of rim cells cannot be changed by the member functions
 *  and updateState(). As of now if action is GIVE_CELL_LIFE and rimCell is true
 *  the rimcell will have color LIVING. Value and color can also be changed
 *  of rim cells through the member functions.
 */
class Cell {
private:
    /**
     * @brief Struct that encapsulates the details about the Cell.
     */
    struct CellDetails {
        int age;
        COLOR color;
        bool rimCell;
        char value;
    } details;

    /**
     * @brief Struct that encapsulates the changes to be made next generation
     *  of the simulation.
     */
    struct NextUpdate {
        ACTION nextGenerationAction;
        COLOR nextColor;
        char nextValue;
        bool willBeAlive;	// some rules may need to know beforehand whether the cell will be alive
    } nextUpdate;

    /**
     * @brief Increments the age property in CellDetails by one.
     */
    void incrementAge() { details.age++; }

    /**
     * @brief Sets the age property in CellDetails to zero.
     */
    void killCell() { details.age = 0; }

    /**
     * @brief Sets the value property of CellDetails to value. Which will be 
     *  printed on the screen for that cell.
     * 
     * @param value Char which will be printed to screen.
     */
    void setCellValue(char value) { details.value = value; }

    /**
     * @brief Set the color property of CellDetails to color.
     * 
     * @param color Color to be used.
     * 
     * @todo remove this->, to use consequent syntax for all set-functions.
     */
    void setColor(COLOR color) { this->details.color = color; }

public:

    /**
     * @brief Construct a new Cell object.
     * @details Sets the starting values for the Cell. The default is a dead
     *  cell with age 0 and value '#', this will change if ACTION is supplied at
     *  construction.
     * 
     * @param isRimCell True if the cell is a rim cell, default is false.
     * @param action Specify an ACTION for the cell, default is DO_NOTHING.
     * 
     * @test Test that values are correctly assigned after construction. Both
     *  default values and when specified.
     */
    Cell(bool isRimCell = false, ACTION action = DO_NOTHING);

    /**
     * @brief Returns true if cell is alive.
     * @details Cell is said to be alive if it is not a rim cell and has an age
     *  that is larger than zero.
     * 
     * @return true If cell is not a rim cell and age is larger than zero.
     * @return false Otherwise.
     * 
     * @test Test that the function returns true when age is larger than zero.
     */
    bool isAlive();

    /**
     * @brief Set the NextGenerationAction in NextUpdate to action.
     * @details Does not work on rim cells.
     * 
     * @param action ACTION for next generation in the simulation.
     * 
     * @test Test that the function sets next ACTION correctly.
     */
    void setNextGenerationAction(ACTION action);

    /**
     * @brief Uses NextUpdate to update the cell state for the next generation.
     * @details If the action is KILL_CELL the cell is killed. If the next 
     *  action is IGNORE_CELL it is kept alive and age is incremented. If the
     *  action is GIVE_CELL_LIFE the age is incremented given it is not a rim
     *  cell.
     * 
     * @test Test that state is correctly updated based on NextUpdate.
     * @todo Enumerate DO_NOTHING in switch case to cover all cases.
     * @todo Make sure rim cell state is not updated. As of now value can be
     *  changed.
     */
    void updateState();

    /**
     * @brief Returns the age of the cell.
     * @details Age is stored in CellDetails.
     * 
     * @return int Current cell age.
     * 
     * @Test that it returns correct age.
     */
    int getAge() { return details.age; }

    /**
     * @brief Returns color of the cell.
     * @details Color is stored in CellDetails
     * 
     * @return COLOR Current cell color.
     * 
     * @test Test that it returns correct color.
     */
    COLOR getColor() { return details.color; }

    /**
     * @brief Returns true if the cell is a rim cell.
     * @details Determines whether the cell is a rim cell, and thus should be 
     *  immutable.
     * 
     * @return true If cell is a rim cell.
     * @return false Otherwise.
     * 
     * @test Test that it correctly returns whether cell is a rim cell.
     */
    bool isRimCell() { return details.rimCell; }

    /**
     * @brief Sets the color the cell will have after its next update.
     * 
     * @param nextColor Next color for cell.
     * 
     * @test Test that it correctly sets next color.
     * @todo Remove this->, to use consequent syntax for all set-functions.
     */
    void setNextColor(COLOR nextColor) { this->nextUpdate.nextColor = nextColor; }

    /**
     * @brief Returns the value of the cell.
     * 
     * @return char Current cell value.
     * 
     * @test Test that it returns correct value.
     */
    char getCellValue() { return details.value; }

    /**
     * @brief Sets the next character value of the cell, which will be printed 
     *  to screen.
     * 
     * @param value Next cell value.
     * 
     * @test Test that it correctly sets next value.
     */
    void setNextCellValue(char value) { nextUpdate.nextValue = value; }

    /**
     * @brief Sets whether the cell is alive/dead next generation.
     * 
     * @param isAliveNext true if alive, false if dead.
     * 
     * @test Test that it correctly sets if the cell will be alive next generation.
     */
    void setIsAliveNext(bool isAliveNext) { nextUpdate.willBeAlive = isAliveNext; }

    /**
     * @brief Returns true if the cell will be alive next generation.
     * 
     * @return true If willBeAlive in NextUpdate is true.
     * @return false Otherwise.
     * 
     * @test Test that it correctly returns whether cell will be alive next
     *  generation.
     */
    bool isAliveNext() { return nextUpdate.willBeAlive; }

    /**
     * @brief Returns the cells next action.
     * 
     * @return ACTION& Next cell action.
     * 
     * @test Test that it returns the next ACTION in the simulation correctly.
     */
    ACTION& getNextGenerationAction() { return nextUpdate.nextGenerationAction; }
};

#endif
