# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++17
AR = ar
ARFLAGS = rcs

# Files
LIB_NAME = libExpenseReport.a
LIB_SRC = ExpenseReport.cpp
LIB_OBJ = ExpenseReport.o
MAIN_SRC = main.cpp
MAIN_OBJ = main.o
EXTRA_SRC = ExpenseTypes.cpp LunchExpenseHandler.cpp
EXTRA_OBJ = ExpenseTypes.o LunchExpenseHandler.o
TARGET = main.exe

# Default target
all: $(TARGET)

# Build static library
$(LIB_NAME): $(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $^

# Build main object
$(MAIN_OBJ): $(MAIN_SRC) ExpenseReport.h ExpenseTypes.h LunchExpenseHandler.h
	$(CXX) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Build library object
$(LIB_OBJ): $(LIB_SRC) ExpenseReport.h
	$(CXX) $(CXXFLAGS) -c $(LIB_SRC) -o $(LIB_OBJ)

# Build extra objects
ExpenseTypes.o: ExpenseTypes.cpp ExpenseTypes.h
	$(CXX) $(CXXFLAGS) -c ExpenseTypes.cpp -o ExpenseTypes.o

LunchExpenseHandler.o: LunchExpenseHandler.cpp LunchExpenseHandler.h ExpenseTypes.h
	$(CXX) $(CXXFLAGS) -c LunchExpenseHandler.cpp -o LunchExpenseHandler.o

# Build main executable
$(TARGET): $(MAIN_OBJ) $(LIB_NAME) $(EXTRA_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJ) $(EXTRA_OBJ) -L. -lExpenseReport

# Clean
clean:
	del /q $(MAIN_OBJ) $(LIB_OBJ) $(LIB_NAME) $(TARGET) $(EXTRA_OBJ) 2>NUL || exit 0

# Run
run: $(TARGET)
	$(TARGET)

.PHONY: all clean run