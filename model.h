#ifndef  _MODEL_H_
#define _MODEL_H_
#include "../categorization/textcategorization.h"
namespace stc{
	class Model{
	public:
		classfy::DictClassfy dicttopic;
		classfy::DictClassfy dictgenre;
	public:
		Model();
		~Model(){}
		std::string TopicClassfy(std::string& str);
		std::string GenreClassfy(std::string& str);
		std::string Classfy(std::string& str);
	};
}
#endif
