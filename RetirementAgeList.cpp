#include "RetirementAgeList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct EMPLOYEE
{
	char name[20];
	int bd;
	char male[6];
	int exp;
	int salary;
	struct EMPLOYEE* next;
};
void ShowRetirmentWorkers(struct EMPLOYEE* X, struct EMPLOYEE** PA, int thisyear)
{
	*PA = NULL;
	struct EMPLOYEE* p;
	for (p = X; p != NULL; p = p->next)
		if (((strcmp(p->male, "MALE") == 0) && (thisyear - p->bd >= 65)) || ((strcmp(p->male, "FEMALE") == 0) && (thisyear - p->bd >= 60)))
		{
			struct EMPLOYEE *pt, *k, *j; 
			j = NULL;
			pt = (struct EMPLOYEE*) malloc(sizeof(struct EMPLOYEE));
			strcpy_s(pt->name, p->name);
			pt->bd = p->bd;
			strcpy_s(pt->male, 7, p->male);
			pt->exp = p->exp;
			pt->salary = p->salary;
			if (*PA == NULL || strcmp(pt->name, (*PA)->name) < 0)
			{
				pt->next = *PA;
				*PA = pt;
			}
			else
			{
				k = *PA;
				while (k != NULL && strcmp(pt->name, k->name) >= 0)
				{
					j = k;
					k = k->next;
				}
				j->next = pt;
				pt->next = k;
			}
		}
}