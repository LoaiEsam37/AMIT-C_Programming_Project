#include "SDBAPP.h"

void SDB_APP() {
	uint8 choice;
	while (1) {
        printf("============ Student DB Application ============\n");
		printf("1. To add entry, enter 1                        \n");
		printf("2. To get used size in database, enter 2        \n");
		printf("3. To read student data, enter 3                \n");
		printf("4. To get the list of all student IDs, enter 4  \n");
		printf("5. To check is ID is existed, enter 5           \n");
		printf("6. To delete student data, enter 6              \n");
		printf("7. To check is database is full, enter 7        \n");
		printf("8. To exit, enter 0                             \n");
		
		choice = readUInt(": ");
		if (choice == 0) break;
        printf("\n\n\n");
        printf("====================\n");
		SDB_action(choice);
        printf("====================\n");
        printf("\n\n\n");
	}
}

void SDB_action(uint8 choice) {
    switch (choice) {
    case 1: {
        bool created = SDB_AddEntry();
        printf(created ? "Entry created successfully.\n" : "Failed to create entry.\n");
        break;
    }
    case 2: {
        uint8 size = SDB_GetUsedSize();
        printf("Used size: %u\n", size);
        break;
    }
    case 3: {
        uint32 id = readUInt("Enter ID: ");
        bool found = SDB_ReadEntry(id);
        printf("ID %u %s\n", id, found ? "found" : "not found");
        break;
    }
    case 4: {
        uint8 count;
        uint32 list[MAX_DB_SIZE];

        SDB_GetList(&count, list);

        printf("Database contains %u student(s):\n", count);
        for (uint8 i = 0; i < count; i++) {
            printf("ID: %u\n", list[i]);
        }
        break;
    }
    case 5: {
        uint32 id = readUInt("Enter ID: ");
        bool exists = SDB_IsIdExist(id);
        printf("ID %u exists: %s\n", id, exists ? "Yes" : "No");
        break;
    }
    case 6: {
        uint32 id = readUInt("Enter ID to delete: ");
        SDB_DeleteEntry(id);
        printf("ID %u deleted (if it existed).\n", id);
        break;
    }
    case 7: {
        bool full = SDB_IsFull();
        printf("Database is %s\n", full ? "FULL" : "NOT full");
        break;
    }
    default: {
        printf("Invalid choice\n");
        break;
    }
    }
}