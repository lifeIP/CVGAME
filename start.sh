g++ -c ./src/blocks/empty/EmptyBlock.cpp -I /usr/include/opencv4
g++ -c ./src/components/buttons/void/VoidButton.cpp -I /usr/include/opencv4
g++ -c ./src/components/buttons/circle/CircleAddButton.cpp -I /usr/include/opencv4
g++ -c ./src/main.cpp -I /usr/include/opencv4

g++ main.o EmptyBlock.o VoidButton.o CircleAddButton.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system `pkg-config opencv4 --cflags --libs`