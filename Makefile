build:
	g++ -Wall -std=c++17 -Iinclude -I/opt/homebrew/include -L/opt/homebrew/lib -L/opt/homebrew/opt/ncurses/lib -I/opt/homebrew/opt/ncurses/include  -lncurses ./src/*.cpp -o main -g

build-debug:
	g++ -Wall -std=c++17 -Iinclude -I/opt/homebrew/include -L/opt/homebrew/lib -L/opt/homebrew/opt/ncurses/lib -I/opt/homebrew/opt/ncurses/include  -lncurses ./src/*.cpp -o main -Og -ggdb3 -fsanitize=address

run:
	./main

clean:
	rm main

debug:
	lldb ./main