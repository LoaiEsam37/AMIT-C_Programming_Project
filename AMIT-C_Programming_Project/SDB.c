#include "SDB.h"

student Students[MAX_DB_SIZE];
uint8 studentCount;


bool SDB_IsFull() {
	return studentCount >= MAX_DB_SIZE ? TRUE : FALSE;
}


uint8 SDB_GetUsedSize() {
	return studentCount;
}


bool SDB_AddEntry() {
	if (SDB_IsFull()) {
		printf("DB is Full.");
		return FALSE;
	}


	printf("Enter Student Data:\n");

	student Instance;

	uint8 studentId = readUInt("Student ID: ");
	if (SDB_IsIdExist(studentId)) {
		printf("Error: Student ID %u already exists.\n", studentId);
		return FALSE;
	}
	else {
		Instance.Student_ID = studentId;
	}

	Instance.Student_year   = readUInt("Student Year: ");
	Instance.Course1_ID     = readUInt("First Course ID: ");
	Instance.Course1_grade  = readUInt("First Course Grade: ");
	Instance.Course2_ID     = readUInt("Second Course ID: ");
	Instance.Course2_grade  = readUInt("Second Course Grade: ");
	Instance.Course3_ID     = readUInt("Third Course ID: ");
	Instance.Course3_grade  = readUInt("Third Course Grade: ");

	Students[studentCount] = Instance;
	studentCount++;

	return TRUE;
}


void SDB_DeleteEntry(uint32 id) {
	int found = -1;
	for (uint8 i = 0; i < studentCount; i++) {
		if (Students[i].Student_ID == id) {
			found = i;
			break;
		}
	}
	if (found != -1) {
		for (uint8 i = found; i < studentCount - 1; i++) {
			Students[i] = Students[i + 1];
		}
		studentCount--;
	}
}


bool SDB_ReadEntry(uint32 id) {
	for (uint8 i = 0; i < studentCount; i++) {
		if (Students[i].Student_ID == id) {
		student Instance = Students[i];
		printf("Student ID: %d\n", Instance.Student_ID);
		printf("Student Year: %d\n", Instance.Student_year);
		printf("First Course ID: %d\n", Instance.Course1_ID);
		printf("First Course Grade: %d\n", Instance.Course1_grade);
		printf("Second Course ID: %d\n", Instance.Course2_ID);
		printf("Second Course Grade: %d\n", Instance.Course2_grade);
		printf("Third Course ID: %d\n", Instance.Course3_ID);
		printf("Third Course Grade: %d\n", Instance.Course3_grade);
		return TRUE;
		}
	}
	return FALSE;
}


void SDB_GetList(uint8* count, uint32* list) {
	if (count == NULL || list == NULL) return;

	*count = studentCount;
	for (uint8 i = 0; i < studentCount; i++) {
		list[i] = Students[i].Student_ID;
	}
}


bool SDB_IsIdExist(uint32 id) {
	for (int i = 0; i < studentCount; i++) {
		if (Students[i].Student_ID == id) return TRUE;
	}
	return FALSE;
}