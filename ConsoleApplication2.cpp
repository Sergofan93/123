// ConsoleApplication2.cpp: главный файл проекта.

#include "stdafx.h"
#include "iostream"
#include <omp.h>
#include "windows.h"

using namespace System;

int func(int x)
{
	Sleep(rand()%1000);
		return (x * 2);
}

int main()
{
	int* x = new int[10];
	int i;



#pragma omp parallel for num_threads(10)
	for (i = 0; i < 10; i++)
		{	
			x[i] = func(i);
		}
	

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", x[i]);
	}
	delete[] x;

	Console::ReadLine();
    return 0;
}
