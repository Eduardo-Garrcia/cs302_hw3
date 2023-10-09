postfix: postfix.o
	g++ postfix.o -o postfix

postfix.o: driver.cpp arrayStack.h stack.h node.h
	g++ -c driver.cpp

clean:
	rm *.o postfix