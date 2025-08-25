#include <bits/stdc++.h>
using namespace std;

int max_range_sum(int A[], int l, int r){
    int max_sum = INT_MIN;
    for(int i = l; i <= r; i++){
        int sum = 0;
        for(int j = i; j <= r; j++){
            sum += A[j];
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}

int crossSum(int A[], int l, int m, int r){
    int maxLeft = INT_MIN;
    int maxRight = INT_MIN;
    
    int sum = 0;
    for(int i = m; i >= l; i--){
        sum += A[i];
        if(sum > maxLeft)
            maxLeft = sum;
    }

    sum = 0;
    for(int i = m + 1; i <= r; i++){
        sum += A[i];
        if(sum > maxRight)
            maxRight = sum;
    }

    return maxLeft + maxRight;
}

int max_range_sum_DC(int A[], int l, int r){
    if(l == r) return A[l];

    int m = (l + r) / 2;

    int leftMaxSum = max_range_sum_DC(A, l, m);
    int rightMaxSum = max_range_sum_DC(A, m + 1, r);
    int crossMaxSum = crossSum(A, l, m, r);

    return max(max(leftMaxSum, rightMaxSum), crossMaxSum);
}

int main(){
    int n = 8;
    //int A[n] = {2, -4, 3, -1, 2, -4, -1, 6};
    int A[n] = {4, -2, -8, 5, -2, 7, 1, -3};

    cout << max_range_sum(A, 0, n-1) << "\n";
    cout << max_range_sum_DC(A, 0, n-1) << "\n";

    return 0;
}
