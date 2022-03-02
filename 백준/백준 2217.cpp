#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a < b;
}

int rope[100001];

int main(void)
{
	int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> rope[i];
    sort(rope, rope + N, greater<int>());
 
    long long result = 0;
    for (int i = 0; i < N; i++) {
        long long sum = rope[i] * (i + 1);
        if(sum > result)
            result = sum;
    }
    cout << result;
	return 0;
}
