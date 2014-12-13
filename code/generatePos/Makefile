CXXFLAGS= -std=c++11
CPP_FILES := $(wildcard *.cpp)
H_FILES := $(wildcard *.h)

all: clean generator

generator:
	g++ -o generator $(CPP_FILES) $(H_FILES) $(CXXFLAGS)

clean:
	@echo "cleaning..."
	@rm -f generator `ls|grep posServo` `ls|grep \~`
	@echo "Done"

