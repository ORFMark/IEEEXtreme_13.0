#include <iostream>
#include <list>
using namespace std;

int main() {
    int arrLen = 0;
    int setLen = 0;
    int temp = 0;
    int i = 0;
    int s = 0;
    list<int> arr;
    list<int> set;
    list<int> output;
    cin >> arrLen;
    cin >> setLen;
    for(int i = 0; i < arrLen; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    for(int i = 0; i < setLen; i++) {
        cin >> temp;
        set.push_back(temp);
    }
    set.sort();
    for(int j = 0; j < arrLen+setLen; j++){
        i = arr.front();
        s = set.front();
        if(set.empty()) {
            output.push_back(i);
            arr.pop_front();
        } else if (arr.empty()) {
            output.push_back(s);
            set.pop_front();
        }
        else if(s > i) {
            output.push_back(i);
            arr.pop_front();
        } else {
            output.push_back(s);
            set.pop_front();
        } 
            
        
    }
    for(auto i = output.begin(); i != output.end(); ++i) {
        cout << *i << " ";
    }
    return 0;
}