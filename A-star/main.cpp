//
//  main.cpp
//  Ateste
//
//  Created by Ranjay Salmon on 1/26/14.
//  Copyright (c) 2014 Ranjay Salmon. All rights reserved.
//

#include <iostream>
#include "AStar.h"
using namespace std;

int main(int argc, const char * argv[])
{
    AStar aStarObject;
    aStarObject.populateMap();
    //aStarObject.printMap();
    /*aStarObject.addWalls();
    
    aStarObject.addStartPoint();
    aStarObject.printMap();
     */
    aStarObject.addTarget();
    aStarObject.calculateHeuristics();
    return 0;
}

