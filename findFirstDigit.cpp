#include <iostream>

using namespace std;

int findFirstDigit(int input){
    
    return -1;
}

int main(){
    
    while(true)
    {
        int input;
        cout << "Input the value to be tested: " << endl;
        cin >> input;
        cout << "The first inconsistent digit is " << findFirstDigit(input) << endl;
        cout << "Continue (y/n)? " << endl;
        string cont;
        cin >> cont;
        if(cont != "y"){
            return 0;
        }
    }

}