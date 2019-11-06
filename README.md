# C-File-Manager
Simple C/C++ utility library for reading and writinig to files.

## Functions

* read_from_file
```cpp

// Function for reading text from file
// Params: path to file
	
char * text = read_from_file("some_file_path");


```
* write_to_file
```cpp

// Function writing text to file
// Params: path to file, some text, mode [ a | w ]
	
write_to_file("some_file_path", "some text to write", "w");


```