#pragma once
//object to creates an array for all instances. sorted, reversed, random permutation. 
class instances
{
public :
	//initalize all to 0
	instances() {
		arr = 0;
		length = 0;
		initialize = 0;
	}
	//destructs if the array was already initialized.
	~instances(){
		if (initialize) {
			delete[] arr;
			arr = nullptr;
		}
	}
	void increasing();
	void decreasing();
	void random();
	void initiate(int n);
	int* getArray();
	int getLength() const;

private:
	int* arr;
	int length;
	bool initialize;
};