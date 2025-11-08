// not exactly n*n, since the grid length and width could be different

void place(vector<vector<int>>& grid, int level, int n, bool& res);
bool canPlace(vector<vector<int>> &grid, int x,int y) {
    bool isReadyToPlace = true;
    for(size_t i = 0; i<= grid[0].size()-1;++i) {
        if(grid[x][i]==2) {
            isReadyToPlace=false;
            return isReadyToPlace;
        }
    }
    for(size_t i = 0 ; i<=grid.size()-1;++i) {
        if(grid[i][y]==2) {
            isReadyToPlace=false;
            return isReadyToPlace;
        }
    }
    for(size_t i =0;i<= grid.size()-1;++i) {
        int j=y+(i-x);
        if(j>=0 && j<grid[0].size()-1) {
            if(grid[i][j] == 2) {
                isReadyToPlace=false;
                return isReadyToPlace;
            }
        }
    }
    for(size_t i =0; i<= grid[0].size()-1;++i) {
        int j = y -(i-x);
        if(j >=0 && j<grid[0].size()-1) {
            if(grid[i][j] ==2) {
                isReadyToPlace=false;
                return isReadyToPlace;
            }
        }
    }
    return isReadyToPlace;
}
bool canPlaceSecurityCameras(int N, vector<vector<int>> grid) {

    vector<vector<int> gridToPlace = grid;
    bool foundPlace=false;
    int level=0;
    int remain=N;
    place(gridToPlace,level,remain,foundPlace);
    return foundPlace;
}

