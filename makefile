CC = g++
CFLAGS = -std=c++11
TARGET = submission

all: $(TARGET)

$(TARGET): TreeSort.cpp
	$(CC) $(CFLAGS) -o $(TARGET) TreeSort.cpp

clean:
	rm -f $(TARGET)
