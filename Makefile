
test_xmlcpp: xmlcpp.h test_xmlcpp.cpp
	g++ -Wfatal-errors `xml2-config --cflags --libs` test_xmlcpp.cpp
	./a.out

xmlcpp.h: make_cpp_wrapper.py
	./make_cpp_wrapper.py > xmlcpp.h


