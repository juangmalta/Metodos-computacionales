#include <iostream>

using namespace std;

bool isprimo(int n){
  if (n == 0 || n == 1 || n == 4) return false;
  for (int x = 2; x < n / 2; x++) {
    if (n % x == 0) return false;
  }
  return true;
}

int main(){
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

    return 0;
}