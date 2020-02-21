//
//  Assignment 2 Task 2 template
//  Copyright © 2019 HKU ENGG1340. All rights reserved.
//


#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;


///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////

// IMPORTANT:  Do NOT change any of the function headers already provided to you
//             It means that you will need to use the function headers as is


// You may implement additional functions here
bool check4dir(int map[][MAX_SIZE],int y, int x, int index, int &flag)
{
    if(map[y+1][x]==0) //UP
    {
        map[y+1][x]=index;
        flag=1;
    }
    if(map[y-1][x]==0) //DOWN
    {
        map[y-1][x]=index;
        flag=1;
    }
    if(map[y][x-1]==0) //LEFT
    {
        map[y][x-1]=index;
        flag=1;
    }
    if(map[y][x+1]==0) //RIGHT
    {
        map[y][x+1]=index;
        flag=1;
    }
    if(map[y+1][x]==-2) //UP
    {
        return true;
    }
    if(map[y-1][x]==-2) //Down
    {
        return true;
    }
    if(map[y][x-1]==-2) //LEFT
    {
        return true;
    }
    if(map[y][x+1]==-2) //RIGHT
    {
        return true;
    }
    return false;

}


// Function: find the smallest number of steps to go from the starting point
//           to the destination in a given map.
//
// Input: int map[][]: 2D-array map
//        int map_h: the height of the map
//        int map_w: the width of the map
// Output: return true if a path is found, and store the smallest number of
//                      steps taken in &num_steps (pass-by-reference)
//         return false if there is no path
// ==============================================================
bool FindPath(int map[][MAX_SIZE], int map_h, int map_w, int &num_steps)
{
  // ==========================
  int one_y, one_x,cen_y,cen_x,flag;

  //looping around the number 1 break if around is -2 , return false if blocked 4 direction
    for (int k=1; k<MAX_SIZE;k++){
        flag=0;
        for (int i=0; i<map_h; i++)
        {
            for (int j=0; j<map_w; j++)
            {
                if (map[i][j]==k)
                {   // check four direction, if way found , flag ==1 , if -2 found, return true and update steps
                    if(check4dir(map, i, j ,k+1,flag))
                    {
                      num_steps=k;
                      return true;
                    }
                 }
            }
        }
        // if no way found , return false
        if(flag==0)
        {
            return false;
        }
    }
  return false;
}


///////// DO NOT MODIFY ANYTHING BELOW THIS LINE /////////

// Function: main function
// ==============================================================
int main()
{
  int map_h;
  int map_w;
  cin >> map_h >> map_w;

  int map[MAX_SIZE][MAX_SIZE];

  // initialize map
  for (int i=0; i<MAX_SIZE; i++)
    for (int j=0; j<MAX_SIZE; j++)
      map[i][j] = -1;

  // read map from standard input
  for (int i=0; i<map_h; i++)
    for (int j=0; j<map_w; j++)
      cin >> map[i][j];

  int steps;
  // print to screen number of steps if a path is found, otherwise print "No"
  if (FindPath(map, map_h, map_w, steps))
    cout << steps << endl;
  else
    cout << "No" << endl;

}
