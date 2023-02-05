#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long BSLIS(vector<long long>& v, long long l, long long r, long long value){
	while (r - l > 1) {
		long long idx = l + (r - l) / 2;
		if (v[idx] >= value)
			r = idx;
		else
			l = idx;
	}

	return r;
}

long long BSLDS(vector<long long>& v, long long l, long long r, long long value){
	while (r - l > 1) {
		long long idx = l + (r - l) / 2;
		if (v[idx] >= value)
			l = idx;
		else
			r = idx;
	}

	return r;
}

long long increaseL[1000000] = {0};
long long decreaseR[1000000] = {0};
long long decreaseL[1000000] = {0};
long long increaseR[1000000] = {0};

// case 1
// If A[i] is smallest among all end candidates of active lists, 
// we will start new active list of length 1.

// case 2
// If A[i] is largest among all end candidates of active lists,
// we will clone the largest active list, and extend it by A[i].

// case 3
// If A[i] is in between, we will find a list with largest end element that is smaller than A[i]. 
// Clone and extend this list by A[i].
// We will discard all other lists of same length as that of this modified list.
void LIS(vector<long long> &h, char LR){
	vector<long long> tail(h.size(), 0);
	long long length = 1; // always points empty slot in tail
	tail[0] = h[0];

	for (long i = 1; i < h.size(); i++) {
        // case 1
		// new smallest value
		if (h[i] <= tail[0]){
			tail[0] = h[i];
            if (LR == 'L') increaseL[i] = 1;
            if (LR == 'R') decreaseR[i] = 1;
        }
        // case 2
		// new largest value
		else if (h[i] > tail[length - 1]){
			tail[length] = h[i];
            length++;
            if (LR == 'L') increaseL[i] = length;
            if (LR == 'R') decreaseR[i] = length;
        }
        // case 3
        // value between smallest and largest
		else{
            long position = BSLIS(tail, -1, length - 1, h[i]);
			tail[position] = h[i];
            if (LR == 'L') increaseL[i] = position + 1;
            if (LR == 'R') decreaseR[i] = position + 1;
        } 
	}
	//return length;
}

void LDS(vector<long long> &h, char LR){    
    vector<long long> tail(h.size(), 0);
    long long length = 1;
    tail[0] = h[0];

    for (long i = 1; i < h.size(); i++){
        if (h[i] >= tail[0]){
            tail[0] = h[i];
            if (LR == 'L') decreaseL[i] = 1;
            if (LR == 'R') increaseR[i] = 1;
        }
        else if (h[i] < tail[length - 1]){
            tail[length] = h[i];
            length++;
            if (LR == 'L') decreaseL[i] = length;
            if (LR == 'R') increaseR[i] = length;
        }
        else{
            long position = BSLDS(tail, -1, length - 1, h[i]);
            tail[position] = h[i];
            if (LR == 'L') decreaseL[i] = position + 1;
            if (LR == 'R') increaseR[i] = position + 1;
        }
    }
    //return length;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long n;
    cin >> n;
    //# of cheerleaders

    vector<long long> heights(n);
    vector<long long> reverseH(n);
    for (long long i = 0; i < n; i++){
        cin >> heights[i];
        reverseH[n - i - 1] = heights[i];
    }

    LIS(heights, 'L');
    LIS(reverseH, 'R');
    LDS(heights, 'L');
    LDS(reverseH, 'R');

    long long sTs = 0, TsT = 0;
    for (long long i = 1; i < n; i++){
        if (increaseL[i] + decreaseR[n - i - 1] - 1 > sTs)
            sTs = increaseL[i] + decreaseR[n - i - 1] - 1;
        if (decreaseL[i] + increaseR[n - i - 1] - 1 > TsT)
            TsT = decreaseL[i] + increaseR[n - i - 1] - 1;
    }

    cout << max(sTs, TsT);

    return 0;
}

