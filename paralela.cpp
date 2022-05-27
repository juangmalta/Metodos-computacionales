#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;

bool isprimo(int n){
            if (n < 2)
                return false;

            for (int divisor = 2; divisor <= sqrt(n); divisor++)
            {
                if (n % divisor == 0)
                    return false;
            }
            return true;
        };


int main(){
    auto start = chrono::steady_clock::now(); 
    int sum=0;
    for (int i = 0; i < 10; i++)
    {
        if (isprimo(i)==true)
        {
            sum+=i;
            cout<<i<<endl;
        }
        
    }
    cout<<"sum is "<<sum<<endl;
    auto end = chrono::steady_clock::now();
        cout << "Elapsed time in seconds: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec";
    return 0;
}