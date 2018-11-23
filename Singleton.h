//
// Created by root on 18-11-23.
//

#ifndef MYREFLECT_SINGLETON_H
#define MYREFLECT_SINGLETON_H


namespace RF{

template <typename T>
class Singleton{
public:

	static T& getInstance(){
		static T t_obj;
		return t_obj;
	}

private:
	friend T;
	Singleton(){}
	~Singleton(){}

private:
	Singleton(const Singleton& ){}
	Singleton& operator=(const Singleton&){}
};

}


#endif //MYREFLECT_SINGLETON_H
