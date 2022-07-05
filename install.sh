
OS=$(uname)

if [[ "$OS" == "Darwin" ]]; then
        brew update
        brew install glfw
elif [[ "$OS" == "Linux" ]]; then
        sudo apt update
        sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
fi     