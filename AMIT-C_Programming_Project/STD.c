#include <stdio.h>

unsigned int readUInt(const char* prompt) {
	int temp;
	while (1) {
		printf("%s", prompt);
		if (scanf_s("%d", &temp) == 1 && temp >= 0) {
			return (unsigned int)temp;
		}
		else {
			printf("Invalid input! Enter a non-negative integer.\n");
		}
	}
};

int readInt(const char* prompt) {
    int temp;
    while (1) {
        printf("%s", prompt);
        if (scanf_s("%d", &temp) == 1) {
            break;
        }
        else {
            printf("Invalid input! Try again.\n");
        }
    }
    return temp;
}
