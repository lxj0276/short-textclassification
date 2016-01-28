#include "model.h"
namespace stc{
	Model::Model(){
		dicttopic.LoadDict(25,"./dict/classfication/wordlist/");
		dictgenre.LoadDict(4,"./dict/classfication/typelist/");
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

	bool Model::Classfy(std::string typestr, std::string& str){
		typestr = TopicClassfy(str) + "\t"+ GenreClassfy(str) + "\t" + str;
		typestr = GenreClassfy(str) + "\t" + str;
	}
}