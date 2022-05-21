#include <iostream>
#include <chrono>

using namespace std;

bool isprimo(int n){
  if (n == 0 || n == 1 || n == 4) return false;
  for (int x = 2; x < n / 2; x++) {
    if (n % x == 0) return false;
  }
  return true;
}

int main(){
    auto start = chrono::steady_clock::now(); 
    int sum=0;
    for (int i = 0; i < 5000000; i++)
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