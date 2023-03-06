FLAGS=-Wall 
INCLUDE_PATH=./include
SOURCE_PATH=./src
OBJECT_PATH=./obj

files = main presenter shader utils view system_state point_mass beam component drawing_visitor spring slider disc

$(files) :; @-mkdir $(OBJECT_PATH) 2> /dev/null; echo compiling $@; g++ -c $(SOURCE_PATH)/$@.cpp -o $(OBJECT_PATH)/$@.o -ldl -lglfw -Wall -pedantic

out: $(files)
	g++ glad.c $(OBJECT_PATH)/*.o -o out -ldl -lglfw -Wall -O3 -pedantic
	

# dependancies
main: presenter shader utils
presenter: view system_state point_mass beam
system_state: component point_mass beam
point_mass: component drawing_visitor 
beam: component drawing_visitor point_mass 
spring: beam
slider: beam
disc: component drawing_visitor
drawing_visitor: component

.PHONY: clean
clean:      ; @-rm -r $(OBJECT_PATH); rm ./out

# out: $(INCLUDE_PATH)/%.hpp $(SOURCE_PATH)/%.cpp $(OBJECT_PATH)/%.o glad.o

# $(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp
# 	g++ $(FLAGS) -c -o $@ $<

