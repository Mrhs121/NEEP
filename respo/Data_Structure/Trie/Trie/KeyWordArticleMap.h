#pragma once



// 关键词与文章的映射 对象

class KeyWordArticleMap
{
public:
	KeyWordArticleMap();
	~KeyWordArticleMap(); 
private:
	char * key_word; //关键字
	int	   Articles_id[10]; // 这个关键词对应的文章列表
	
};

