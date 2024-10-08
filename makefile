# Compiler
CC = gcc

# Directories
INCLUDE_DIR = includes
SRC_DIR = src
BUILD_DIR = build

# Source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/chats.c $(SRC_DIR)/messages.c

# Output binary
OUTPUT = $(BUILD_DIR)/chat_box

# Compiler flags
CFLAGS = -I$(INCLUDE_DIR)

# Target to build the executable
all: $(OUTPUT) run

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	
# Link object files to create the final executable
$(OUTPUT): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(OUTPUT)

# Run the executable after building
run: $(OUTPUT)
	@echo "Running the program..."
	@$(OUTPUT)

# Clean up build files
clean:
	rm -f $(OUTPUT)

# Phony targets to avoid conflicts with file names
.PHONY: all clean run