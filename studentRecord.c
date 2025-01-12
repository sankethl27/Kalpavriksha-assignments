#include<stdio.h>
#include<stdlib.h>

typedef struct RecordStruct
{
	int id;
	char name[20];
}record;

int main()
{	
	record* studentRecord = (record*) malloc(100 * sizeof(record));

	int totalStudents;
	printf("Enter total numeber of student Records : ");
	scanf("%d",&totalStudents);
	printf("Enter id and names of student\n");
	for(int student = 0; student < totalStudents; student++)
	{
		scanf("%d",&studentRecord[student].id);
		scanf("%s",studentRecord[student].name);
	}

	for(int student = 0; student < totalStudents; student++)
	{
		printf("Student %s has id : %d\n",studentRecord[student].name,studentRecord[student].id);
	}
	return 0;
}