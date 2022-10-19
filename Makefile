CC = g++

EXECUTABLE = run

SOURCES = main.cpp \
		map/cell.cpp \
		map/field.cpp \
		graphics/field_view.cpp \
		graphics/cell_view.cpp \
		entities/entity.cpp \
		entities/player.cpp \
		core/commandreader.cpp \
		core/controller.cpp \
		core/mediator.cpp \
		events/event.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	rm $(OBJECTS)
