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
* <file to generate table>
*
*/

#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <random>
#include <cassert>

#include "generateTable.h"
using namespace std;

void my_random_shuffle(vector < pair < int, int > > &v)
{
    for (int i = 0; i < v.size(); i ++)
    {
        int j = abs(rand() * rand() - rand()) % v.size();
        swap(v[i], v[j]);
    }
}
vector < vector < char > > generateTable(int h, int w)
{
    vector < vector < char > > table(h, vector<char>(w, 0));
    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < w; j ++)
        {
            table[i][j] = '.';
        }
    }
    vector < pair < int, int > > empty_cells;
    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < w; j ++)
        {
            empty_cells.push_back({i, j});
        }
    }
    my_random_shuffle(empty_cells);
    table[empty_cells[0].first][empty_cells[0].second] = 'K';
    table[empty_cells[1].first][empty_cells[1].second] = '1';
    table[empty_cells[2].first][empty_cells[2].second] = '2';
    // we will see which cells are not attacked by the player already so we can put the computer king there
    vector< vector<bool> >available_cells(h, vector<bool>(w, 1));
    int t1x = empty_cells[1].first, t1y = empty_cells[1].second;
    int t2x = empty_cells[2].first, t2y = empty_cells[2].second;
    int px = empty_cells[0].first, py = empty_cells[0].second;
    for (int i = 0; i < h; i ++)
    {
        available_cells[i][t1y]=0;
        available_cells[i][t2y]=0;
    }
    for (int i = 0; i < w; i ++)
    {
        available_cells[t1x][i]=0;
        available_cells[t2x][i]=0;
    }
    for (int i = max(0, px-1); i <= min(px+1, h-1); i ++)
    {
        for (int j = max(0, py-1); j <= min(py+1, w-1); j ++)
        {
            available_cells[i][j]=0;
        }
    }
    empty_cells.clear();
    
    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < h; j ++)
        {
            if (available_cells[i][j] == 1)
            {
                empty_cells.push_back({i, j});
            }
        }
    }
    my_random_shuffle(empty_cells);
    table[empty_cells[0].first][empty_cells[0].second] = 'P';
    return table;
}