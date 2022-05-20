#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int num[4];
	int test_case, sub_top, sub_down, add_top, add_down, error;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		error = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> num[j];
			if (num[j] <= 0 || num[j] > 10000)
				error = 1;
		}
		if (!error)
		{
			num[0] *= num[3];
			num[2] *= num[1];
			num[1] *= num[3];
			num[3] = num[1];

			add_top = num[0] + num[2];
			add_down = num[1];
			sub_top = num[0] - num[2];
			sub_down = num[1];

			int m = min(add_top, add_down);
			while (m > 1)
			{
				if (!(add_top % m) && !(add_down % m))
				{
					add_top /= m;
					add_down /= m;
					break;
				}
				m--;
			}
			if (sub_top < 0)
				m = min(-sub_top, sub_down);
			else
				m = min(sub_top, sub_down);
			while (m > 1)
			{
				if (!(sub_top % m) && !(sub_down % m))
				{
					sub_top /= m;
					sub_down /= m;
					break;
				}
				m--;
			}

			cout << sub_top << '/' << sub_down << ' ' << add_top << '/' << add_down << endl;
		}
		else
			cout << "입력 오류\n";
	}
	return 0;
}