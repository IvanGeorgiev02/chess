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
* <file to  print table>
*
*/

#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include "printTable.h"
using namespace std;

void printTable(int h, int w, vector < vector < char > > table)
{
    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < w; j ++)
        {
            cout << table[i][j];
        }
        cout << endl;
    }
}