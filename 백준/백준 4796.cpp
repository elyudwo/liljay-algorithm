#include <iostream>

using namespace std;

int main(void)
{
	int L,P,V;
	int sum;
	int i = 0;
	while(1)
	{
		cin >> L >> P >> V;
		if(L == 0 && P == 0 && V == 0)
			break;
		sum = (V/P) * L + min(V%P,L);
		cout << "Case " << ++i << ": " << sum << "\n";
	}
	
	
	return 0;
}
