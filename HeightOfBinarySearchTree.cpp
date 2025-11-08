int getBinarySearchTreeHeight(vector<int> values, vector<int> leftChild, vector<int> rightChild) {
if (leftChild.empty()) return 0;

    queue<int> q;
    q.push(0);  
    int height = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        //cout << "Level " << height + 1 << ": ";

        for (int i = 0; i < levelSize; i++) {
            int node = q.front();
            q.pop();

            //cout << values[node] << " ";  

            if (leftChild[node] != -1)
                q.push(leftChild[node]);
            if (rightChild[node] != -1)
                q.push(rightChild[node]);
        }

        //cout << endl;  
        height++;      
    }

    return height;
}