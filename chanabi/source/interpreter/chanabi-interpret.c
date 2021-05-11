
#include <stdio.h>
#include <stdlib.h>
#include <chanabi.h>
#include "../common/log.h"
#include "../common/common.h"
#include "../common/types.h"

#define STRING_ALLOC_START_SIZE   0x100

int main(int argc, char *argv[]) {
	int error = ERR_CRITICAL;

	FILE *sourceFile;
	// This string has no \0.
	char *fileText = NULL;
	size_t fileText_length;
	size_t fileText_allocLength;
	char character;
	hanabiState_t hanabiState;
	char *arguments = &argv[2];
	size_t arguments_length = argc - 2;
	
	error = chanabi_create(&hanabiState);
	if (error) {
		critical_error("Could not create Hanabi instance.", "");
		error = ERR_CRITICAL;
		goto cleanup;
	}

	// Open file.
	sourceFile = fopen(argv[1], "r");
	if (sourceFile == NULL) {
		critical_error("Could not open file \"%s\".", argv[1]);
		error = ERR_CRITICAL;
		goto cleanup;
	}
	
	fileText_length = 0;
	fileText_allocLength = STRING_ALLOC_START_SIZE;
	fileText = malloc(fileText_allocLength * sizeof(char));
	if (fileText == NULL) {
		critical_error("Out of memory.", "");
		error = ERR_OUTOFMEMORY;
		goto cleanup;
	}
	
	// Read entire file into string.
	while ((character = getc(sourceFile)) != EOF) {
		
		if (fileText_length == fileText_allocLength) {
			fileText_allocLength *= 2;
			fileText = realloc(fileText, fileText_allocLength * sizeof(char));
			if (fileText == NULL) {
				critical_error("Out of memory.", "");
				safeFree(fileText);
				error = ERR_OUTOFMEMORY;
				goto cleanup;
			}
		}
		
		fileText[fileText_length] = character;
		fileText_length++;
	}
	
	// Allow Hanabi to analyze the string.
	error = chanabi_loadString(&hanabiState, fileText, fileText_length);
	safeFree(fileText);
	if (error) {
		error("Could not load string into Hanabi. Returned %i", error);
		error = ERR_CRITICAL;
		goto cleanup;
	}
	
	fileText_allocLength = 0;
	fileText_length = 0;
	
	// Execute!
	error = chanabi_call(&hanabiState, "main", arguments, arguments_length);
	if (error) {
		error("Hanabi returned %i", error);
		error = ERR_CRITICAL;
		goto cleanup;
	}

	error = ERR_OK;
	cleanup:
	
	return error;
}
