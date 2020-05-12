#include <stdio.h>
#include <conio.h>
#include "LoadInfo.h"
#include <iostream>

struct EMPLOYEE
{
	char name[20];
	int bd;
	char male[6];
	int exp;
	int salary;
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
	printf("\nСотрудники, достигшие пенсионного возраста:");
	ShowAllWorkers(PA);

	//midle salary
	midsal = GetMidleSalary(X);
	printf("\n Средний оклад среди всех сотрудников составляет:%d", midsal);*/

	return 0;
}
void ShowAllWorkers(struct EMPLOYEE* X)
{
	struct EMPLOYEE* p;
	for (p = X; p->next != NULL; p = p->next);
	{
		printf("\nName:");
		printf(p->name);
		printf(" Birth:");
		printf("%d", p->bd);
		printf(" Male:");
		printf(p->male);
		printf(" Work Exp:"); 
		printf("%d", p->exp);
		printf(" Salary:");
		printf("%d\n", p->salary);
	}
}