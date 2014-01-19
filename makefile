all:
	g++ main.cpp room.cpp world_picker.cpp console.cpp log.cpp -lreadline -lm -ldl -llua5.1 -o luarpg
