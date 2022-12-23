CC = g++ -std=c++17

EXECUTABLE = run.exe

SOURCES = main.cpp \
		map\cell.cpp \
		map\field.cpp \
		graphics\field_view.cpp \
		graphics\cell_view.cpp \
		entities\entity.cpp \
		entities\player.cpp \
		core\controller.cpp \
		core\mediator.cpp \
		core\statemediator.cpp \
		core\controls\commandreader.cpp \
		core\controls\controls_storage.cpp \
		events\event.cpp \
		events\playerEvents\eventHeal.cpp \
		events\playerEvents\eventHurt.cpp \
		events\playerEvents\eventGetWeight.cpp \
		events\playerEvents\eventLoseWeight.cpp \
		events\stateEvents\eventVictory.cpp \
		events\stateEvents\eventDefeat.cpp \
		events\mapEvents\eventTrap.cpp \
		log\console_logger.cpp \
		log\file_logger.cpp \
		log\logger_pool.cpp \
		log\logger.cpp \
		log\message.cpp \
		log\observable.cpp \
		log\messages\event_messages.cpp \
		log\messages\player_messages.cpp \
		log\messages\game_state_messages.cpp \
		map\save\file_map_saver.cpp \
		utils\string_utilities.cpp \
		map\save\save_file_loader.cpp \
		events\test_event_creator.cpp \
		exceptions\loading_map_exception.cpp \
		exceptions\slon_exception.cpp
		

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	del $(OBJECTS)
