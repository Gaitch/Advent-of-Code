#include <stdio.h>

#define LOWEST 48 // 0
#define HIGHEST 57 // 9


int main()
{
	// open File
	FILE *filePointer = fopen("inputData.txt", "r");
	int fileSize = sizeof *filePointer;
	char data[fileSize];
	printf("Size of File: %d Bytes\n", fileSize);
	
	char first = 'x';
	char last = 'x';
	char current = 'x';
	int sum = 0;
	int index = 0;

	// read line by line and store each time in data
	while(fgets(data, fileSize, filePointer))
	{
		while(data[index] !='\0')
		{
			current = data[index];
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
			index++;
		}
		printf("%d\n", sum);
		index = 0;
		sum += 10*((int)first-LOWEST) + ((int)last-LOWEST);
		first = 'x';
		last = 'x';
	}
	fclose(filePointer);
	printf("%d \n", sum);
	return 0;
}


