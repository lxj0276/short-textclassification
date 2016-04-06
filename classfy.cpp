#include <Python.h>
#include "model.h"
#include "../wordseg/seg.h"
#include "../commom/func.h"
stc::Model model;
std::string Categorizatetopic(const char* s){
	std::string str = s;
	return model.TopicClassfy(str);
}

std::string Categorizategenre(const char* s){
	std::string str = s;
	return model.GenreClassfy(str);
}
//python °ü×°
static  PyObject* topic_classfy(PyObject* self, PyObject* args){
	const char* str;
	std::string result;
	if (! PyArg_ParseTuple(args, "s", &str)) 
		return NULL;
	result = Categorizatetopic(str);
	return Py_BuildValue("s", result.c_str());
}
static  PyObject* genre_classfy(PyObject* self, PyObject* args){
	const char* str;
	std::string result;
	if (! PyArg_ParseTuple(args, "s", &str)) 
		return NULL;
	result = Categorizategenre(str);
	return Py_BuildValue("s", result.c_str());
}


static PyMethodDef textclassfyMethods[] ={
	{"Categorizatetopic", topic_classfy, METH_VARARGS, "textclassfy!"}, 
	{"Categorizategenre", genre_classfy, METH_VARARGS, "textclassfy!"}, 
	{NULL, NULL}
};

extern "C"   {
	void inittextclassfy(){
		PyObject* m;
		m = Py_InitModule("textclassfy", textclassfyMethods);
	}
};

