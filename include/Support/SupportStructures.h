/**
 * @file SupportStructures.h
 * @author Erik Ström
 * @brief Various supportive structures to be used throughout the application
 * @version 0.1
 * @date 2018-10-29
 */

#ifndef GAMEOFLIFE_SUPPORTSTRUCTURES_H
#define GAMEOFLIFE_SUPPORTSTRUCTURES_H

/**
 * @brief Constitues a single Point in the simulated world.
 * @details The Point structure handles x and y (column/row) coordinates in the world of Game of life, and is used to map Cell objects to their positions.
 */
struct Point {
    /**
     * @brief x-coordinate stored as integer
     */
    int x;

    /**
     * @brief y-coordinate stored as integer
     */
    int y;

    /**
     * @brief Overloading of operator <
     * @details Returns true if x is smaller than the x of the comparing Point.
     *  If they x-coordinates are equal then the y-coordinates are compared, and
     *  true is returned if y is smaller than the y of comparing point.
     * 
     * @param other Reference to other Point
     * @return true if x is smaller than other x. If x equals other x it returns true if y is smaller than the other x.
     * @return false otherwise
     */
    bool operator < (const Point& other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }

};

/**
 * @brief Data structure storing dimensions as width and height.
 */
struct Dimensions {
    /**
     * @brief Width stored as integer.
     */
    int WIDTH;

    /**
     * @brief Height stored as integer.
     */
    int HEIGHT;
};


#endif //GAMEOFLIFE_SUPPORTSTRUCTURES_H
