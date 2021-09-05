filename = imgrotate.cpp
outfile = imgrotate
compileopts = $(shell Magick++-config --cxxflags --cppflags --ldflags --libs) -std=c++17 -pipe -Og -Wall -g3

$(outfile): $(filename)
	g++ $(compileopts) $(filename) -o $(outfile)
