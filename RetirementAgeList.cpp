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
//genarate new list with element of list X and set them according alphavite
void ShowRetirmentWorkers(struct EMPLOYEE* X, struct EMPLOYEE **PA, int thisyear)
{
	*PA = NULL;//set empty link to new list
	struct EMPLOYEE* p;//new link of list to switch element one by one
	for (p = X; p != NULL; p = p->next)//switch element one by one
		if (((strcmp(p->male, "MALE") == 0) && (thisyear - p->bd >= 65)) || ((strcmp(p->male, "FEMALE") == 0) && (thisyear - p->bd >= 60)))//fing employer in pension age
		{
			struct EMPLOYEE *pt, *k, *j; //new links to add new element to PA list
			j = NULL;//set emty link 
			pt = (struct EMPLOYEE*) malloc(sizeof(struct EMPLOYEE));//realise memery to new element
			strcpy_s(pt->name, p->name);//copy employer name
			pt->bd = p->bd;//copy birth day
			strcpy_s(pt->male, 7, p->male);//copy employer male
			pt->exp = p->exp;//copy employer work experience
			pt->salary = p->salary;//cope salary
			if (*PA == NULL || strcmp(pt->name, (*PA)->name) < 0)//if new elemnt the first elemnet or it should stay as first elemnet according alphavite
			{
				//connect new element to list
				pt->next = *PA;
				*PA = pt;
			}
			else
			{
				k = *PA;
				//find place of element according alphavite
				while (k != NULL && strcmp(pt->name, k->name) >= 0)
				{
					//set element to list
					j = k;
					k = k->next;
				}
				//connect other elements to new element
				j->next = pt;
				pt->next = k;
			}
		}
}