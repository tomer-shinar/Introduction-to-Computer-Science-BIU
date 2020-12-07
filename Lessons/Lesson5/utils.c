#include "utils.h"
#include <stdio.h>
#include <Windows.h>

void printWithColor(char* string, char color_char)
{
	int color;
	switch (color_char) {
			default:
		case 'g':
			color = FOREGROUND_GREEN;
			break;
		case 'b':
			color = FOREGROUND_BLUE;
			break;
		case 'r':
			color = FOREGROUND_RED;
			break;
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	/* Save current attributes */
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	const WORD savedAttributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, color);
	printf("%s", string);

	/* Restore original attributes */
	SetConsoleTextAttribute(hConsole, savedAttributes);
}
