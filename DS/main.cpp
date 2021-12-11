#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int data;
    Node()
    {
        data = 0;
    }
    Node(int d)
    {
        data = d;
    }
};

int main()
{
    Node n_1 = Node(3);
    Node n_2 = n_1;
    cout << n_1.data << endl;
    n_2.data = 4;
    cout << n_2.data << endl;
    cout << n_1.data << endl;
}