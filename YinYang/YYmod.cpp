#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int n = 0;
    int m = 0;
    cin >> n;
    m = n-1;
    for(int i = 0; i < n; i++){
        if(i % m && i+1 < n) {
            cout << "Yy";
            i++;
        } else {
            cout << 'y';
        } 
    }
}