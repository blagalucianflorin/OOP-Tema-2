CC         = g++
CFLAGS     = -c -Wall -Wextra
SOURCES    = $(wildcard *.cpp) $(wildcard sources/*.cpp) $(wildcard sources/exceptions/*.cpp)
EXECUTABLE = oop-tema-2
OBJECTS    = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		@ echo "\033[32;1mCreating executable:\033[0m\t$(EXECUTABLE)"
			@ $(CC) $(OBJECTS) -o $@

%.o: %.cpp
		@ $(CC) $(CFLAGS) -c -o $@ $<
			@ echo "\033[32;1mCompiling:\033[0m\t$<"

clean:
		@ echo "\033[32;1mCleaning object files\033[0m"
			@ rm -r sources/*o *o

clean_all:
		@ echo "\033[32;1mCleaning object files and executable\033[0m"
			@ rm -r sources/*o *o $(EXECUTABLE)

