#include <iostream>
#include <sstream>
#include <cmath>
#include <tclap/CmdLine.h>
#include "board.h"
#include "randgen.h"


const double DEFAULT_MAX_WEIGHT = 9.99;
const double DEFAULT_MIN_WEIGHT = 0.10;
const unsigned DEFAULT_GRID_WIDTH = 6;
const unsigned DEFAULT_GRID_HEIGHT = 9;
const unsigned MAX_GRID_DIMENSION = 9;
const unsigned MIN_GRID_DIMENSION = 2;
const double DEFAULT_EQUAL_WEIGHT = 1.0;
const double MAX_EQUAL_WEIGHT = 7.0;
const double MIN_EQUAL_WEIGHT = 0.0;


int main(int argc, char* argv[])
{
	double high = DEFAULT_MAX_WEIGHT;
	double low = DEFAULT_MIN_WEIGHT;
	unsigned width = DEFAULT_GRID_WIDTH;
	unsigned height = DEFAULT_GRID_HEIGHT;
	double equalWeight = MIN_EQUAL_WEIGHT;

    try
    {
        TCLAP::CmdLine cmd("command line for dijkstra demo", ' ' , "0.1");
        TCLAP::ValueArg<unsigned> seedArg("s", "seed", "Initial seed value for the Random Number Generator", 
                                          false, 0, "unsigned integer");
        TCLAP::ValueArg<double> lowArg("l", "low", "Low value for path weights", 
                                          false, DEFAULT_MIN_WEIGHT, "double 0, less than or equal to high");
        TCLAP::ValueArg<double> highArg("i", "high", "High value for path weights", 
                                          false, DEFAULT_MAX_WEIGHT, "double 0, greater than or equal low");
        TCLAP::ValueArg<unsigned> widthArg("w", "width", "Width of the grid in cells", 
                                          false, DEFAULT_GRID_WIDTH, "unsigned, between 2 and 9");
        TCLAP::ValueArg<unsigned> heightArg("e", "height", "Height of the grid in cells", 
                                          false, DEFAULT_GRID_HEIGHT, "unsigned, between 2 and 9");
        TCLAP::ValueArg<double> equidistantArg("q", "equal", "Vertical and Horizontal weights are equal. Diagonal weights are 1.414 times Vertical weights", 
			                              false, MIN_EQUAL_WEIGHT, "double, between 0 and 7");
        cmd.add(seedArg); 
        cmd.add(lowArg); 
        cmd.add(highArg); 
        cmd.add(widthArg); 
        cmd.add(heightArg); 
        cmd.add(equidistantArg); 

        cmd.parse(argc, argv);
        RandGen::setSeed(seedArg.getValue());
        
		low = lowArg.getValue();
		low = low < 0 ? 0 : low;

		high = highArg.getValue();
		high = high < low ? low : high;

		width = widthArg.getValue();
		width = width > MAX_GRID_DIMENSION ? MAX_GRID_DIMENSION : width;
		width = width < MIN_GRID_DIMENSION ? MIN_GRID_DIMENSION : width;

		height = heightArg.getValue();
		height = height > MAX_GRID_DIMENSION ? MAX_GRID_DIMENSION : height;
		height = height < MIN_GRID_DIMENSION ? MIN_GRID_DIMENSION : height;

		equalWeight = equidistantArg.getValue();
		equalWeight = equalWeight > MAX_EQUAL_WEIGHT ? MAX_EQUAL_WEIGHT : equalWeight;
		equalWeight = equalWeight < MIN_EQUAL_WEIGHT ? MIN_EQUAL_WEIGHT : equalWeight;


    }
    catch(TCLAP::ArgException& e) 
    {
        std::cerr << "error: " << e.error() << " for argument "  << e.argId() << std::endl;
		return 1;
    }

    Board board(width, height, low, high, equalWeight);
    do
    {
        board.show(std::cout);
        std::cout << "Press <enter> to continue.....";
        std::cin.get();    
            
    }while(board.next(std::cout) == false);   
    std::cin.get();
    return 0;
}
