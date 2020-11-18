#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "./student.h"
#include <string.h>


int main(){
    unsigned index;
    Student myStudent;

    printf("Index: ");
    scanf("%d", &index);
    int fd= open(dbName, O_RDONLY, 0);
    int offset = index * sizeof(Student);
    lseek(fd, offset, SEEK_SET);
    read(fd, &myStudent,sizeof(Student));
    close(fd);
	printf("attribute: ");
	char attributeName[20];
	scanf("%s", attributeName);
	if(strcmp(attributeName,"id")==0){
		printf("new id: ");
		scanf("%d", &myStudent.id);
	}
	if(strcmp(attributeName,"firstName")==0){
		printf("new firstName: ");
		scanf("%s", &myStudent.firstName);
	}
	if(strcmp(attributeName,"lastName")==0){
		printf("new lastName: ");
		scanf("%s", &myStudent.lastName);
	}
	if(strcmp(attributeName,"semester")==0){
		printf("new semester: ");
		scanf("\n %c", &myStudent.semester);
	}
	fd = open(dbName, O_WRONLY, 0);
	lseek(fd, offset, SEEK_SET);
	write(fd, &myStudent, sizeof(Student));
	close(fd);
    
    return 0;

}