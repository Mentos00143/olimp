#include <iostream>
#include <time.h>
using namespace std;
void main()
{

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*const int n = 10;
	int a[n], i, s = 0;
	srand(time(NULL));
	int k;
	for (i = 0; i < n; i++)
	{
		k = rand();
		cout << "k = " << k << endl;
		s += (!((a[i] = k % 10) % 2));
		cout <<"s = " << s << endl;
	}*/

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int x = 1, y = 2;
	int * const p = &x;
	p = &y;
	cout << x << "," << y << "," << *p << endl;

	system("pause>>void");
}