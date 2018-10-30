/**
 * @file Population.h
 * @author Erik Ström
 * @brief Definition of Population.
 * @version 0.1
 * @date 2018-10-30
 */

#ifndef POPULATION_H
#define POPULATION_H

#include<map>
#include<string>
#include "Cell.h"
#include "Support/Globals.h"
#include "GoL_Rules/RuleOfExistence.h"
#include "GoL_Rules/RuleFactory.h"

using namespace std;

/**
 * @brief Representation of the complete society of cell existance and interactions.
 * 
 * @details The Population constitutes of all current, previous and future 
 *  generations of cells, both living and dead as well as those not yet born. By 
 *  mapping all cells to their respective positions in the simulation world, 
 *  Population has the complete knowledge of each cell's whereabouts. 
 *  Furthermore, the class is responsible for determining which rules should be 
 *  required from the RuleFactory, and store the pointer to these as members. 
 *  Population's main responsibility during execution is determining which rule 
 *  to apply for each new generation and updating the cells to their new states.
 */
class Population
{
private:
    /**
     * @brief Current generation.
     */
    int generation; 

    /**
     * @brief std::map that maps each Cell to a Point.
     */
    map<Point, Cell> cells;

    /**
     * @brief RuleOfExistence for even generations.
     */
    RuleOfExistence* evenRuleOfExistence;

    /**
     * @brief RuleOfExistence for odd generations.
     */
    RuleOfExistence* oddRuleOfExistence;

    /**
     * @brief Randomizes the state of each cell in cells.
     * @details Does not randomize the rim cells. The size of the simulation is
     *  determined by the global WORLD_DIMENSIONS.
     */
    void randomizeCellCulture();

    /**
     * @brief Populates the map cells with predefined cells from file.
     * @details Uses FileLoader::LoadPopulationFromFile() to load the map with
     *  data from the filename supplied when the application was run.
     */
    void buildCellCultureFromFile();

public:
    /**
     * @brief Constructor
     * @details Sets generation to zero and sets even- and odd rule of existence
     *  to nullptr.
     */
    Population() : generation(0), evenRuleOfExistence(nullptr), oddRuleOfExistence(nullptr) {}
    
    /**
     * @brief Destructor
     */
    ~Population();

    /**
     * @brief Initiates cell population before simulation starts.
     * @details First runs randomizeCellCulture or buildCellCultureFromFile
     *  depending on if a filename was provided. Then proceeds to set the 
     *  populations rules of existence. If no oddRuleName is provided odd
     *  generations have the same rule as even generations.
     * 
     * @param evenRuleName Rule for even generations.
     * @param oddRuleName Rule for odd generations (default is empty)
     */
    void initiatePopulation(string evenRuleName, string oddRuleName = "");

    /**
     * @brief Updates the cell population and determines the next generation
     *  based on the rules of existence.
     * 
     * @return int Increments the generation counter.
     */
    int calculateNewGeneration();

    /**
     * @brief Returns a reference to the cell at the position of the provided 
     *  Point.
     * 
     * @param position Cell position.
     * @return Cell& Reference to cell at position.
     */
    Cell& getCellAtPosition(Point position) { return cells.at(position); }

    /**
     * @brief Returns the total amount of cells in the population.
     * 
     * @return int Amount of cells in population.
     */
    int getTotalCellPopulation() { return cells.size(); }

};

#endif