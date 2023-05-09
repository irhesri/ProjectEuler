#include <vector>
#include <iostream>

using namespace std;

int max_(int a, int b)
{
    return (a * (a > b) + b * (a <= b));
}

void    getLargestProduct(vector<vector<int>> grid)
{
    int   max = 0;
    int   tmp;
    
    
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            tmp = max_(grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3], 
                        grid[j][i] * grid[j + 1][i] * grid[j + 2][i] * grid[j + 3][i]);
            if (i < 17)
                tmp = max_(tmp, 
                        grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]); 
            if (i > 2)
                tmp = max_(tmp, 
                        grid[j][i] * grid[j + 1][i - 1] * grid[j + 2][i - 2] * grid[j + 3][i - 3]);  
            if (tmp > max)
                max = tmp;
        }
    }
    std::cout << max;
}

int main(){
    vector< vector<int> > grid(20,vector<int>(20));
    for(int grid_i = 0;grid_i < 20;grid_i++){
    	for(int grid_j = 0;grid_j < 20;grid_j++){
    		cin >> grid[grid_i][grid_j];
    	}
    }
    getLargestProduct(grid);
    return 0;
}