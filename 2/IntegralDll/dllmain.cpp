#include "stdafx.h"
#include <Windows.h>
#include <cmath>
#include <iostream>
#include "Functions.h"

using namespace std;

// Главная функция
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) float func1(float a, float b) {
	int n;
	cout << "Number of parts? ";
	cin >> n;
	float h = (b - a) / n;
	float integral;
	integral = 0;
	for (float x = a + h / 2; x < b; x += h) {
		float f1 = sqrt(1.1 * x * x + 0.9) / (1.6 + sqrt(0.8 * x * x + 1.4));
		integral += h * f1;
	}
	return integral;
}

extern "C" __declspec(dllexport) float func2(float a, float b) {
	int n;
	cout << "Number of parts? ";
	cin >> n;
	float h = (b - a) / n;
	float integral;
	integral = 0;
	for (float x = a + h / 2; x < b; x += h) {
		float f2 = cos(0.8 * x * x + 1) / (1.4 + sin(0.3 * x + 0.5));
		integral += h * f2;
	}
	return integral;	
}

extern "C" __declspec(dllexport) float func3(float a, float b) {
	int n;
	cout << "Number of parts? ";
	cin >> n;
	float h = (b - a) / n;
	float integral;
	integral = 0;
	for (float x = a + h / 2; x < b; x += h) {
		float f3 = 1 / sqrt(x * x + 2);
		integral += h * f3;
	}
	return integral;
}

extern "C" __declspec(dllexport) float func4(float a, float b) {
	int n;
	cout << "Number of parts? ";
	cin >> n;
	float h = (b - a) / n;
	float integral;
	integral = 0;
	for (float x = a + h / 2; x < b; x += h) {
		float f4 = sqrt(x + 1) * cos(x * x);
		integral += h * f4;
	}
	return integral;
}