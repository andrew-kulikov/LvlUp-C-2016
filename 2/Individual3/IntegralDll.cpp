#include <iostream>
#include <Windows.h>
#include <tchar.h>

using namespace std;

int main() {
	HINSTANCE load;
	load = LoadLibrary(_T("IntegralDll.dll"));
	float(*definiteIntegral) (float, float);
	definiteIntegral = (float(*)(float, float))GetProcAddress(load, "func1");
	cout << "First integral is: " << definiteIntegral(0.6, 2.4) << endl;
	definiteIntegral = (float(*)(float, float))GetProcAddress(load, "func2");
	cout << "Second integral is: " << definiteIntegral(0.4, 1.2) << endl;
	definiteIntegral = (float(*)(float, float))GetProcAddress(load, "func3");
	cout << "Third integral is: " << definiteIntegral(0.5, 1.3) << endl;
	definiteIntegral = (float(*)(float, float))GetProcAddress(load, "func4");
	cout << "Fourth integral is: " << definiteIntegral(0.2, 1.8) << endl;
	if (!FreeLibrary(load))
	{
		cout << _T("Error when cleaning memory!") << endl;
		return GetLastError();
	}
	return 0;
}