#include <stdio.h>

int main(void) {
	unsigned long ccn;
	printf("Number: ");
	scanf("%lu", &ccn);

	//split the credit card number into an array by repeated division by 10
	int ccArr[16];
	int i = 15;
	while (ccn > 0) {
		int mod = ccn % 10;
		ccArr[i] = mod;
		ccn = ccn / 10;
		i--;
	}
	int len = 16 - (i + 1);

	//now lets define card types and determine what we have
	enum ccType {INVALID = 0, VISA = 1, MASTERCARD = 2, AMEX = 3};

	int type = INVALID;
	
	//mastercard: 16 digits, starting with 51,52,53,54,55
	if (len == 16 && ccArr[0] == 5 && (ccArr[1] > 0 && ccArr[1] < 6)) {
		type = MASTERCARD;
	//visa: either 13 OR 16 digits, starting with 4
	} else if ((len == 16 && ccArr[0] == 4) || (len == 13 && ccArr[3] == 4)) {
		type = VISA;
	//amex: 15 digits, starting with 32 or 37
	} else if (len == 15 && ccArr[1] == 3 && (ccArr[2] == 4 || ccArr[2] == 7)) {
		type = AMEX;
	}

	//add every other digit *2
	int j = 15;
	int checkSum = 0;
	while (j >= (16 - len)) {
		if (j % 2 == 0) {
			int prod = 2 * ccArr[j];
			if (prod > 9) {
				checkSum += prod % 10;
				checkSum += prod / 10;
			} else {
				checkSum += prod;
			}
		} else {
			checkSum += ccArr[j];
		}
		j--;
	}
	if (checkSum % 10 != 0) {
		type = INVALID;
	}

	switch (type) {
		case 0: 
			printf("INVALID\n");
			break;
		case 1:
			printf("VISA\n");
			break;
		case 2:
			printf("MASTERCARD\n");
			break;
		case 3:
			printf("AMEX\n");
			break;
	}

	//printf("length: %d, [0]: %d, [1]: %d, type: %d", len, ccArr[0], ccArr[1], type);
}
