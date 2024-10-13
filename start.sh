g++ -c ./src/blocks/empty/EmptyBlock.cpp -I /usr/include/opencv4
g++ -c ./src/blocks/inputs/CameraInput/CameraInput.cpp -I /usr/include/opencv4
g++ -c ./src/main.cpp -I /usr/include/opencv4

g++ main.o EmptyBlock.o CameraInput.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system `pkg-config opencv4 --cflags --libs`