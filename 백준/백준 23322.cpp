#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int v[2001];

int main(void)
{
	int K, N;
	int chocolate = 0, days = 0;
    cin >> N >> K;

	vector<int>arr(N + 1);
	arr[0] = 0;
    for (int j = 1; j <= N; j++)
        cin >> arr[j];

	for (int i = K + 1; i <= N; i++)
		while (1)
		{
			if (arr[i] != arr[i - K])
			{
				chocolate += arr[i] - arr[i - K];
				days++;
				arr[i] = arr[i - K];
				sort(arr.begin(), arr.end());
			}
			else
				break;
		}

	cout << chocolate << " " << days;
    return 0;
}
