#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1; 
    int res = arr.size();
  	
  	while(low <= high) {
      	int mid = low + (high - low)/2;
        
        // If arr[mid] >= target, then mid can be the
        // lower bound, so update res to mid and
        // search in left half, i.e. [lo...mid-1]
      	if(arr[mid] >= target) {
            res = mid;
            high = mid - 1;
        }
        
        // If arr[mid] < target, then lower bound
        // cannot lie in the range [lo...mid] so
        // search in right half, i.e. [mid+1...hi]
      	else {
            low = mid + 1;
        }
    }
  	return res;	
}

int main() {
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int target = 9;
  
    cout << lowerBound(arr, target);
    return 0;
}