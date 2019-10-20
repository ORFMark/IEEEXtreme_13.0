#include <iostream>
using namespace std;

int main() {
    // variables
    int N = 0; //N is # vertices
    int M = 0; //M is # other points
    int xMax = 0;
    int yMax = 0;
    int xMin = 0;
    int yMin = 0;
    int inPolySize = 0;
    int outPolySize = 0;
    int inPoly[inPolySize][2];
    int outPoly[outPolySize][2];
    int totalConnections = 0;
    int m = 0;
    int b = 0;
    int crossPointx = 0;
    int crossPointy = 0;
    bool xCross = false;
    bool yCross = false;
    
    // read in ints
    cin >> N;
    //cout << "N: " << N << endl;
    cin >> M;
    
    // arrays
    int arrayN[N][2];
    int arrayM[M][2];
    
    // populate arrays
    for (int i = 0; i < N; i++){
        cin >> arrayN[i][0];
        cin >> arrayN[i][1];
    }
    
    for (int i = 0; i < M; i++){
        cin >> arrayM[i][0];
        cin >> arrayM[i][1];
    }
    
    // find largest x polygon point
    xMax = arrayN[0][0];
    for (int i = 1; i < N; i++){
        if (arrayN[i][0] > xMax){
            xMax = arrayN[i][0];
        }
    }
    
    // find largest y polygon point
    yMax = arrayN[0][1];
    for (int i = 1; i < N; i++){
        if (arrayN[i][1] > yMax){
            yMax = arrayN[i][1];
        }
    }
    
    // find smallest x polygon point
    xMin = arrayM[0][0];
    for (int i = 1; i < N; i++){
        if (arrayN[i][0] < xMin){
            xMin = arrayN[i][0];
        }
    }
    
    // find smallest y polygon point
    yMin = arrayN[0][1];
    for (int i = 1; i < N; i++){
        if (arrayN[i][1] < yMin){
            yMin = arrayN[i][1];
        }
    }
    
    // check if M values are in poly and sort
    for(int i = 0; i < M; i++){   // for each point M
        for(int e = 0; i < N - 1; i++) {    // for each vertice N
            m = (arrayN[e][1] - arrayN[e+1][1]) / (arrayN[e][0] - arrayN[e+1][0]);
            b = arrayN[e][1] - (m * arrayN[e][0]);
            crossPointx = (m * arrayM[i][0]) + b;
            crossPointy = (m * arrayN[i][1]) + b;
            if (crossPointx < xMax && crossPointx > xMin) {
                xCross = true;
                cout << "x true" << endl;
            } else if (crossPointy < yMax && crossPointy > yMin) {
                yCross = true;
                cout << " y true" << endl;
            }
            if (xCross && yCross) {
                cout << "in poly" << endl;
                inPoly[inPolySize][0] = arrayM[i][0];
                inPoly[inPolySize][1] = arrayM[i][1];
                inPolySize++;
            } else {
                outPoly[outPolySize][0] = arrayM[i][0];
                outPoly[outPolySize][1] = arrayM[i][0];
                outPolySize++;
            }
        }
    }
    
    // compute amount of crossings in shape
    totalConnections += inPolySize;
    if (inPolySize >= 3) {
    totalConnections += 2 * (inPolySize - 3);
    for (int i = 0; (inPolySize - i) < 0; i++){
        totalConnections += inPolySize - i;
    }
    }
    
    totalConnections += outPolySize;
    if (outPolySize >= 3 ) {
    totalConnections += 2 * (outPolySize - 3);
    for (int i = 0; (outPolySize - i) < 0; i++){
        totalConnections += outPolySize - i;
    }
    }
    
    cout << totalConnections;
    
    return 0;
}

