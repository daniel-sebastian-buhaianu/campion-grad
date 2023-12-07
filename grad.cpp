#include <fstream>
#define GRADMAX 255*26
using namespace std;
int main()
{
	ifstream f("grad.in");
	int n;
	f >> n;
	f.get(); // citesc '\n'
	char s[n+1];
	f.getline(s, n+1);
	f.close();
	int nrc = 0, nrg = 0, grup[GRADMAX+1], i;
	for (i = 0; i <= GRADMAX; i++) grup[i] = 0;
	for (i = 0; s[i];)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			nrc++;
			int grad = 0;
			while (s[i] >= 'a' && s[i] <= 'z')
				grad += s[i++]-'a'+1;
			grup[grad]++;
			if (grup[grad] == 1) nrg++;
		}
		else i++;
	}
	ofstream g("grad.out");
	g << nrc << '\n' << nrg;
	g.close();
	return 0;
}

