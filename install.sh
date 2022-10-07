
OSTYPE=$(uname -m)

if [[ "$OSTYPE" == "x86_64" ]]; then
        brew update
        brew install glfw
elif [[ "$OSTYPE" == "linux-gnu" ]]; then
        sudo apt update
        sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
elif [[ "$OSTYPE" == "arch" ]]; then
	sudo pacman -S glfw-x11
elif [[ "$OSTYPE" == "aarch64" ]]; then
	sudo pacman -S glfw-x11
fi
