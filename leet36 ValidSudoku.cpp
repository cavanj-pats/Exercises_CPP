//leet 36 valid sudoku


#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map <char, int> myMap = {{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
        int n = 9;
        map<char,int> trow, tcol;
        
        vector<map<char, int>> tempGrid(9);
        vector<int> gridCounter(9,0);
       

        for (int i=0; i<n; ++i){
             int rowCounter=0;
             int colCounter=0;
            for (int j=0; j<n; ++j){
                //for columns
                if(board[i][j] !='.'){
                    tcol.insert(std::pair<char, int> (board[i][j],myMap[board[i][j]]));
                    colCounter++;

                    tempGrid[3*(i/3)+(j/3)].insert(std::pair<char, int> (board[i][j],myMap[board[i][j]]));
                    gridCounter[3*(i/3)+(j/3)]+=1;

                    
                }

                //for a row reverse i and j
                if(board[j][i] !='.'){
                    trow.insert(std::pair<char, int> (board[j][i],myMap[board[j][i]]));
                    rowCounter++;

                    

                }

                


            }
            if(tcol.size() !=colCounter) return false;
            if(trow.size() != rowCounter) return false;

            

            tcol.clear();
            trow.clear();
        }

        for(int i = 0; i<n; ++i){
            if(tempGrid[i].size() != gridCounter[i]) return false;
        }

        return true;
        
    }
};


int main(){
    Solution sol;
    //map <char, int> myMap = {{'3',3},{'4',4}};

    vector<vector<char>> myMap = {{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};

cout << sol.isValidSudoku(myMap) << endl;
   // myMap.insert(std::pair<char,int>('1',1)) ;
   // myMap.insert(std::pair<char,int>('1',1)) ;



    //cout <<myMap['3'] << endl;
    //cout << myMap.count('3') << endl;

    return 0;
}