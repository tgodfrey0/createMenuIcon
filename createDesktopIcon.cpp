//Author: tgodfrey0

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <boost/range/algorithm/remove_if.hpp>

using namespace std;

void execCommand(string command)
{
	cout << "Executing command: \"" + command + "\"" << endl;
	system(command.c_str());
}

int main(int argc, char *argv[])
{

	string paramVal;
	string name;
	string comment;
	string executable;
	string icon;
	string type;
	string genericName;
	string notify;
	string categories;

	for (int i = 1; i < argc; i++)
	{
		string param = argv[i];
		if (i + 1 <= argc - 1)
		{
			paramVal = argv[i + 1];
		}
		else
		{
			paramVal = argv[i];
		}
		if (param == "-h")
		{
			cout << "-h        Display this help dialogue" << endl;
			cout << "-n        Set entry name" << endl;
			cout << "-c        Set entry comment" << endl;
			cout << "-e        Set entry executable path" << endl;
			cout << "-i        Set entry icon" << endl;
			cout << "-g        Set generic name" << endl;
			cout << "-s        Set entry to notify on startup (true/false)" << endl;
			cout << "-f        Set entry categories (end each category with ;)" << endl;
			cout << "Example:" << endl;
			cout << "./createDesktopIcon -n Ghidra -c \"An NSA decomplier\" -e ./ghidraRun -i ./ghidraIcon -t Application -g Decompiler -s false -f \"Utility;TextEditor;Development;\"" << endl;
			return (0);
		}
		else if (param == "-n")
		{
			name = paramVal;
			i++;
			continue;
		}
		else if (param == "-c")
		{
			comment = paramVal;
			i++;
			continue;
		}
		else if (param == "-e")
		{
			executable = paramVal;
			i++;
			continue;
		}
		else if (param == "-i")
		{
			icon = paramVal;
			i++;
			continue;
		}
		else if (param == "-g")
		{
			genericName = paramVal;
			i++;
			continue;
		}
		else if (param == "-s")
		{
			notify = paramVal;
			i++;
			continue;
		}
		else if (param == "-f")
		{
			categories = paramVal;
			i++;
			continue;
		}
		else
		{
			cout << "ERROR >>> Unrecognised parameter " << param << endl;
		}
	}

	string title = name;
	title.erase(boost::remove_if(title, ::isspace), title.end());
	string extension = ".desktop";
	string path = "/usr/share/applications/";
	string fullPath = path + title + extension;

	string command0 = ("sudo touch " + fullPath);
	string command1 = ("sudo echo \"[Desktop Entry]\" >> " + fullPath);
	string command2 = ("sudo echo \"Name=" + name + "\" >> " + fullPath);
	string command3 = ("sudo echo \"Comment=" + comment + "\" >> " + fullPath);
	string command4 = ("sudo echo \"GenericName=" + genericName + "\" >> " + fullPath);
	string command5 = ("sudo echo \"Exec=" + executable + "\" >> " + fullPath);
	string command6 = ("sudo echo \"Icon=" + icon + "\" >> " + fullPath);
	string command7 = ("sudo echo \"Type=Application\" >> " + fullPath);
	string command8 = ("sudo echo \"StartupNotify=" + notify + "\" >> " + fullPath);
	string command9 = ("sudo echo \"Categories=" + categories + "\" >> " + fullPath);
	string command10 = ("sudo echo \"MimeType=text/plain;inode/directory;\" >> " + fullPath);

	execCommand(command0);
	execCommand(command1);
	execCommand(command2);
	execCommand(command3);
	execCommand(command4);
	execCommand(command5);
	execCommand(command6);
	execCommand(command7);
	execCommand(command8);
	execCommand(command9);
	execCommand(command10);

	return (0);
}
