#include<iostream>
#include<cstdlib>
#include<thread>
using namespace std;


int main(){
    
    cout<<"Starting web automation program\n";

    system("start \"\" brave");

    this_thread::sleep_for(chrono::seconds(3));

    system("winapp ui invoke \"New Tab\" -a brave");

    this_thread::sleep_for(chrono::seconds(1));

    system("winapp ui send-keys \"Ctrl+l\" -a brave");

    this_thread::sleep_for(chrono::seconds(1));

    system("winapp ui send-keys \"Terry A Davis\" -a brave");

    system("winapp ui send-keys \"Enter\" -a brave");
    
    this_thread::sleep_for(chrono::seconds(10));

    system("taskkill /IM brave.exe /F");

    cout<<"Work done boss\n";


    return 0;
}