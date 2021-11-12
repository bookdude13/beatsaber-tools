CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/bs-tools

SRCEXT := cpp
OBJEXT := o
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
CFLAGS := -g -Wall
INCLUDE := -I include

# Link .o files into target
# $^ is all prerequisites
$(TARGET): $(OBJECTS)
	@echo " Linking..."
	$(CC) $^ -o $(TARGET)

# Compile .cpp into .o
# $@ is the target, $< is first prerequisite
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	@echo " Cleaning..."
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"
	$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
