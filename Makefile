CC = g++

EXECUTABLE = run.exe

SOURCES = main.cpp \
		map\cell.cpp \
		map\field.cpp \
		graphics\field_view.cpp \
		graphics\cell_view.cpp \
		entities\entity.cpp \
		entities\player.cpp \
		core\commandreader.cpp \
		core\controller.cpp \
		core\mediator.cpp \
		core\statemediator.cpp \
		events\event.cpp \
		events\playerEvents\eventHeal.cpp \
		events\playerEvents\eventHurt.cpp \
		events\stateEvents\eventVictory.cpp \
		events\stateEvents\eventDefeat.cpp


OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	del $(OBJECTS)
