set -e    # if error, stop the build
g++ src/main.cpp src/term.cpp src/binarySearchDeluxe.cpp src/textBox.cpp -o RayMenu -lc -lraylib -lm -lpthread -ldl -lrt -lX11