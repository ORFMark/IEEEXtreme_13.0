#include <iostream>

using namespace std;

int main() {
	int k = 0;
	int j = 0;
	int temp = 0;
	int result =0;
	cin >> k;
	cin >> j;
	/*
    if(k ==0 || j == 0) {
        cout << 0;
        return 0;
    } else {
        if(k > j) { 
          cout << (j/2 + 1);
        } else if (k < j) {
            cout << (k/2 +1);
        } else {
            cout << k;
        }
    }
	 */
	if((k == 0 || j== 0) || (j == 1 && k == 1)) {
		cout << 0;
		return 0;
    }
	else if(k >= 2*j) {
		cout << j;
		return 0;
	} else if (j >= 2*k) {
		cout << k;
		return 0;
	} else {
		if (j >=3 && k >= 3) {
			if(k > j) {
				temp = k-j;
				k-= temp*2;
				j-= temp;
				result+=temp;
			} else {
				temp = j-k;
				j-= temp*2;
				k-= temp;
				result+=temp;
			}

		}
		if (j >=3 && k >= 3) {
			if(k > j) {
				temp = j/3;
				j-= temp*3;
				k-= temp*3;
				result += 2*temp;
			} else {
				temp = k/3;
				j-= temp*3;
				k-= temp*3;
				result += 2*temp;
			}
		}
		if(j >= 1 && k >=1 && j+k>3 ) {
			while((k >= 2 && j >= 1) || (k >= 1 && j >= 2)) {
				if(k>=j) {
					k-=2;
					j--;
					result++;
				} else {
					j-=2;
					k--;
					result++;
				}
			} 
		}
	}


	cout << result;
	return 0;
}