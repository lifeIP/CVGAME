cd ./build;

g++ -c ../src/components/buttons/circle/CircleButton.cpp -I /usr/include/opencv4
g++ -c ../src/components/buttons/circle/CircleAddButton/CircleAddButton.cpp -I /usr/include/opencv4

g++ -c ../src/components/buttons/void/VoidButton.cpp -I /usr/include/opencv4
g++ -c ../src/components/buttons/rect/RectButton.cpp -I /usr/include/opencv4


g++ -c ../src/blocks/empty/EmptyBlock.cpp -I /usr/include/opencv4
g++ -c ../src/main.cpp -I /usr/include/opencv4


g++ main.o RectButton.o EmptyBlock.o VoidButton.o CircleAddButton.o CircleButton.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system `pkg-config opencv4 --cflags --libs`
