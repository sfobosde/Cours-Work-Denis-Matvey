#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "LoadInfo.h"
#include "SearchElement.h"
#include "RetirementAgeList.h"
#include "Arifmetics.h"

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
	int thisyear = 2020;
	float midsal;

	//generate workers list
	LoadWorkersList(&X, FileName);

	//show all 
	ShowAllWorkers(X);

	//get info about worker
	printf("\nВведите Фамилия_И.О. для поиска:");
	gets_s(SelectedEmpl, sizeof(SelectedEmpl));
	ShowInfoAboutWorker(X, SelectedEmpl);

	//pension list during alphavite
	ShowRetirmentWorkers(X, &PA, thisyear);
	printf("\nСотрудники, достигшие пенсионного возраста в алфавитном порядке:");
	ShowAllWorkers(PA);

	//midle salary
	midsal = GetMidleSalary(X);
	printf("\nСредний оклад среди всех сотрудников составляет:%.2f", midsal);

	printf("\nНажмите <ENTER> для завершения программы.");
	getchar();
	return 0;
}
void ShowAllWorkers(struct EMPLOYEE* X)
{
	struct EMPLOYEE* p;
	for (p = X; p != NULL; p = p->next)
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
		printf("%d", p->salary);
	}
}