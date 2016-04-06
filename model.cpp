#include "model.h"
namespace stc{
	Model::Model(){
		dicttopic._LoadDict(TOPICNUM,"./dict/classfication/wordlist/");
		dictgenre._LoadDict(CENRENUM,"./dict/classfication/typelist/");
	}
	/*
	void Model::LoadDict(const char* dictpath){
		dicttopic._LoadDict(TOPICNUM,"./dict/classfication/wordlist/");
		dictgenre._LoadDict(CENRENUM,"./dict/classfication/typelist/");
	}
	*/
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