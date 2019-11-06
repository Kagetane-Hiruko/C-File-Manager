#ifdef _WIN32

	#ifdef BUILD_MODE

		#define KAGETANE_HIRUKO_API __declspec(dllexport)

	#else

		#define KAGETANE_HIRUKO_API __declspec(dllimport)

	#endif

#endif

#define dref(pointer) (*pointer)

/**

	Function: write_to_file
	Return type: void
	Params: const char *, const char *, const char *

	This function is used for writing text to file.

**/
extern "C" void KAGETANE_HIRUKO_API write_to_file(const char * file, const char * text, const char * mode);

/**

	Function: read_from_file
	Return types: cons char *
	Params: const char *

	This function will read text from file and return it.

**/
extern "C" char * KAGETANE_HIRUKO_API read_from_file(const char * file);