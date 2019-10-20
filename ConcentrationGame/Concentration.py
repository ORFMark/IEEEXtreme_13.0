#include <iostream>

using namespace std;
bool validString(string val) {
    if(val.length() == 1) {
        return true;
    }
    unsigned int i = 0;
    //cout << "Finding Split!" << endl;
    for(i = 0; i < val.length() - 1; i++) {
        if(val.at(i) > val.at(i+1)) {
            break;
        }
    } 
   // cout << "Found it !" << endl;
    if(i == val.length()-1) {
        return true;
    }
    else {
        string start;
        start = val.substr(0, i+1);
      
        //cout << "Start: " << start;
        //cout << "Val: " << val;
        string end = val.substr(i+1);
            if(start.length() < end.length()) {
                return true;
            } else if (start.length() == end.length()) {
                auto i = start.begin();
                auto j = end.begin();
                while (i != start.end()) {
                    if (*i > *j) {
                        return false;
                    }
                }
                return true;
        } else {
            return false;
        }
    }
}

int main() {
    int num;
    string val;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> val;
        if(validString(val)) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
}