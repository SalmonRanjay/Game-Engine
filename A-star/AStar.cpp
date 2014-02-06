//
//  AStar.cpp
//  Ateste
//
//  Created by Ranjay Salmon on 1/28/14.
//  Copyright (c) 2014 Ranjay Salmon. All rights reserved.
//
#include <iostream>
#include "AStar.h"
using namespace std;

AStar::AStar()
{
    
}

void AStar::printMap()
{
    for (int i=0; i<= ROW; i++)
    {
        for (int j=0; j<=COL; j++)
        {
            //cout<<mArray[i][j].mapValue;
            cout<<mArray[i][j].mpVal;
        }
        cout<<endl;
    }
            
}

void AStar::populateMap( )
{
    //int counter=1;
    for (int i=0; i<= ROW; i++)
    {
        for (int j=0; j<=COL; j++)
        {
            mArray[i][j].mpVal = '1';
            mArray[i][j].rowValue=i;
            mArray[i][j].Colvalue=j;
            
        }
    }
    
    
}

void AStar:: printStructMap ( )
{
    for (int i=0; i<= ROW; i++)
    {
        for (int j=0; j<=COL; j++)
        {
            cout<<mArray[i][j].mapValue;
        }
        cout<<endl;
    }
            
}

void AStar::addWalls( )
{
    mArray[0][10].mpVal= '0';
    mArray[1][10].mpVal= '0';
    mArray[2][10].mpVal= '0';
    mArray[3][10].mpVal= '0';
    mArray[4][2].mpVal= '0';
    mArray[5][5].mpVal= '0';
    mArray[6][5].mpVal= '0';
    mArray[7][5].mpVal= '0';
    mArray[8][8].mpVal= '0';
    mArray[9][8].mpVal= '0';
    
}

void AStar::addTarget()
{
    
    
    cout<<"Enter Row position"<<endl;
    cin>>targetrowPosition;
    cout<<"Enter Column Position"<<endl;
    cin>>targetcolPosition;
    
    mArray[targetrowPosition][targetcolPosition].mpVal='T';
    
}

void AStar::addStartPoint()
{
    cout<<"Enter the starting position"<<endl;
    int rowPosition,colPosition;
    
    cout<<"Enter Row position"<<endl;
    cin>>rowPosition;
    cout<<"Enter Column Position"<<endl;
    cin>>colPosition;
    
    mArray[rowPosition][colPosition].mpVal='S';

    
}
void AStar::calculateHeuristics()
{
    int heuristics,gvalue,fvalue;
    for (int i=0; i<= ROW; i++)
    {
        for (int j=0; j<=COL; j++)
        {
            heuristics=(targetrowPosition - mArray[i][j].rowValue) + (targetcolPosition - mArray[i][j].Colvalue);
            mArray[i][j].H_heuristics=abs(heuristics);
            //cout<<mArray[i][j].H_heuristics<<"next"<<endl;
           
        }
        cout<<endl;
    }

    
}

