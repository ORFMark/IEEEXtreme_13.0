#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

	int n = 0;
	int a = 0;
	int b = 0;
	int found = 0;
	int aVal;
	int bVal;
	cin >> n;
	int* valArray = new int[n+1];
	a = 1;
	b = 2;
	aVal = 0;
	bVal = 0;
	for(int i = 1; i <= n; i++) {
		valArray[i] = -1;
	}
	printf("%d %d", a, b);
	//fflush(stdout);
	do {
	    fflush(stdout);
		cin >> aVal;
		if(cin.fail()) {
			found++;
			cin.clear();
			cin.ignore();
			//fflush(stdout);
			//fflush(stdin);
			continue;

		}
		if(aVal == -1) {
			break;
		} else {
			if(valArray[aVal] != -1) {
				//cout << a << " " << valArray[aVal];
				//cout << valArray[aVal] << " " << a;
				//fflush(stdout);
				printf("%d %d", a, valArray[aVal]);
                continue;
			} else {
				valArray[aVal] = a;
			}
			cin >> bVal;
			if(valArray[bVal] != -1) {
				printf("%d %d", b, valArray[bVal]);
				continue;
			} else {
				valArray[bVal] = b;
			}
		}
		a+=2;
		b+=2;
		printf("%d %d", a, b);
		//fflush(stdout);
	} while(found < n);
	cout << "-1";
	//fflush(stdout);
	return 0;
}