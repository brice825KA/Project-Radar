#Makefile Project My Radar

src	=	$(wildcard src/*.cpp main.cpp)

exec	=	my_radar

comp	=	clang++

flags	=	--std=c++17	-lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o

obj	=	$(src:.cpp=.o)

all:	$(exec)

$(exec):
	    $(comp) $(src) $(flags) $(exec)

clean:
	rm -f $(obj)
	rm -f $(exec)

fclean:	clean

re: fclean all