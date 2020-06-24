#include <stdio.h>

//return 0 if not a letter, 1 for lower case, 2 for upper case
int checkChar(int ci) {
	if (ci >= (int)'a' && ci <= (int)'z') {
		return 1;
	} else if (ci >= (int)'A' && ci <= (int)'Z') {
		return 2;
	}
	return 0;
}


int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Needs a single, numeric argument\n");
		return 1;
	}

	char* key = argv[1];

	//calculate the ascii offset between lower and upper case letters
	int caseOffset = (int)'a' - (int)'A';
	
	//check that there are 26 elements in the key (null element (0) means end of string)
	//then check that all of the elements are either capital or lower case letters
	//if they are lower case letters, convert them to upper case letters
	for (int i = 0; i < 26; i++) {
		int ci = (int)key[i];
		if (ci == 0) {
			printf("needs 26 letters for the key!\n");
			return 1;
		}

		int letterType = checkChar(ci);
		if (letterType == 0) {
			printf("Error!  Need 26 letter charecters for key!\n");
			return 1;
		} else if (letterType == 1) {
			key[i] = key[i] - caseOffset;
		}
	}

	//prompt for user input
	char pt[100];
	printf("plaintext: ");
	//need to use a regex to match spaces as well - basically reads in everythind except newlines
	scanf("%[^\n]%*c", pt);
	
	//iterate through the plaintext converting letters where they appear
	char ct[100];
	char c;
	int j = 0;

	do {	
		c = pt[j];
		int typeC = checkChar( (int)c );
		switch (typeC) {
			//not a letter - pass it as is
			case 0:
				ct[j] = c;
				break;
			//lowercase letter
			case 1:
				//so what we need to do it covert the lower case letter to uppercase using the offset
				//and then 0 index it (since key[0] is A and ascii A is 65
				ct[j] = (char)(key[(int)c - caseOffset - (int)'A'] + caseOffset);
				break;
			//upper case letter (need to convert back and forth
			case 2:
				//just need to change the letter offset to 0 (since key[0] is A but ascii A is 65)
				ct[j] = key[(int)c - (int)'A'];
				break;
		}
		j++;
	} while (c != '\0'); 
		
	printf("ciphertext: %s\n", ct);
}  
