#include"contact.h"

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录已满,添加失败\n");
		return;
	}
	printf("输入名字：");
	scanf("%s", pc->data[pc->sz].name);
	printf("输入年龄：");
	scanf("%d", &pc->data[pc->sz].age);
	printf("输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	printf("输入地址：");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("添加成功\n");
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n",
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}
int FindByName(const Contact* pc, char name[])
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;
}
void DeleteContact(Contact* pc)
{
	char name[20] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，删除失败\n");
		return;
	}
	printf("请输入删除人的姓名：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		for (int i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}
void Searchcontact(const Contact* pc)
{
	char name[20] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，查找失败\n");
		return;
	}
	printf("请输入查找人的姓名：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("查找成功：\n");
		printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n",
			pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
	}
}
void Modifycontact(const Contact* pc)
{
	char name[20] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，修改失败\n");
		return;
	}
	printf("请输入修改人的姓名：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("输入名字：");
		scanf("%s", pc->data[pos].name);
		printf("输入年龄：");
		scanf("%d", &pc->data[pos].age);
		printf("输入性别：");
		scanf("%s", pc->data[pos].sex);
		printf("输入电话：");
		scanf("%s", pc->data[pos].tele);
		printf("输入地址：");
		scanf("%s", pc->data[pos].addr);
		printf("修改成功\n");
	}
}

int cmp_name(void* e1, void* e2)
{
	return strcmp((*(PeoInfo*)e1).name, (*(PeoInfo*)e2).name);
}
void SortByName(Contact* pc)
{
	qsort((void*)pc->data, pc->sz, sizeof(PeoInfo), cmp_name);
}

void ClearContact(Contact* pc)
{
	memset(pc->data, 0, pc->sz * sizeof(PeoInfo));
	pc->sz = 0;
}