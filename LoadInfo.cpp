#include "LoadInfo.h"
#include <string.h>
#include <stdio.h>
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
//to cut useles symbols in shar wi and select info to char* info
void EditInfo(char wi[42], char* info)
{
	int i = 0, j = 0;
	for (; wi[i] != ' '; info[i] = wi[i], i++);//switch elements before ' ' and copy them from wi to info
	info[i] = '\0';//set point of end of string in info
	for (; wi[i] == ' '; i++);//to cut ' '
	for (; wi[j + i] != '\0'; wi[j] = wi[j + i], j++);//move inputted string to begin
	wi[j] = '\0';//reset point of end of string in wi
}
//convert from char to integer
int ConvetToInt(char* m)
{
	int buf = 0;
	for (int i = 0; m[i] >= '0' && m[i] <= '9'; buf = buf * 10 + (m[i] - 48), i++);//converts element of string to int format
	return buf;
}
void LoadWorkersList(struct EMPLOYEE** X, char* FileName)
{
	FILE* Workers;//file link
	*X = NULL;//set empty link to list
	char WI[42];// string to store date from file
	if (fopen_s(&Workers, FileName, "r") != 0)//checking out of file
		printf("\nWorkers file didn`t exists");//file didnqt exists
	else//file exeists
	{
		while (fgets(WI, 42, Workers) != NULL)//read file by string
		{
			struct EMPLOYEE* pt;//link to new element
			char buf[6];//to process data
			pt = (struct EMPLOYEE*) malloc(sizeof(struct EMPLOYEE));//realise memory for new element
			EditInfo(WI, pt->name);//get information about emloyer name and write in to name field
			EditInfo(WI, buf);//get information about emloyer birth day 
			pt->bd = ConvetToInt(buf);//convert birth day from from char to int
			EditInfo(WI, pt->male);//get information about emloyer male and write in to male field
			EditInfo(WI, buf);//get information about emloyer work experiens 
			pt->exp = ConvetToInt(buf);//convert work experince from char to int
			pt->salary = ConvetToInt(WI);//convert salary from from char to int
			pt->next = *X;//connect new element to list
			*X = pt;
		}
	}
	fclose(Workers);//close file 
}