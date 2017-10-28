//
//  main.cpp
//  play
//
//  Created by Berk Dehrioğlu on 29/10/2017.
//  Copyright © 2017 Berk Dehrioğlu. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int arr[11][11];
int n,m;
int findRegion(int x, int y);

int main() {
    
    string str;
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    scanf("%d",&m);
    
    cin.ignore();
    
    for(auto i =0; i < n ; i++){
        getline(std::cin,str);
        string temp;
        istringstream iss(str);
        
        for(auto j = 0;j<m;j++)
        {
            iss >> temp;
            arr[i][j] = stoi(temp);
        }
    }
    int mx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1)
                mx = max(mx, findRegion(i, j));
        }
    }
    cout << mx;
    
    return 0;
}



int findRegion(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m
        || arr[i][j] == 0)
        return 0;
    else {
        arr[i][j] = 0;
        return 1 + findRegion(i+1, j) + findRegion(i-1, j) +
        findRegion(i, j+1) + findRegion(i, j-1) +
        findRegion(i+1, j-1) + findRegion(i-1, j+1) +
        findRegion(i+1, j+1) + findRegion(i-1, j-1);
    }
}
