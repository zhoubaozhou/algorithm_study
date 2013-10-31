// 
// My Submissions
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
// 
// Note: You can only move either down or right at any point in time.
// 
class Solution {
    vector<vector<int> > cost_;
    
    int minPathSum(vector<vector<int> > &grid, int x, int y) {
        if (x >= grid.size() || y >= grid[0].size()) return INT_MAX;
        if ((x == grid.size() - 1 ) && (y == grid[0].size() - 1)) {
            cost_[x][y] = grid[x][y];
            return cost_[x][y];
        }
        if (cost_[x][y] != 0) return cost_[x][y];
        cost_[x][y] = grid[x][y] + min(minPathSum(grid, x, y+1), minPathSum(grid, x+1, y));
        return cost_[x][y];
    }
    
public:
    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        cost_ = vector<vector<int> >(grid.size(), vector<int>(grid[0].size(), 0));
        return minPathSum(grid, 0, 0);
    }
};
