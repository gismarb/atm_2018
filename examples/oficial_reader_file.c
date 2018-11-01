/*
 * Gismar (31/10/2018):
 * 
 * DONE: The program can already read a file, and make the exchange of 
 * the contents read from the file to an array, where the data can be filtered.
 * 
 * TODO: Necessary implement (Function) filters (values): Only remove values, 
 * and later convert to integer type (int).
 * 
 * TODO: Necessary to implement (Functions) the actions to generate 
 * the general averages (as requested).
 * 
 * TODO: Necessary to implement (Functions or not) the conditionals 
 * to receive the command line parameters: input options to generate the requested outputs.
 * 
 * NOTE: The exported txt and csv formats have the same formatting, so the code 
 * that will read and filter the values ​​of the two types may be the same.
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> /* Enable use of the strdup */
 
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *fp; /* Pointer (File type) */
    char buffer[BUFFER_SIZE]; /* Swap Area to receive String generated by File */
    char *read_data[BUFFER_SIZE]; /* Array that allocates data from the "buffer" */
    int read_size = 0; /* Buffer size read */
    int line = 0; /* line counter */
    int index = 0; /* aux */

    /* Variables, if you want to work on reading character, the character of array (optional) */
    char filter[BUFFER_SIZE][BUFFER_SIZE];
    char ch;
    int column = 0;
    int size_str = 0;
    int count = 0;
 
    /* Condition: two or more parameter are required */
    if (argc != 2)
    {
    	fprintf(stderr, "\n\tDo like this: %s <path/file>\n\n", argv[0]);
    	return 1;
    }
 
    /* Condition: if file or path exists, will be open in read-mode "r" */
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
    	perror("\n\t<path/file>");
		printf("\n");
		return 1;
    }
    
    /* Loop: getting line by line, and inserting into a array and after copied to another array */
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        read_size = strlen(buffer);
        /* "strdup" from <strings.h> doing copy of pointer to pointer */
        read_data[index] = strdup(buffer);
        index++;
        line++;
    }

    
    /* Output options on the screen to validate the process of reading arrays */
 
    system("clear");
    /* 1 - Printing content allocated in the Array of Strings (String by String) */
    for(index = 0; index < line; index++)
    {
        printf("%d %s", index, read_data[index]);
        
        if (index == (line -1))
            printf("\n");
        
    }

    getchar();

    system("clear");
    /* 2 - Printing content allocated in the Array of Strings (char by char) */
    for(index = 0; index < line; index++)
    {
        size_str = strlen(read_data[index]);
        printf("%d %d ", count, size_str);
        
        for(column = 0; column < size_str; column++)
        {
            ch = read_data[index][column];
            filter[index][column] = ch;
            printf("%c", filter[index][column]);       
        }
        count++;
        if (index == (line -1))
            printf("\n");
    }

    fclose(fp);
    return 0;
}