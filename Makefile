COMPILER = g++
CFLAGS   = -g -Wall -O2 -std=c++14
LDFLAGS  =
LIBS     =
INCLUDE  = -I./include
TARGET   = ./bin/trump
OBJDIR   = ./source/obj
SOURCES  = $(wildcard source/*.cpp)
OBJECTS  = $(subst ./source/obj/source, ./source/obj, $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o)))

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: source/%.cpp
	@[ -d $(OBJDIR) ]
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

exec:
	@bin/trump

clean:
	rm -f $(OBJECTS) $(TARGET)