void place(vector<vector<int>>& grid, int level, int n, bool& res) {
    if(n ==0) {
        res= true;
        return;
    }
    if( level == grid.size()) {
        return;
    }
    size_t row = grid.size()-1;
    size_t column = grid[level].size()-1;
        for(size_t i=0; i <= column;++i) {
                if(grid[level][i] == 1 || !canPlace(grid,level,i)) { // block or can not place, means if placed there is conflict
                    continue;
                } else if (grid[level][i] == 2) {
                   place(grid,level+1,n,res);
                } else if (grid[level][i] == 0 && canPlace(grid,level,i)) {
                    grid[level][i]=2;  // place a camera at level,i
                    // mark the same level all to 2
                    for(size_t k=0;k<=column;++k) {
                        if(grid[level][k] == 1) { // block not change
                            continue;
                        } else {
                            grid[level][k]=2;
                        }
                    // mark the same column all to 2;
                    for(size_t k=0; k<= row;++k) {
                        if(grid[k][i] == 1) {
                            continue;
                        } else {
                            grid[k][i]=2;
                        }
                    }
                    // mark all diagonal from upper left to lower right
                    for(size_t k=0;k <=row;++k) {
                        int j =i+(k-level);
                        if( j>=0 && j <= column) {
                            if(grid[k][j] == 1) {
                                continue;
                            } else{
                                grid[k][j]=2;
                            }
                        }
                    }
                    // mark all diagonal from upper right to lower left
                    for(size_t k=0; k<=row;++k) {
                        int j = i-(k-level);
                        if( j>=0 && j <=column) {
                            if(grid[k][j] == 1) {
                                continue;
                            } else {
                                grid[k][j]=2;
                            }
                        }
                    }
                    place(grid,level+1,n-1,res); // recursion
                    // trace back
                    // mark the same level all to 0
                    for(size_t k=0;k<=column;++k) {
                        if(grid[level][k] == 1) { // block not change
                            continue;
                        } else {
                            grid[level][k]=0;
                        }
                    // mark the same column all to 0;
                    for(size_t k=0; k<= row;++k) {
                        if(grid[k][i] == 1) {
                            continue;
                        } else {
                            grid[k][i]=0;
                        }
                    }
                    // mark all diagonal from upper left to lower right
                    for(size_t k=0;k <=row;++k) {
                        int j =i+(k-level);
                        if( j>=0 && j <= column) {
                            if(grid[k][j] == 1) {
                                continue;
                            } else{
                                grid[k][j]=0;
                            }
                        }
                    }
                    // mark all diagonal from upper right to lower left
                    for(size_t k=0; k<=row;++k) {
                        int j = i-(k-level);
                        if( j>=0 && j <=column) {
                            if(grid[k][j] == 1) {
                                continue;
                            } else {
                                grid[k][j]=0;
                            }
                        }
                    }      
        }
}

/* what is the termination condition */


//
             // mark the same level all to 2
                    for(size_t k=0;k<=column;++k) {
                        if(grid[level][k] == 1) { // block not change
                            continue;
                        } else {
                            grid[level][k]=2;
                        }
                    }
                    // mark the same column all to 2;
                    for(size_t k=0; k<= row;++k) {
                        if(grid[k][i] == 1) {
                            continue;
                        } else {
                            grid[k][i]=2;
                        }
                    }
                    // mark all diagonal from upper left to lower right
                    for(size_t k=0;k <=row;++k) {
                        int j =i+(k-level);
                        if( j>=0 && j <= column) {
                            if(grid[k][j] == 1) {
                                continue;
                            } else{
                                grid[k][j]=2;
                            }
                        }
                    }
                    // mark all diagonal from upper right to lower left
                    for(size_t k=0; k<=row;++k) {
                        int j = i-(k-level);
                        if( j>=0 && j <=column) {
                            if(grid[k][j] == 1) {
                                continue;
                            } else {
                                grid[k][j]=2;
                            }
                        }
                    }

                for(size_t k=0;k<=column;++k) {
                        if(grid[level][k] == 1) { // block not change
                            continue;
                        } else {
                            grid[level][k]=0;
                        }
                    }
                    // mark the same column all to 0;
                    for(size_t k=0; k<= row;++k) {
                        if(grid[k][i] == 1) {
                            continue;
                        } else {
                            grid[k][i]=0;
                        }
                    }
                    // mark all diagonal from upper left to lower right
                    for(size_t k=0;k <=row;++k) {
                        int j =i+(k-level);
                        if( j>=0 && j <= column) {
                            if(grid[k][j] == 1) {
                                continue;
                            } else{
                                grid[k][j]=0;
                            }
                        }
                    }
                    // mark all diagonal from upper right to lower left
                    for(size_t k=0; k<=row;++k) {
                        int j = i-(k-level);
                        if( j>=0 && j <=column) {
                            if(grid[k][j] == 1) {
                                continue;
                            } else {
                                grid[k][j]=0;
                            }
                        }
                    }      

//version 3
void place(vector<vector<int>>& grid, int level, int n, bool& res);
bool canPlace(vector<vector<int>> &grid, int x,int y) {
    bool isReadyToPlace = true;
    for(size_t i = 0; i<= grid[0].size()-1;++i) {
        if(grid[x][i]==2) {
            isReadyToPlace=false;
            return isReadyToPlace;
        }
    }
    for(size_t i = 0 ; i<=grid.size()-1;++i) {
        if(grid[i][y]==2) {
            isReadyToPlace=false;
            return isReadyToPlace;
        }
    }
    for(size_t i =0;i<= grid.size()-1;++i) {
        int j=y+(i-x);
        if(j>=0 && j<=grid[0].size()-1) {
            if(grid[i][j] == 2) {
                isReadyToPlace=false;
                return isReadyToPlace;
            }
        }
    }
    for(size_t i =0; i<= grid[0].size()-1;++i) {
        int j = y -(i-x);
        if(j >=0 && j<=grid[0].size()-1) {
            if(grid[i][j] ==2) {
                isReadyToPlace=false;
                return isReadyToPlace;
            }
        }
    }
    return isReadyToPlace;
}
bool canPlaceSecurityCameras(int N, vector<vector<int>> grid) {

    vector<vector<int>> gridToPlace = grid;
    bool foundPlace=false;
    int level=0;
    int remain=N;
    place(gridToPlace,level,remain,foundPlace);
    return foundPlace;
}

void place(vector<vector<int>>& grid, int level, int n, bool& res) {
    if(n ==0) {
        res= true;
        return;
    }
    if( level == grid.size()) {
        return;
    }
    size_t row = grid.size()-1;
    size_t column = grid[level].size()-1;
        for(size_t i=0; i <= column;++i) {
                if(grid[level][i] == 1 || !canPlace(grid,level,i)) { // block or can not place, means if placed there is conflict
                    continue;
                } else if (grid[level][i] == 2) {
                   place(grid,level+1,n,res);
                } else if (grid[level][i] == 0 && canPlace(grid,level,i)) {
                    grid[level][i]=2;  // place a camera at level,i
       
                    place(grid,level+1,n-1,res); // recursion
                    // trace back
                    // mark the same level all to 0
                }
        }
    }


    grid[level][i] = 2;     // 放摄像头
mark(grid, level, i, 3); // 把可见区域标记为 3
问题在于：

mark() 里没有跳过摄像头自己 (x, y) 位置；

并且它会无条件地把所有 0 都改成 3；

回溯时你是 grid = backup;，会把上层状态一起清掉；

这样有可能：

清掉了前面合法的摄像头；

或者残留了不该有的“3”，导致后续误判不能放置。

也就是说，回溯逻辑“太重”了，每层都复制整个 grid 效率也低。

several version of this problem still not right, can pass all the test case

bool canPlace(vector<vector<int>> &grid, int x, int y) {
    size_t n = grid.size();
    for (size_t i = 0; i < n; ++i) {
        if (grid[x][i] == 2 || grid[i][y] == 2)
            return false;
    }
    for (int i = 0; i < n; ++i) {
        int j1 = y + (i - x);
        int j2 = y - (i - x);
        if (j1 >= 0 && j1 < n && grid[i][j1] == 2) return false;
        if (j2 >= 0 && j2 < n && grid[i][j2] == 2) return false;
    }
    return true;
}


void mark(vector<vector<int>> &grid, int x, int y, int val) {
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
        if (i != y && grid[x][i] == 0) grid[x][i] = val;
        if (i != x && grid[i][y] == 0) grid[i][y] = val;
    }
    for (int i = 0; i < n; ++i) {
        int j1 = y + (i - x);
        int j2 = y - (i - x);
        if (j1 >= 0 && j1 < n && grid[i][j1] == 0) grid[i][j1] = val;
        if (j2 >= 0 && j2 < n && grid[i][j2] == 0) grid[i][j2] = val;
    }
}

void place(vector<vector<int>>& grid, int level, int n, bool& res) {
    if (n == 0) {
        res = true;
        return;
    }
    if (level == grid.size()) return;

    int columns = grid[level].size();
    for (int i = 0; i < columns; ++i) {
        if (grid[level][i] == 1) continue; 
        if (canPlace(grid, level, i)) {
         
            vector<vector<int>> backup = grid; 
            grid[level][i] = 2;
            mark(grid, level, i, 3); 

            place(grid, level + 1, n - 1, res);

            if (res) return; 
            grid = backup;   
        }
    }

 
    place(grid, level + 1, n, res);
}

bool canPlaceSecurityCameras(int N, vector<vector<int>> grid) {
    vector<vector<int>> gridToPlace = grid;
    bool foundPlace = false;
    int level = 0;
    place(gridToPlace, level, N, foundPlace);
    return foundPlace;
}
this solution can pass 13/15 test case
