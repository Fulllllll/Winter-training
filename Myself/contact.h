#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[5];
	char addr[30];
	char tele[12];
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;

void InitContact(Contact* pc);
void AddContact(Contact* pc);
void ShowContact(const Contact* pc);
void DeleteContact(Contact* pc);
void Searchcontact(const Contact* pc);
void SortByName(Contact* con);
void Modifycontact(const Contact* pc);
void ClearContact(Contact* con);
void DestoryContact(Contact* pc);
void SaveContact(Contact* pc);