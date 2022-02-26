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
		printf("ͨѶ¼����,���ʧ��\n");
		return;
	}
	printf("�������֣�");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������䣺");
	scanf("%d", &pc->data[pc->sz].age);
	printf("�����Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����绰��");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�����ַ��");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ�\n");
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�գ�ɾ��ʧ��\n");
		return;
	}
	printf("������ɾ���˵�������");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		for (int i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�\n");
	}
}
void Searchcontact(const Contact* pc)
{
	char name[20] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ʧ��\n");
		return;
	}
	printf("����������˵�������");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("���ҳɹ���\n");
		printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n",
			pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].addr);
	}
}
void Modifycontact(const Contact* pc)
{
	char name[20] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޸�ʧ��\n");
		return;
	}
	printf("�������޸��˵�������");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("�������֣�");
		scanf("%s", pc->data[pos].name);
		printf("�������䣺");
		scanf("%d", &pc->data[pos].age);
		printf("�����Ա�");
		scanf("%s", pc->data[pos].sex);
		printf("����绰��");
		scanf("%s", pc->data[pos].tele);
		printf("�����ַ��");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ�\n");
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