#include "Splay.h"
#include "Gladiator.h"
#include <iostream> 


using namespace std;

template <class T>
void Print(SplayTree<T>& st) {
	st.Inorder(st.GetRoot());
	cout << endl;
}

int main() {
	SplayTree<Gladiator> st;
	st.Insert(Gladiator(1, 1, 5, NULL, false));
	st.Insert(Gladiator(2, 1, 4, NULL, false));
	Print(st);
	st.Insert(Gladiator(26, 1, 46, NULL, false));
	Print(st);
	if (st.Find(Gladiator(26, 1, 46, NULL, false)))
		cout << "Found" << endl;
	Print(st);
	Gladiator* arr = new Gladiator[st.GetSize()];
	st.ConvertToArray(arr, st.GetSize(), st.GetRoot(), st.GetSize()-1);
	for (int i = 0; i < st.GetSize(); ++i) {
		cout << arr[i].GetGladiatorID() << " ";
	}
	cout << endl;
	st.Delete(Gladiator(1, 1, 5, NULL, false));
	Print(st);
	system("pause");
	return 0;
}