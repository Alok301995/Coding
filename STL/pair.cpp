#include<bits/stdc++.h>
using namespace std;




int main(){
    pair<int , string> p;
    p = make_pair(2 ,"alok");// first way of make pair 
    cout<< p.first << p.second <<endl;
// second way of makeing pair.
    p.first = 3;
    p.second = "Hey";
    // third way

    p = {3 , "alok dhiman"};
    cout<<p.first <<p.second <<endl;


    // pair can be copied and they are copied by using call by value 
    pair< int  , string> p1;
    p1 = p;

    cout<< "second pair" << p1.first  << p1.second << endl;
   



}