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
* <file to validate move>
*
*/

#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include "validateMove.h"
using namespace std;

bool validateMove(int h, int w, vector < vector < char > >table, tuple< char, int, int> move)
{
    char fig = get<0>(move);
    if (fig != '1' && fig != '2' && fig != 'K')
    {
        cout << "Invalid figure\n";
        return false;
    }
    int r1, c1;
    r1 = get<1>(move);
    c1 = get<2>(move);
    if(r1 >= h || r1 < 0 || c1 >= w || c1 < 0)
    {
        cout << "Move going out of table\n";
        return false;
    }
    vector < vector <bool> >valid(h, vector<bool> (w, 0) );
    for (int i = 0 ; i < h; i ++)
    {
        for (int j = 0; j < w; j ++)
        {
            if (table[i][j] == fig)
            {
                if (fig == '1' || fig == '2')
                {
                    for(int i1 = i+1; i1 < h; i1 ++)
                    {
                        if(table[i1][j] != '.')break;
                        valid[i1][j]=1;
                    }
                    for(int i1 = i-1; i1 >= 0; i1 --)
                    {
                        if(table[i1][j] != '.')break;
                        valid[i1][j]=1;
                    }
                    for(int j1 = j+1; j1 < w; j1 ++)
                    {
                        if(table[i][j1] != '.')break;
                        valid[i][j1]=1;
                    }
                    for(int j1 = j-1; j1 >= 0; j1 --)
                    {
                        if(table[i][j1] != '.')break;
                        valid[i][j1]=1;
                    }
                    return valid[r1][c1];
                }
                else
                {
                    if (abs(r1 - i) <= 1 && abs(c1 - j) <= 1 && table[r1][c1] == '.')
                    {
                        return true;
                    }
                    else
                    {}
                }
            }
        }
    }
    return false;

}