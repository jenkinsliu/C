#This is the makefile of the C++ project StudentMS
#the standard c++ compiler is Ubuntu linux is g++
all: stu
CC	= g++
TARGET = .
CFLAGS	=	-g
CFLAGC	=	-c

MAINC	=	stu.cpp
STUDENT	=	Student.cpp
OBJ	=	Student.o

INCLUDE	=	-I$(TARGET)
EXEC	=	$(TARGET)/stu

$(EXEC):$(OBJ) $(MAINC)
	$(CC) $(CFLAGS) $(OBJ) $(MAINC) $(INCLUDE) -o $@
	rm -f $(OBJ)
	@echo "<<<<<<<<<<<<$@ is created successfully!<<<<<<<"
$(OBJ): $(STUDENT)
	$(CC) $(CFLAGS) $(CFLAGC) $(STUDENT) -o $@
clean:
	rm -f $(EXEC)
