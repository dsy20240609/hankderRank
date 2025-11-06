// not exactly n*n, since the grid length and width could be different

void place(vector<vector<int>>& grid, int index, int n, bool& res);
bool canPlaceSecurityCameras(int N, vector<vector<int>> grid) {

    vector<vector<int> gridToPlace = grid;
    bool foundPlace=false;
    int level=0;
    int remain=N;
    place(gridToPlace,level,remain,foundPlace);
    return foundPlace;
}
bool allZero(vector<int> vec) {
    bool isAllZero = true;
    for(size_t i = 0; i < vec.size();++i) {
        if(vec[i] == 1) {
            isAllZero = false;
            return;
        }
    }
    return isAllZero;
}
void place(vector<vector<int>>& grid, int index, int n, bool& res) {
    if(n ==0) {
        res= true;
        return;
    }
    if( index == grid.size()) {
        return;
    }

    size_t column = grid[n].size();
    if(allZero(grid[n]) {
        for(size_t i=0; i < column;++i) {
                grid[n][i] =1;
            for(int c=0; c< column; ++c) {
                grid[i][c]=1;
            } // mark all row to 1
            for(int r =0; r< grid.size();++r) {
                grid[r][i]=1;
            } // mark all column to 1
            for(int r=0; r< grid.size(); ++r) {
                int c= index -i +r;
                if(c>=0 && c< column) {
                    grid[r][c]=1
                }
            } // mark diagonal from upper left to lower right
            for(int r =0; r < grid.size();++r) {
                int c= i+index-r;
                if(c >= 0 && c< cols) {
                    grid[r][c]=1;
                }
            } // mark diagonal from upper right to lower left


            place(grid,index+1,n-1,res);

                grid[n][i] =0;
            
            for(int c=0; c< column; ++c) {
                grid[i][c]=0;
            } // mark all row to 0
            for(int r =0; r< grid.size();++r) {
                grid[r][i]=0;
            } // mark all column to 0
            for(int r=0; r< grid.size(); ++r) {
                int c= index -i +r;
                if(c>=0 && c< column) {
                    grid[r][c]=0;
                }
            } // mark diagonal from upper left to lower right
            for(int r =0; r < grid.size();++r) {
                int c= i+index-r;
                if(c >= 0 && c< cols) {
                    grid[r][c]=0;
                }
            } // mark diagonal from upper right to lower left
        }
    } else {
        place(grid,index+1,n,res);
    }
}

/* what is the termination condition */