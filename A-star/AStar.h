//
//  AStar.h
//  Ateste
//
//  Created by Ranjay Salmon on 1/28/14.
//  Copyright (c) 2014 Ranjay Salmon. All rights reserved.
//

#ifndef __Ateste__AStar__
#define __Ateste__AStar__

#include <iostream>
using namespace std;
#define ROW 9
#define COL 16

class AStar
{
    public :
    // Search node
    struct myStruct
    {
        //int map[ROW][COL];
        int G_costToMove;
        int H_heuristics;
        int F_Total_cost;
        int mapValue;
        char mpVal;
        int rowValue,Colvalue;
        //myStruct *parent= NULL;
    };
    int targetrowPosition,targetcolPosition;
    
    myStruct mArray[ROW][COL];
    
    AStar();
    //~AStar();
    void printMap ();
    void populateMap( );
    void printStructMap ( );
    void addWalls( );
    void addTarget();
    void addStartPoint();
    void calculateHeuristics();

    
};

#endif /* defined(__Ateste__AStar__) */
