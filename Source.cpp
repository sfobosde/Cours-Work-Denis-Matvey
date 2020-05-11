#include <stdio.h>
#include <conio.h>
#include "LoadInfo.h"
#include <iostream>

struct EMPLOYEE
{
	char name[20];
	char bd[4];
	char male;
	char exp[2];
	char salary[6];
	struct EMPLOYEE* next;
};

void ShowAllWorkers(struct EMPLOYEE* X);

int main()
{
	setlocale(LC_ALL, "ru"); 
	struct EMPLOYEE *X, *PA;
	char FileName[] = "Workers.txt";
	char SelectedEmpl[20];
	const int pension = 50;
	int midsal;

	//generate workers list
	LoadWorkersList(&X, FileName);

	//show all 
	ShowAllWorkers(X);

	/*//get info about worker
	ShowInfoAboutWorker(X, SelectedEmpl);

	//pension list during alphavite
	ShowRetirmentWorkers(X, &PA);
	printf("\n����������, ��������� ����������� ��������:");
	ShowAllWorkers(PA);

	//midle salary
	midsal = GetMidleSalary(X);
	printf("\n ������� ����� ����� ���� ����������� ����������:%d", midsal);*/

	return 0;
}
void ShowAllWorkers(struct EMPLOYEE* X)
{
	struct EMPLOYEE* p;
	for (p = X; p->next != NULL; p = p->next);
	{
		printf("\nName:");
		printf(p->name);
		printf("\tBirth:");
		printf(p->bd);
		printf(" Male:%c",p->male);
		printf(" Work Exp:");
		printf(p->exp);
		printf(" Salary:");
		printf(p->salary);
	}
}