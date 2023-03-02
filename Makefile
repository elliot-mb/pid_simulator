FLAGS=-Wall 
INCLUDE_PATH=./include
SOURCE_PATH=./src
OBJECT_PATH=./obj

.PHONY: all clean

all: out 

clean:
	rm

out: $(INCLUDE_PATH)/%.hpp $(SOURCE_PATH)/%.cpp $(OBJECT_PATH)/%.o glad.o

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp
	g++ $(FLAGS) -c -o $@ $<

