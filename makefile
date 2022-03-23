all:
	g++ -g main.cpp -o wordcounter
test: all
	./wordcounter 1Nephi.txt