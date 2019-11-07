#include "filemanager.h"

#include <stdlib.h>
#include <stdio.h>

char * __garabage_string = (char *) malloc(1);

extern "C" void KAGETANE_HIRUKO_API write_to_file(file_t * file, const char * text)
{

	FILE * file_ptr = (FILE*) DREF(file).file_stream;
	
	if(file_ptr)
	{
		fputs( text, file_ptr);
	}
	else
	{
		fprintf(stderr, "Failed to write to file\n");
	}
}

extern "C" char * KAGETANE_HIRUKO_API read_from_file(file_t * file)
{
    FILE * file_ptr = (FILE*) DREF(file).file_stream;

    if(file_ptr == NULL)
    {
        fprintf(stderr, "Failed to read from file!\n");
        return __garabage_string;
    }


	size_t size_of_file = DREF(file).size;

	char * text_from_file = (char *) malloc(size_of_file + 1);
    char character;
    int i = 0;
    while((character = getc(file_ptr)) != EOF)
    {
    	text_from_file[i] = character;
        i++;
    }
    text_from_file[i++] = '\0'; 
    return text_from_file;
}

extern "C" file_t * KAGETANE_HIRUKO_API create_file_manager(const char * file_path, const char * mode)
{
    file_t * new_file_manager = (file_t *) malloc(sizeof(file_t));

    DREF(new_file_manager).file_path = file_path;
    DREF(new_file_manager).file_stream = fopen(file_path, mode);

    if (fseek((FILE*) DREF(new_file_manager).file_stream, 0, SEEK_END) != 0) { }

    DREF(new_file_manager).size = ftell((FILE*) DREF(new_file_manager).file_stream);

    if (fseek((FILE*) DREF(new_file_manager).file_stream, 0, SEEK_SET) != 0) { }

    return new_file_manager;
}


extern "C" void   KAGETANE_HIRUKO_API close_file_manager(file_t * file)
{
    fclose((FILE*) DREF(file).file_stream);
    free(file);
}

extern "C" void   KAGETANE_HIRUKO_API set_file_stream_position(file_t * file, unsigned int position)
{
    fseek((FILE*) DREF(file).file_stream, 0, SEEK_SET);
}

extern "C" void   KAGETANE_HIRUKO_API buffer_read_file(char * buffer, unsigned int size, file_t * file)
{
    fread(buffer, 1, size, (FILE*) DREF(file).file_stream);
}