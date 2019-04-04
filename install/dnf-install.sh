echo ""
echo "Installing G++"
sudo dnf install g++
echo ""
echo "G++ has been installed"
echo ""
echo "Compiling main file"
g++ ./createDesktopIcon.cpp -o ./createDesktopIcon
echo ""
echo "File has been compiled"
chmod +u ./createDesktopIcon
sudo mv ./createDesktopIcon /usr/bin