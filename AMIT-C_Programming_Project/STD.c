#include "STD.h"

uint32 readUInt(const int8* prompt) {
    int32 temp;
	while (1) {
		printf("%s", prompt);
		if (scanf_s("%d", &temp) == 1 && temp >= 0) {
			return (uint32)temp;
		}
		else {
			printf("Invalid input! Enter a non-negative integer.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
		}
	}
};

int32 readInt(const int8* prompt) {
    int32 temp;
    while (1) {
        printf("%s", prompt);
        if (scanf_s("%d", &temp) == 1) {
            return temp;
        }
        else {
            printf("Invalid input! Try again.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
    return temp;
}