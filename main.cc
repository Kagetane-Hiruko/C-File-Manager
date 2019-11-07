#include "source/filemanager.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    
	file_t * myfile = create_file_manager("main.cc", "r");
	
	char buffer[4];

	buffer_read_file(buffer, 4, myfile);
	printf("%c\n", buffer[0]);


    close_file_manager(myfile);

    
	return 0;
}