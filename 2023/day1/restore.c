#include <stdio.h>

#define LOWEST 48 // 0
#define HIGHEST 57 // 9


int main()
{
	// open File
	FILE *filePointer = fopen("inputData.txt", "r");
	int fileSize = sizeof *filePointer;
	printf("Size of File: %d Bytes\n", fileSize);

	// read File
	char data[fileSize];
	while(fgets(data, fileSize, filePointer))
	{
		printf("%s", data);
	}
	fclose(filePointer);
	printf("Data: %s\n", data);

	// read file

	// store data
	char testdata[] = "1abc2\npqr3stu8vwx\na1b2c3d4e5f\ntreb7uchet\n";

	char first = 'x';
	char last = 'x';
	char current = 'x';
	int sum = 0;
	// loop through array
	for(int i = 0; i < sizeof testdata; i++)
	{
		current = testdata[i];

		// before each linebreak find first and last value
		// when line break accourse calcuete sum and reset first and last
		if(current != '\n')
		{
			
			if(current >= LOWEST && current <= HIGHEST)
			{
				if(first == 'x')
				{
					first = current;
				}
				else
				{
					last = current;
				}
			}
			if(last == 'x')
			{
				last = first;
			}
		}
		else
		{
			printf("%c%c\n", first, last);
			sum += 10*((int)first-LOWEST) + ((int)last-LOWEST);
			first = 'x';
			last = 'x';
		}
	}
	printf("%d \n", sum);
	return 0;
}
