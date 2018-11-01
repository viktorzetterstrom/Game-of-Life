/**
 * @file FileLoader.h
 * @author Erik Ström
 * @brief Declaration of FileLoader, class for loading cell population from file.
 * @version 0.1
 * @date 2018-10-29
 */

#ifndef FileLoaderH
#define FileLoaderH

#include <map>
#include "Cell_Culture/Cell.h"
#include "Globals.h"

using namespace std;

/**
 * @brief Determines starting values for simulation, based on contents of 
 * specified file.
 * @details Reads startup values from specified file, containing values for 
 * WORLD_DIMENSIONS and cell Population. Will create the corresponding cells.
 */
class FileLoader {

public:
    /**
     * @brief Empty constructor of FileLoader.
     */
    FileLoader() {}

    /**
     * @brief Loads a population seed from a file.
     * @details Stores the population seed in a referenced std::map with mapping
     *  Point -> Cell
     * 
     * @param cells Reference to a std::map with cells mapped to points.
     * 
     * @todo Add more robust checks for files with bad input. As of now it can
     *  not handle bad files.
     */
    void loadPopulationFromFile(map<Point, Cell>& cells);
};

#endif
