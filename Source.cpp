#include <stdio.h>
#include <conio.h>
#include <iostream>
#include "LoadInfo.h"
#include "SearchElement.h"
#include "RetirementAgeList.h"
#include "Arifmetics.h"

struct EMPLOYEE
{
	char name[20];//to store employer name surname
	int bd;//to store employer birth day
	char male[6];//to store employer male
	int exp;//to store date about work expesince
	int salary;//to stode data about employer salary
	struct EMPLOYEE* next;//link to next elemnt in list
};
//print list elements
void ShowAllWorkers(struct EMPLOYEE* X);
int main()
{
	setlocale(LC_ALL, "ru"); //to use russian symbols
	struct EMPLOYEE *X, *PA;//links to main list and list with pension age employers
	char FileName[] = "Workers.txt";//file with task data
	char SelectedEmpl[20];//name and surname of selected employer
	int thisyear = 2020;//to solve task with pension age: this year
	float midsal;//midle arifmetic salary of all employers

	//generate workers list
	LoadWorkersList(&X, FileName);

	//show all 
	ShowAllWorkers(X);

	//get info about worker
	printf("\n������� �������_�.�. ��� ������:");
	gets_s(SelectedEmpl, sizeof(SelectedEmpl));
	ShowInfoAboutWorker(X, SelectedEmpl);//printf info about selected employer

	//pension list during alphavite
	ShowRetirmentWorkers(X, &PA, thisyear);
	printf("\n����������, ��������� ����������� �������� � ���������� �������:");
	ShowAllWorkers(PA);//show pension age employers for alphavite

	//midle salary
	midsal = GetMidleSalary(X);
	printf("\n������� ����� ����� ���� ����������� ����������:%.2f", midsal);

	printf("\n������� <ENTER> ��� ���������� ���������.");
	getchar();
	return 0;
}
//printf list elements
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