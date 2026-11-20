#Makefile Project My Radar

src	=	$(wildcard src/*.cpp main.cpp)

executable	=	my_radar

comp	=	clang++

flags	=	--std=c++17	-lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o

obj	=	$(src:.cpp=.o)

all:	$(executable)

$(executable):
	            $(comp) $(src) $(flags) $(executable)

clean:
	rm -f $(obj)
	rm -f $(executable)

fclean:	clean

re: fclean all