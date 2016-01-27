#include "model.h"
namespace stc{
	Model::Model(){
		dicttopic.LoadDict(25,"./dict/classfication/wordlist/");
		dictgenre.LoadDict(4,"./dict/classfication/typelist/");
	}
	std::string Model::TopicClassfy(std::string& str){
		return dicttopic.Categorizate(str);
	}

	std::string Model::GenreClassfy(std::string& str){
		return dictgenre.Categorizate(str);
	}
	std::string Model::Classfy(std::string& str){
		return TopicClassfy(str) + "\t"+ GenreClassfy(str) + "\t" + str;
	}
}