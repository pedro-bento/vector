executable = vector
compiler = gcc
flags = -Wall -std=c11 -O3
files = main.c $(wildcard vector/*.c)

$(executable): $(files)
	$(compiler) $(flags) -o $(executable) $(files)