#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	int sum = 0;
	cin >> n;
	char k[n];
	cin >> k;
	for(int i=0;i<n;i++)
	{
		sum += k[i] - '0';
		// char�� ������ 0�� ���� int �� ���������� ��ȯ�� 
	}
	cout << sum;
	return 0;
}
