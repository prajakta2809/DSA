#include <iostream>

using namespace std;

int main()
{
	
	int p=3,q=5,r=5;
     p=1+3+q;
     q=3+6+q;
     r=(r&q)+q;
     r=r+q;
     cout<<p+q+r;
    return 0;
}
