#include "SDBAPP.h"

void SDB_APP() {
	uint8 choice;
	while (1) {
		printf("1. To add entry, enter 1                       \n");
		printf("2. To get used size in database, enter 2       \n");
		printf("3. To read student data, enter 3               \n");
		printf("4. To get the list of all student IDs, enter 4 \n");
		printf("5. To check is ID is existed, enter 5          \n");
		printf("6. To delete student data, enter 6             \n");
		printf("7. To check is database is full, enter 7       \n");
		printf("8. To exit enter 0                             \n");
		
		choice = readUInt(": ");
		if (choice == 8) break;
		SDB_action(choice);
	}
}

void SDB_action(uint8 choice) {
	switch (choice) {
		case 1:
			SDB_AddEntry();
			break;
		case 2:
			SDB_GetUsedSize();
			break;
		case 3:
			//SDB_ReadEntry();
			break;
		case 4:
			//SDB_GetList();
			break;
		case 5:
			//SDB_IsIdExist();
			break;
		case 6:
			//SDB_DeletEntry();
			break;
		case 7:
			SDB_IsFull();
			break;
	}
}