# Create Menu Icon

A simple yet effective C++ script to make a .desktop icon for any file to appear in the Linux menu

## Install
To install and compile the C++ script run the bash install file as root/sudo

Run the install file with the prefix of the package manager of your OS

## Note
The script must be run as root or sudo

###### Syntax:
-h        Display this help dialogue
-n        Set entry name 
-c        Set entry comment 
-e        Set entry executable path 
-i        Set entry icon 
-g        Set generic name 
-s        Set entry to notify on startup (true/false) 
-f        Set entry categories (end each category with ;) 

###### Example: 
sudo ./createDesktopIcon -n Ghidra -c \"An NSA decomplier\" -e ./ghidraRun -i ./ghidraIcon -t Application -g Decompiler -s false -f \"Utility;TextEditor;Development;\" 
