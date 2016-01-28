#include <Python.h>
#include "model.h"
#include "../wordseg/seg.h"
#include "../commom/func.h"
stc::Model model;
seg::Wordseg mseg;
std::string Categorizatetopic(const char* s){
	std::string str = s;
	std::string strseg = mseg.Segement(str);
	return model.TopicClassfy(strseg);
}

std::string Categorizategenre(const char* s){
	std::string str = s;
	std::string strseg = mseg.Segement(str);
	return model.GenreClassfy(strseg);
}
//python 包装
static  PyObject* topic_classfy(PyObject* self, PyObject* args){
	const char* str;
	std::string result;
	if (! PyArg_ParseTuple(args, "s", &str)) //把python的变量转换成c的变量
		return NULL;
	result = Categorizatetopic(str);
	return Py_BuildValue("s", result.c_str());//把c的返回值n转换成python的对象
}
static  PyObject* genre_classfy(PyObject* self, PyObject* args){
	const char* str;
	std::string result;
	if (! PyArg_ParseTuple(args, "s", &str)) //把python的变量转换成c的变量
		return NULL;
	result = Categorizategenre(str);
	return Py_BuildValue("s", result.c_str());//把c的返回值n转换成python的对象
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

