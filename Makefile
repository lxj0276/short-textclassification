all:
	g++ -fPIC -o textclassfy.so classfy.cpp ../categorization/textcategorization.cpp ./model.cpp ../textanalysis/textanalysis.cpp ../wordseg/symbol.cpp ../wordseg/seg.cpp ../wordseg/hmm.cpp ../wordseg/tree.cpp ../commom/func.cpp ../commom/func.h -shared -I /home/seanxywang/app/include/python2.7/ -I /home/seanxywang/app/lib/python2.7/config/ -L /home/seanxywang/app/lib/python2.7/config/
	g++ -o textclassfy textclassfy.cpp ../categorization/textcategorization.cpp ./model.cpp ../textanalysis/textanalysis.cpp ../wordseg/symbol.cpp ../wordseg/seg.cpp ../wordseg/hmm.cpp ../wordseg/tree.cpp ../commom/func.cpp ../commom/func.h 
clean:
	$(RM) -rf textclassfy textclassfy.so
