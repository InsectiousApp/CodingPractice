#include <iostream>
using namespace std;

#define N 4

bool isSafe(int arr[N][N], int x, int y);
bool RatInAMaze(int arr[N][N], int x, int y, int sol[N][N]);
void printMaze(int sol[N][N]);

int main()
{
    int arr[N][N]  =  { {1, 1, 1, 0},
        {0, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 0, 1}
    };

     int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    if(RatInAMaze(arr, 0, 0, sol)==true)
    {
        //means it returned true, so solution exists, hence print the solution matrix
        printMaze(sol);
    }
    else{
        cout<<"No solution exist for the given matrix";
    }


    return 0;
}

void printMaze(int sol[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isSafe(int arr[N][N], int x, int y)
{
    if(x>=0&&x<N&&y>=0&&y<N&&arr[x][y]==1)
        return true;

    return false;
}

bool RatInAMaze(int arr[N][N], int x, int y, int sol[N][N])
{

    if(x==N-1&&y==N-1)
    {
        sol[x][y]=1;
        return true;
    }

    if(isSafe(arr, x, y)==true)
    {
        sol[x][y]=1;

        if(RatInAMaze(arr, x+1, y, sol)==true)
            return true;
        if(RatInAMaze(arr, x, y+1, sol)==true)
            return true;

        //it means that we are not able to rache further , so will backtrack
        sol[x][y]=0;
        return false;
    }
    else{
        return false;
    }

}
