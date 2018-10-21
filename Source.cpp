#include <iostream>
#include <time.h>

using namespace std;

void myswap(int a, int b) // значение через &
	{

		int c;
		c = a; a = b; b = c;
	}

int sum(int *mas, int l)
{
	int s = 0;
	for (int i = 0; i < l; i++)
		s += mas[i];
	return s;
}


int main1()
{
	int a = 7;
	/*char s[100];

	strcat_s(s, "fdfdfd");


	cout << "Hello, world!" << a << endl;
	printf("a= %d",a);*/

	const int  size = 5;
	int mas[size];
	int *m;

	for (int i = 0; i < size; i++)
	{
		mas[i] = i;
	}

	for (int i = 0; i < 2*size; i++)
	{
		printf("%d", mas[i]);
	}

	
	printf("\n");

	m = &a;
	printf("%d\n", m);

	*m = 500;
	printf("%d\n", a);

	srand(time(0));

	m = new int[100];

	for (int i = 0; i < 100; i++)
	{
		m[i] = rand() % 100;
		printf("%d\n", mas[i]);
	}

	delete m;
	int k = 10, l = 5;
	myswap(k, l);

	printf("%d\n%s", k, l);

	sum(mas, 5);
	
	
	return 0;
	//system("pause");
}