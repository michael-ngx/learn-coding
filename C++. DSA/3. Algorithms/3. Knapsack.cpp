#include <cmath>
#include <iostream>

int main()
{
    int num = 9;
    int w = 30; // max wt
    int val[] = {25, 45, 15, 35, 50, 30, 20, 10, 40};
    int wt[] = {5, 9, 3, 7, 10, 6, 4, 2, 8};

    // Tabular method - Dynamic programming
    // Rows: 0 -> num: Row i represents the set of all the items from first rows up to i
    // Cols: 0 -> w  : Current weight capacity of knapsack, increasing up to w
    // --> Entry in row i, col j represents **maximum value** that can be obtained with limit **j** and items **1, 2, ..., i**
    int mat[num + 1][w + 1];
    
    for (int item = 0; item <= num; item++)
    {
        for (int cap = 0; cap <= w; cap++)
        {
            // We can easily fill first row as 0 (no items can be included) and first column as 0 (knapsack max weight = 0)
            if (item == 0 || cap == 0)
            {
                mat[item][cap] = 0;
            }
            // As we move downwards (next row --> meets the new item), we have the choice to either include it or not
            // Obviously if j < wt[item], we cannot add item, so mat[i][j] = mat[i - 1][j]
            else if (cap < wt[item - 1])
            {
                mat[item][cap] = mat[item - 1][cap];
            }
            // Else, mat[i][j] = max(value "with" new item, value "without" new item)
            //      "without" = mat[i - 1][j]
            //      "with" = val[item] + max val of (j - wt[item]) 
            //             = val[item] + mat[i - 1][j - wt[item]]
            else
            {
                int item_wt = wt[item - 1];
                int item_val = val[item - 1];

                int val_without = mat[item - 1][cap];
                int val_with = item_val + mat[item - 1][cap - item_wt];
                mat[item][cap] = std::max(val_with, val_without);
            }
            std::cout << mat[item][cap] << " ";
        }
        std::cout << std::endl;
    }

    // Restructure the array indicating include (1) or not include (0) each object
    // Based on the increase in value of this row compared to previous row (traverse backwards)
    int check_value = mat[num][w];
    int check_cap = w;
    for (int item = num; item > 0; item--)
    {
        if (mat[item][check_cap] > mat[item - 1][check_cap])
        {
            std::cout << item << std::endl;
            check_value -= val[item - 1];
            check_cap -= wt[item - 1];
        }
    }

    std::cout << "//************************************************************ Space optimized ************************************************************//" << std::endl;
    // We can observe that we only need to compare current row (item) with previous one
    // and the value in previous row, if nothing, is kept. So we can just use 1D array!
    int mat_optimized[w + 1];
    int item = 0;
    
    for (int item = 0; item <= num; item++)
    {
        for (int cap = 0; cap <= w; cap++)
        {
            if (item == 0)
            {
                mat_optimized[cap] = 0;
            }
            else if (wt[item - 1] <= cap)
            {
                int item_wt = wt[item - 1];
                int item_val = val[item - 1];

                int val_with = item_val + mat_optimized[cap - item_wt];
                mat_optimized[cap] = std::max(val_with, mat_optimized[cap]);
            }
            std::cout << mat_optimized[cap] << " ";
        }
        std::cout << std::endl;
    }

    // Restructure is done similarly, just on the same array ??????? TODO: CHECK
    
}