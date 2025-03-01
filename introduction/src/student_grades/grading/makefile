# calling build needs to call 'main' first, which builds the object files
build: main
	rm median.o student_info.o main.o

# linking object files into final executable
main: median.o student_info.o main.o
	g++ median.o student_info.o main.o -o grading

#
# Object Files
#
median.o:
	g++ -c median.cpp 

student_info.o:
	g++ -c student_info.cpp 

main.o:
	g++ -c main.cpp

# remove built file
clean:
	rm grading