echo ""
echo "Installing G++"
sudo pacman -S g++
echo ""
echo "G++ has been installed"
echo ""
echo "Compiling main file"
g++ ./createDesktopIcon.cpp -o ./createDesktopIcon
echo ""
echo "File has been compiled"
chmod +u ./createDesktopIcon
sudo mv ./createDesktopIcon /usr/bins