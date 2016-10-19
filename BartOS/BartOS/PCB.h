#pragma once
class PCB
{
public:
	PCB();
	~PCB();
	int Process_State,
		Process_ID,Process_Child_ID,
		Memory_Begin,
		Memory_Limit;
	bool HasChild;
	void RequestMemoryBegin(int &Memory_Begin);
	void RequestMemoryLimit(int &Memory_Begin);
	typedef enum//Stany Procesora
	{
		Proc_New,Proc_Waiting,Proc_Ready
	};
};

