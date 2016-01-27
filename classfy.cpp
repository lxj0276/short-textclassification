#include <Python.h>
#include "model.h"
#include "../wordseg/seg.h"
#include "../commom/func.h"
stc::Model model;
seg::Wordseg mseg;
std::string Categorizate(const char* s){
	std::string str = s;
	commom::DEBUG_INFO("seginput");
	commom::DEBUG_INFO(str);
	std::string strseg = mseg.Segement(str);
	commom::DEBUG_INFO("seg");
	commom::DEBUG_INFO(strseg);
	return model.Classfy(strseg);
}
//python 包装
static  PyObject* wrap_classfy(PyObject* self, PyObject* args){
	const char* str;
	std::string result;
	if (! PyArg_ParseTuple(args, "s", &str)) //把python的变量转换成c的变量
		return NULL;
	result = Categorizate(str);
	return Py_BuildValue("s", result.c_str());//把c的返回值n转换成python的对象
}

static PyMethodDef textclassfyMethods[] ={
	{"Categorizate", wrap_classfy, METH_VARARGS, "textclassfy!"}, 
	{NULL, NULL}
};

extern "C"   {
	void inittextclassfy(){
		PyObject* m;
		m = Py_InitModule("textclassfy", textclassfyMethods);
	}
};

