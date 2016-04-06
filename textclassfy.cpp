#include "model.h"
#include "../wordseg/seg.h"
#include "../commom/func.h"
bool ReadData(const char* filein, const char* fileout){
	stc::Model model;
	seg::Wordseg mseg;
	mseg.TnitPath("./dict/seg/");
	mseg.InitDict();
	FILE* fi = fopen(filein, "r");
	FILE* fo = fopen(fileout, "ab+");
	char buffer[MAX_LENTH];
	std::vector<std::string>vec;
	while (mseg.f.ReadLine(buffer,MAX_LENTH,fi)!=NULL){	
		std::string str = mseg.f.GetLine(buffer);
		std::string segstr = mseg.Segement(str.c_str());
		commom::DEBUG_INFO(segstr);
		std::string typestr = "";
		model.Classfy(typestr, segstr) ;
		typestr += "\n";
		mseg.f.WiteLine(typestr.c_str(), fo);
	}
	fclose(fi);
	fclose(fo);
	return true;
}
int main(int argc, char *argv[]) {
	ReadData(argv[1],argv[2]);
	return 0;
}