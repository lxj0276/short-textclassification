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
//python ��װ
static  PyObject* wrap_classfy(PyObject* self, PyObject* args){
	const char* str;
	std::string result;
	if (! PyArg_ParseTuple(args, "s", &str)) //��python�ı���ת����c�ı���
		return NULL;
	result = Categorizate(str);
	return Py_BuildValue("s", result.c_str());//��c�ķ���ֵnת����python�Ķ���
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

