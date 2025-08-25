#include <bits/stdc++.h>
using namespace std;

double power_function(double a, int b){
    double acum = 1;
    for(int i = 0; i < b; i++)
        acum *= a;
    
    return acum;
}

double power_function_DC(double a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;

    int b_half = b / 2;

    double partial_result = power_function_DC(a, b_half);

    return partial_result * partial_result;
}

int main(){
    double a = 45;
    int b = 32;
    cout << power_function(a, b) << "\n";
    cout << power_function_DC(a, b) << "\n";

    return 0;
}