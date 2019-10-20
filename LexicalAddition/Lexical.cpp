#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<int, int> hash;
	int lower; // lower limit for values
	int upper; // upper limit for values
	int goal; // N, the target sum
	int orig; // original
	int range; // = upper - lower
	cin >> goal;
	cin >> lower;
	cin >> upper;
	orig = goal; // original
	range = upper-lower;
	if( goal < lower) { /* invalid case*/
		cout << "NO" << endl;
		return 0;
	} else if (goal >= lower && goal <= upper) { // between upper and lower, so the smallest one is itself
		cout << "YES" << endl;
		cout << goal << " ";
		return 0;
	} else { //greater than upper
		while(upper>= lower){
			for(int i = 0; i <= upper - lower; i++){ //populate the hashmap
				hash[lower+i] = 0;
			}
			while(goal >= upper) { //take out as many uppers as possible
				hash[upper]++; // these will be lexicographically larger than any other
				goal-=upper;   // partial sum
			}
			if(goal == 0) { //evenly divided into upper
				cout << "YES" << endl;
				for(int j = 0; j <= range; j++) {
					for(int i = 0; i < hash[lower + j]; i++) {
						cout << lower + j << " ";
					}
				}
				return 0;
			}
			else if (goal >= lower && goal <= upper){ //did not evenly divide but the
			                                          //remainder was within the range
				hash[goal]++;
				cout << "YES" << endl;
				for(int j = 0; j <= range; j++) {
					for(int i = 0; i < hash[lower + j]; i++) {
						cout << lower + j << " ";
					}
				}
				return 0;
			} else { // nothing good, this is difficult
				//cout << "bad juju";
				while(hash[upper] > 0) {
					hash[upper]--;
					goal+= upper; // put back uppers
					for(int i = 1; upper - i >= lower; i++) { //try subtracting upper -i
						//cout << "Trying: " << upper-i << endl;
						while(goal >= upper-i){ //at least upper-i remaining
							hash[upper-i]++;
							goal -= upper-i;
						} 
						if(goal == 0) { //found it
							cout << "YES" << endl;
							for(int j = 0; j <= range; j++) {
								for(int i = 0; i < hash[lower+j]; i++) {
									cout << lower+j << " ";
								}
							}
							return 0;
						}
						else if (goal >= lower) {
							hash[goal]++;
							cout << "YES" << endl;
							for(int j = 0; j <= range; j++) {
								for(int i = 0; i < hash[lower + j]; i++) {
									cout << lower + j << " ";
								}
							}
							return 0;

						} else { //took out too much, give some back
							goal += upper-i;
							hash[upper-i]--;
						}
					}
				}
			}
			//cout << "miserable failure!";
			upper--;
			goal = orig;
		}
		cout << "NO";
		return 0;
	}
	cout << "NO";
	return 0;
}