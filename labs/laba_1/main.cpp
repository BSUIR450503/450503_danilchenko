// child.cpp: определяет точку входа для консольного приложения.
//


#include <Windows.h>

int main(int argc, char** argv)
{
	int x = 0;
	x = atoi(argv[1]);
	x*=x;
	
	system("pause");

	return x;
	
}

