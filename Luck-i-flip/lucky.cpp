#include <iostream>
#include <vector>
using namespace std;

int main() {
    // variables
    int b = 0; // amount of bets
    int n = 0; // length of array
    int m = 0; // min winning draws for worst bets
    
    cin >> b;
    string inputBets[b];
    for (int i = 0; i < b; i++) {
        cin >> inputBets[i];
    }
    
    int dimensions = inputBets[0].size(); // get number of dimensions
    vector<vector<int>> inputBetsInt;
    for (int i = 0; i < dimensions; i++) {
        inputBetsInt.push_back(vector<int>);
        for (auto j = inputBets[i].begin(); j != inputBets[i].end(); ++j) {
            inputBetsInt[i].push_back((int)*j);
        }
    }
    
    // create reference location of bet
    // loop for each array in inputBetsInt
        // move down/right/left/etc. by one space
        // repeat for two spaces
        // check if bump into other bet, if not, increment possibilities into a map
        // otherwise, do not
    // output minimum value in map
    
}