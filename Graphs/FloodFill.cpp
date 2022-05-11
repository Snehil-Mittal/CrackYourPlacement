#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int init=0;
    int prevColor;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(!init){
            prevColor=image[sr][sc];
            init=1;
        }
        if(prevColor == newColor)
            return image;
        if(sr<image.size() && sr>=0){
            if(sc<image[sr].size() && sc>=0){
                if(image[sr][sc]==prevColor){
                    image[sr][sc]=newColor;
                    floodFill(image,sr-1,sc,newColor);
                    floodFill(image,sr+1,sc,newColor);
                    floodFill(image,sr,sc-1,newColor);
                    floodFill(image,sr,sc+1,newColor);
                }
            }
        }
        return image;
    }
};