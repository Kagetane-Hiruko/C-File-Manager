# C-File-Manager
Simple C/C++ utility library for reading and writinig to files.

## Functions

* create_file_manager
```cpp

// Function for creating file manager
// Params: path to file, mode
	
file_t * file_manager = create_file_manager("filepath", "r");


```
* read_from_file
```cpp

// Function for reading text from file
// Params: file manager
	
char * text = read_from_file(file_manager);


```
* write_to_file
```cpp

// Function for writing text to file
// Params: file manager, some text
	
write_to_file(file_manager, "some text to write");


```
* close_file_manager
```cpp

// Function for destroying file manager
// Params: file manager
	
close_file_manager(file_manager);


```
* set_file_stream_position
```cpp

// Function for setting file stream position
// Params: file manager, position
	
set_file_stream_position(file_manager, 0);


```
* buffer_read_file
```cpp

// This functions is used for reading blocks of file.
// Params: char buffer, size, file manger

char buffer[4];
buffer_read_file(buffer, 4, file_manager);


```