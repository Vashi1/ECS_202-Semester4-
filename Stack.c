#include <stdio.h>
#include <stdlib.h>
typedef struct studentdb{
	int Rollno;
	int Batchno;
	struct studentdb *next;
}Student;
Student *search(Student *ptr, int rollno){
	if (ptr == NULL)
		return NULL;
	else if (ptr -> RollNo == rollno)
		return ptr;
	else
		return search(ptr->next, rollno);
}
void insert(Student **ptr, int rollno){
	Student *p;
	p = (Student *) maclloc(sizeof(Student));
	printf("Enter student BAtchnp:");
	scanf("%d", 
