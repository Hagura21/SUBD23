#include "DoubleList.h"

using namespace std;

int main() 
{
	DoubleList <int> DL1;
	DL1.PushB(15);
	DL1.PushB(23);
	DL1.Add(67, 1);
	cout << DL1;
	return 0;
	
}