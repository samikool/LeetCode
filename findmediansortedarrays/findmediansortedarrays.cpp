#include <iostream>
#include <vector>
#include <stdio.h>

using std::vector;
using std::cout;
using std::max;
using std::min;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    if(nums1.size() > nums2.size()){
        nums1.swap(nums2);
    }
    //arrays are same length or nums1 is smaller

    int x = nums1.size();
    int y = nums2.size();

    int s = 0;
    int e = x;
    int i,j; 

    int xl, xr, yl, yr;

    while(s <= e){
        i = (s+e)/2;
        j = (x+y+1)/2 - i;

        xl = i == 0 ? INT_MIN : nums1[i-1];
        xr = i == x ? INT_MAX : nums1[i];

        yl = j == 0 ? INT_MIN : nums2[j-1];
        yr = j == y ? INT_MAX : nums2[j];

        if(xl <= yr && yl <= xr) break;

        if(xl > yr) e = i-1;
        else s = i+1;
    }

    if((x+y) % 2) return max(xl,yl);
    else return (max(xl,yl)+min(xr,yr)) / 2.;
}

int main(){
    vector<int> nums1,nums2;
    nums1 = {1,2};
    nums2 = {3,4};

    // nums1 = {1,3,8,9,15};
    // nums2 = {7,11,18,19,21,25};

    // nums1 = {23,26,31,35};
    // nums2 = {3,5,7,9,11,16};

    double res = findMedianSortedArrays(nums1, nums2);
    cout << res << '\n';

    return 0;
}