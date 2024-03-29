#include "main.h"
#include "GameWindow.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
{
	GameWindow gameWin;
	int retCode;

	//creating a debug console 
	//TODO: create an actual developer console some day ...
	if (AllocConsole()) {
		std::string s = "I made a console window!\n";
		DWORD n;
		char c;

		WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), s.c_str(), s.size(), &n, 0);
	}

	// Initialize the engine.
	if (!gameWin.InitInstance( hInstance, lpCmdLine, nCmdShow )) return 0;

	// Begin the gameplay process. Will return when app due to exit.
	retCode = gameWin.BeginGame();

	// Shut down the engine, just to be polite, before exiting.
	if ( !gameWin.ShutDown() )  MessageBox( 0, "Failed to shut system down correctly, please check file named 'debug.txt'.\r\n\r\nIf the problem persists, please contact technical support.", "Non-Fatal Error", MB_OK | MB_ICONEXCLAMATION );

	// Return the correct exit code.
	return retCode;
}