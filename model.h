#ifndef  _MODEL_H_
#define _MODEL_H_
#define TOPICNUM 25
#define CENRENUM 4
#include "../categorization/textcategorization.h"
namespace stc{
	class Model{
	public:
		classfy::DictClassfy dicttopic;
		classfy::DictClassfy dictgenre;
	public:
		Model();
		~Model(){}
		//void LoadDict(const char* dictpath);
		std::string TopicClassfy(std::string& str);
		std::string GenreClassfy(std::string& str);
		bool Classfy(std::string& typestr, std::string& str);
	};
}
#endif
