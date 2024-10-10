# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -I/opt/homebrew/opt/sfml/include -std=c++17

# Linker flags
LDFLAGS = -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = BananaPeel.cpp Bomb.cpp Burger.cpp Cheese.cpp FallingObjects.cpp \
       FallingObjectSpawnTest.cpp FallingObjectTest.cpp FoodItem.cpp Game.cpp \
       GameMode.cpp Hazards.cpp HazardsSpawnTest.cpp IntroductionMenu.cpp \
       Lettuce.cpp main.cpp maintest.cpp Onion.cpp Patty.cpp PauseMenu.cpp \
       Player.cpp PlayerTest.cpp PoisonBottle.cpp Score.cpp SettingsMenu.cpp \
       Sock.cpp Tomato.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = game

# Rule to link the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(EXEC)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)
