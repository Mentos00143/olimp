#include <iostream>
#include <fstream>
#include "windows.h"
using namespace std;
void Shutdown(int);
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	int k = -1;
	ifstream fin("1.txt");
	fin >> k;
	k++;
	int choise;
	do{
		cout << "0 - Подивитись кількість запусків програми за даний сеанс;\n";
		cout << "1 - Завершити сеанс;\n";
		cout << "2 - Вийти з програми.\n";
		cout << "Ваш вибір - ";
		cin >> choise;
		switch (choise)
		{
		case 0:
		{
				  system("cls");
				  ofstream fout("1.txt");
				  fout << k << endl;
				  ifstream fin("1.txt");
				  fin >> a;
				  cout << "Кількість запусків програми: " << a << endl;
				  system("pause>>void");
				  system("cls");
				  break;
		}
		case 1:
		{
				  system("cls");
				  ofstream fout("1.txt");
				  fout << 0 << endl;
				  Shutdown(EWX_LOGOFF);
				  system("pause>>void");
				  system("cls");
				  break;
		}
		case 2:
		{
				  break;
		}
		default:
		{

				   system("cls");
				   cout << "jhikjbnhk" << endl;
				   system("pause>>void");
				   system("cls");
				   break;
		}
		}
	} while (choise != 2);
}
void Shutdown(int type) {
	HANDLE hToken;
	TOKEN_PRIVILEGES* NewState;

	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken);

	NewState = (TOKEN_PRIVILEGES*)malloc(sizeof(TOKEN_PRIVILEGES)+sizeof
		(LUID_AND_ATTRIBUTES));

	NewState->PrivilegeCount = 1;
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &NewState->Privileges[0].Luid);

	NewState->Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, NewState, NULL, NULL, NULL);

	free(NewState);

	CloseHandle(hToken);

	ExitWindowsEx(type, 0);
}