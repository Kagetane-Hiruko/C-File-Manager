#include "source/filemanager.h"

int main(int argc, char const *argv[])
{
    
	char * text = read_from_file("main.cc");
    
    write_to_file("new.cc", text, "w");
    
	return 0;
}