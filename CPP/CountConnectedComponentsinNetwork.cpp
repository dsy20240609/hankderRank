// not working code using set<int> can not combine multiple groups [0,1] [3,4] [1,3]
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'countIsolatedCommunicationGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY links
 *  2. INTEGER n
 */

bool checkInGroup(vector<set<int>> & record, vector<int> pair) {
    for(size_t i = 0 ; i <record.size();++i) {
         if(record[i].find(pair[0]) != record[i].end() ||
            record[i].find(pair[1]) != record[i].end()) {
            record[i].insert(pair[0]);
            record[i].insert(pair[1]);
            return true;
         } 
    }
    return false;
}

int countIsolatedCommunicationGroups(vector<vector<int>> links, int n) {
  vector<set<int>> record;
  for(size_t i=0; i < links.size(); ++i ) {
    if(checkInGroup(record,links[i])) {
       continue; 
    } else {
        set<int> temp;
        temp.insert(links[i][0]);
        temp.insert(links[i][1]);
        record.push_back(temp);
    }
  }
  while(record.size() !=1) {
      for(size_t i=0;i<record.size();++i) {
        for(size_t j=i+1;j<record.size();++j) {
            set<int> temp1 = record[i];
            set<int> temp2 = record[j];
            if(canConbine(temp1,temp2)) {
                
            }
        }
      }
    
  }
  return record.size();
}

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


#include <algorithm>
/*
 * Complete the 'countIsolatedCommunicationGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY links
 *  2. INTEGER n
 */

bool checkInGroup(vector<set<int>> & record, vector<int> pair) {
    for(size_t i = 0 ; i <record.size();++i) {
         if(record[i].find(pair[0]) != record[i].end() ||
            record[i].find(pair[1]) != record[i].end()) {
            record[i].insert(pair[0]);
            record[i].insert(pair[1]);
            return true;
         } 
    }
    return false;
}

bool canCombine(set<int> s1, set<int>s2) {
    for(int i : s1) {
        if(s2.find(i) != s2.end()) {
            return true;
        }
    }
    return false;
}
int countIsolatedCommunicationGroups(vector<vector<int>> links, int n) {
  vector<set<int>> record;
  for(size_t i=0; i < links.size(); ++i ) {
    if(checkInGroup(record,links[i])) {
       continue; 
    } else {
        set<int> temp;
        temp.insert(links[i][0]);
        temp.insert(links[i][1]);
        record.push_back(temp);
    }
  }
  while(record.size() !=1) {
      for(size_t i=0;i<record.size();++i) {
        for(size_t j=i+1;j<record.size();++j) {
            set<int> temp1 = record[i];
            set<int> temp2 = record[j];
            if(canCombine(temp1,temp2)) {             
             set<int> result;
             set_union(temp1.begin(), temp1.end(),
             temp2.begin(), temp2.end(),
             inserter(result, result.begin()));  
            }
        }
      }
    
  }
  return record.size();

  // this is the working code using unite find algorithm, 
  #include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


#include <algorithm>
/*
 * Complete the 'countIsolatedCommunicationGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY links
 *  2. INTEGER n
 */

#include <vector>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // recursively find the root.
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) 
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }  // this is combining trees.
    }

    int countGroups() {
        int cnt = 0;
        for (int i = 0; i < parent.size(); ++i)
            if (parent[i] == i)
                cnt++;
        return cnt;
    }  // count all groups that its parent is the root, then you get the group numbers
};

int countIsolatedCommunicationGroups(vector<vector<int>> links, int n) {
    UnionFind uf(n);
    for (auto& p : links)
        uf.unite(p[0], p[1]);
    return uf.countGroups();
}