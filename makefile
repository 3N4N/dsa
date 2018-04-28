CC=g++
INPUT=ArrayList.cpp
OUTPUT=output

build: $(INPUT)
	$(CC) $(INPUT) -o $(OUTPUT)
