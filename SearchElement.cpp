#include "SearchElement.h"
#include <stdio.h>
#include <string.h>
struct EMPLOYEE
{
	char name[20];
	int bd;
	char male[6];
	int exp;
	int salary;
	struct EMPLOYEE* next;
};
//printf info about selected worker
void ShowInfoAboutWorker(struct EMPLOYEE* X, char* SelectedEmpl)
{
	struct EMPLOYEE* p;//new link to list to switch elements one be one
	for (p = X; p != NULL; p = p->next)
		if(strcmp(p->name, SelectedEmpl)==0)//selected name = employer name
		{
			//print data
			printf("\nSelected worker:");
			printf("\nName:");
			printf(p->name);
			printf(" Birth:");
			printf("%d", p->bd);
			printf(" Male:");
			printf(p->male);
			printf("\tWork Exp:");
			printf("%d", p->exp);
			printf(" Salary:");
			printf("%d", p->salary);
		}
}