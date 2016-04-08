#include "model.h"
namespace stc{
	Model::Model(){}
	
	void Model::LoadDict(const char* dictpath){
		std::string pathtopic = std::string(dictpath) + "wordlist/";
		std::string pathtype = std::string(dictpath) + "typelist/";
		dicttopic._LoadDict(TOPICNUM,pathtopic.c_str());
		dictgenre._LoadDict(CENRENUM,pathtype.c_str());
	}
	std::string Model::TopicClassfy(std::string& str){
		std::string typestr = "";
		dicttopic.Categorizate(typestr,str);
		return typestr;
	}
	std::string Model::GenreClassfy(std::string& str){
		std::string typestr = "";
		dictgenre.Categorizate(typestr,str);
		return typestr;
	}

	bool Model::Classfy(std::string& typestr, std::string& str){
		typestr = TopicClassfy(str) + "\t"+ GenreClassfy(str) + "\t" + str;
		return true;
	}
}