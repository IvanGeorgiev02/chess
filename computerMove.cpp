/**
*
* Solution to course project # 12
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Ivan Georgiev
* @idnumber 6MI0600074
* @compiler VC
*
* <file for computer move>
*
*/

#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include "computerMove.h"
using namespace std;

bool checkForChess(int h, int w, vector < vector < char > > table, int r, int c)
{
    if (table[r][c] != '.') 
    {
        return true;
    }
    for (int r1 = max(0, r-1); r1 <= min(h-1, r+1); r1 ++) {
        for (int c1 = max(0, c-1); c1 <= min(w-1, c+1); c1 ++) {
            if (table[r1][c1] == 'K') 
            {
                return true;
            }
        }
    }
    for (int r1 = 0; r1 < h; r1 ++)
    {
        if (table[r1][c] == '1' || table[r1][c] == '2')
        {
            return true;
        }
    }
    
    for (int c1 = 0; c1 < w; c1 ++)
    {
        if (table[r][c1] == '1' || table[r][c1] == '2')
        {
            return true;
        }
    }
    return false;
}
int computerMove(int h, int w, vector < vector < char > > &table)
{
    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < h; j ++)
        {
            if (table[i][j] == 'P')
            {
                for (int i1 = max(0, i-1); i1 < min(h, i+2); i1 ++)
                {
                    for (int j1 = max(0, j-1); j1 < min(w, j+2); j1 ++)
                    {
                        if (i == i1 && j == j1)
                        {
                            continue;
                        }
                        if (checkForChess(h, w, table, i1, j1) == false)
                        {
                            swap(table[i][j], table[i1][j1]);
                            return 0;
                        }
                    }
                }
                if (checkForChess(h, w, table, i, j)) 
                {
                    return -1;
                }
                else
                {
                    return -2;
                }
            }
        }
    }
    return -1;
}