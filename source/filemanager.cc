#include "filemanager.h"

#include <stdlib.h>
#include <stdio.h>

char * __garabage_string = (char *) malloc(1);

extern "C" void KAGETANE_HIRUKO_API write_to_file(const char * file, const char * text, const char * mode)
{

	FILE * file_ptr = fopen(file, mode);
	
	if(file_ptr)
	{
		fputs( text, file_ptr);
		
	}
	else
	{
		fprintf(stderr, "Failed to write to file\n");
	}
    fclose(file_ptr);

}

extern "C" char * KAGETANE_HIRUKO_API read_from_file(const char * file)
{
	FILE * file_ptr = fopen(file, "r");
    if(file_ptr == NULL)
    {
        fprintf(stderr, "Failed to read from file!\n");
        return __garabage_string;
    }

    if (fseek(file_ptr, 0, SEEK_END) != 0) { }

	size_t size_of_file = ftell(file_ptr);

	if (fseek(file_ptr, 0, SEEK_SET) != 0) { }

	char * text_from_file = (char *) malloc(size_of_file + 1);
    char character;
    int i = 0;
    while((character = getc(file_ptr)) != EOF)
    {
    	text_from_file[i] = character;
        i++;
    }
    text_from_file[i++] = '\0'; 
    fclose(file_ptr);
    return text_from_file;
}