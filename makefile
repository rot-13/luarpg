all:
	clang++ styled_text/*.cpp main.cpp actions/room_action_handler.cpp game_engine.cpp room.cpp world_picker.cpp console.cpp log.cpp -std=c++11 -lreadline -lm -ldl -llua5.1 -o luarpg
