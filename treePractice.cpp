
#include <iostream>
#include <vector>
#include <string>
#include"pch.h"
using namespace std;


class position{
public:
	string Element;

	position() {
		TheRoot = false;
		TheExternal = false;
		Element = "--Default Element--";

	}
	~position() {
		//Nothing here
	}
	void SetParent(position* P) {
		TheParent = P;
	}
	vector<position*> GetChildren() {
		return ChildrenList;
	}
	bool IsRoot() {
		return TheRoot;
	}
	bool SetIsRoot(bool B) {
		TheRoot = B;
	}
	bool IsExternal() {
		return TheExternal;
	}
	bool IsInternal() {
		return !IsExternal();
	}
	bool SetIsExternal(bool B) {
		TheExternal = B;
	}

	void SetChildren(position* R) {
		ChildrenList.push_back(R);
	}
private:
		position* TheParent;
		vector<position*> ChildrenList;
		bool TheRoot;
		bool TheExternal;

	
};

class Tree {
public:
	Tree() {
		TheSize = 0;
	}
	~Tree() {
		//Nothing here
	}
	bool IsEmpty() {
		return TheSize == 0;
	}
	int size() {
		return TheSize;
	}
	void  SetSize(int i) {
		TheSize = i;
	}
	position* root() {
		return TheRoot;
	}
	void SetRoot(position* R) {
		TheRoot = R;
	}
	
private:
	position* TheRoot;
	int TheSize;

};

int main()
{
	////Create Tree
	Tree MyTree;
	MyTree.SetSize(10);
	/////////////////////////////////////
	///define and create nodes
	/////////////////////////////////////
	///node 1
	position* Electro = new position;
	Electro->Element = "Electronics R'Us";
	Electro->SetIsRoot(true);
	Electro->SetIsExternal(false);
	///node 2
	position* RD = new position;
	RD->Element = "R&D";
	RD->SetIsRoot(false);
	RD->SetIsExternal(false);
	///node 3
	position* Sales = new position;
	Sales->Element = "Sales";
	Sales->SetIsRoot(false);
	Sales->SetIsExternal(false);
	///node 4
	position* Purchase = new position;
	Purchase->Element = "Purchasing";
	Purchase->SetIsRoot(false);
	Purchase->SetIsExternal(true);
	///node 5
	position* Manufacture = new position;
	Manufacture->Element = "Manufacturing";
	Manufacture->SetIsRoot(false);
	Manufacture->SetIsExternal(false);
	///node 6
	position* Domestic = new position;
	Domestic->Element = "Domestic";
	Domestic->SetIsRoot(false);
	Domestic->SetIsExternal(true);
	///node 7
	position* International = new position;
	International->Element = "International";
	International->SetIsRoot(false);
	International->SetIsExternal(true);
	///node 8
	position* TV = new position;
	TV->Element = "TV";
	TV->SetIsRoot(false);
	TV->SetIsExternal(true);
	///node 9
	position* CD = new position;
	CD->Element = "CD";
	CD->SetIsRoot(false);
	CD->SetIsExternal(true);
	///node 10
	position* Tuner = new position;
	Tuner->Element = "Tuner";
	Tuner->SetIsRoot(false);
	Tuner->SetIsExternal(true);
	////////////////////////////////////
	/////constructing tree
	/////define relations between nodes
	////////////////////////////////////
	MyTree.SetRoot(Electro);
	//node1
	//Electro
	Electro->SetChildren(RD);
	Electro->SetChildren(Sales);
	Electro->SetChildren(Purchase);
	Electro->SetChildren(Manufacture);
	//node2
	RD->SetParent(Electro);
	//node3
	Sales->SetParent(Electro);
	Sales->SetChildren(Domestic);
	Sales->SetChildren(International);
	//node4
	Purchase->SetParent(Electro);
	//node5
	Manufacture->SetParent(Electro);
	Manufacture->SetChildren(TV);
	Manufacture->SetChildren(CD);
	Manufacture->SetChildren(Tuner);
	//node6
	Domestic->SetParent(Sales);
	//node7
	International->SetParent(Sales);
	//node8
	TV->SetParent(Manufacture);
	//node9
	CD->SetParent(Manufacture);
	//node10
	Tuner->SetParent(Manufacture);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
