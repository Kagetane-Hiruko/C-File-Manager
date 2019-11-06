#include "source/filemanager.h"
int main(int argc, char const *argv[])
{


    
	char * text = read_from_file("C:\\Users\\Kagetane Hiruko\\Desktop\\CBGE\\Game Engine\\src\\KH\\Graphics\\2d\\ShapeBuffers.cpp");
    
    write_to_file("new.cc", text, "w");
    
	return 0;
}