all : generate build insert

insert : $(wildcard build/*.o)
	scripts/insert

build : $(wildcard src/*.h) $(wildcard src/*.c) $(wildcard src/*.s)
	scripts/build

generate : $(wildcard src/*.yml)
	scripts/generate
