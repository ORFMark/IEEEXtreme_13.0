#include <iostream>

using namespace std;

int main() {
    int min = -1;
    int temp = 0;
    int len = 0;
    int minOcc = 0;
    cin >> temp;
    cin >> len;
    for(int i = 0; i < len; i++) {
        cin >>temp;
        cin >> temp;
        cin >> temp;
        if(temp == min) {
            minOcc++;
        } else if (min > temp) {
            min = temp;
            minOcc = 1;
        }
    }
    cout << minOcc;
    return 0;
}