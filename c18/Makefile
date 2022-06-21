CXX = g++-12

# prints "all" Warning messages.
CXXFLAGS = -Wall

# This enables some extra warning flags that are not enabled by -Wall.
# CXXFLAGS += -Wextra

# generates additional symbolic debuggging information for use with gdb debugger.
CXXFLAGS += -g

# -std=gnu++20: enable GNU extensions in addition to C++20 features
CXXFLAGS += -std=gnu++20

default: build_drill_part_2 run_drill_part_2

build_drill_part_1:
	$(CXX) $(CXXFLAGS) -o drill_part_1 drill_part_1.cpp

run_drill_part_1:
	./drill_part_1

build_drill_part_2:
	$(CXX) $(CXXFLAGS) -o drill_part_2 drill_part_2.cpp

run_drill_part_2:
	./drill_part_2

build_e1:
	$(CXX) $(CXXFLAGS) -o e1 e1.cpp

run_e1:
	./e1

build_e2:
	$(CXX) $(CXXFLAGS) -o e2 e2.cpp

run_e2:
	./e2

build_e3:
	$(CXX) $(CXXFLAGS) -o e3 e3.cpp

run_e3:
	./e3

build_e4:
	$(CXX) $(CXXFLAGS) -o e4 e4.cpp

run_e4:
	./e4

build_e5:
	$(CXX) $(CXXFLAGS) -o e5 e5.cpp

run_e5:
	./e5

build_e6:
	$(CXX) $(CXXFLAGS) -o e6 e6.cpp

run_e6:
	./e6

build_e7:
	$(CXX) $(CXXFLAGS) -o e7 e7.cpp

run_e7:
	./e7

build_e8:
	$(CXX) $(CXXFLAGS) -o e8 e8.cpp

run_e8:
	./e8

build_e9:
	$(CXX) $(CXXFLAGS) -o e9 e9.cpp

run_e9:
	./e9

build_e10:
	$(CXX) $(CXXFLAGS) -o e10 e10.cpp

run_e10:
	./e10

clean:
	rm -f *.o;
	rm -f *.gch;

# valgrind:
# 	valgrind --leak-check=full \
#          --show-leak-kinds=all \
#          --track-origins=yes \
#          --verbose \
#          --log-file=valgrind-out.txt \
# 	./update_formatting /home/martin/src/cpp_primer
