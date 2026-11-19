#Makefile Project My Radar

src	=	$(wildcard src/*.cpp main.cpp)

executable	=	my_radar

comp	=	clang++

flags	=	--std=c++17	-o

obj	=	$(src:.cpp=.o)

all:	$(executable)

$(executable):
	            $(comp) $(src) $(flags) $(executable)

clean:
	rm -f $(obj)
	rm -f $(executable)

fclean:	clean

re: fclean all