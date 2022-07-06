#pragma once

// �ּ�ó���ϸ� �浹 �簢�� �Ⱥ���
//#define SHOW_COLLISION

#define SINGLE(type) \
private: \
	type(); \
	~type(); \
public: \
	static type* GetInstance() \
	{ \
		static type* Instance; \
		if(Instance == nullptr) \
			Instance = new type(); \
		return Instance; \
	}

#define KEY_STATE(InKey) CKeyManager::GetInstance()->GetKeyState(InKey)
#define MOUSE_POS CKeyManager::GetInstance()->GetMousePos();

#define MEMBER(type, name)									\
private:													\
	type name;												\
public:														\
	void Set##name(const type& InValue) {name = InValue;}	\
	type Get##name() const {return name;}

#define PROTECT_MEMBER(type, name)							\
protected:													\
	type name;												\
public:														\
	void Set##name(const type& InValue) {name = InValue;}	\
	type Get##name() const {return name;}

#define WIDTH 1020
#define HEIGHT 960