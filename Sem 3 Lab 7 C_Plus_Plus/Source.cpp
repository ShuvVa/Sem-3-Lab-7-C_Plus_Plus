#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

const string Out_F = "Result.txt";//	��������� ���� string, ���������� � ���� ��� ����� ������ ����������� ������ ������

class Tree_Sort{
private:
	vector<int> tree;//	����������, ���������� � ���� �������� ������
	int level_counter;//����������, ���������� � ���� ���������� ������� ������

public:
	// ����������� ������ ��-���������, ����������� ���� ������� ����� ��� ����������
	Tree_Sort() {
		tree.push_back(NULL);
		level_counter = 1;
		Tree_Assign();
	}
	//	����������� ������, ����������� ������������ ������ ����� ��� ����������
	Tree_Sort(vector<int> temp) {
		tree.clear();
		level_counter = 0;
		if (temp.size()) {
			Tree_Level_Append();
			tree[0] = temp[0];

			for (int i = 1; i < temp.size(); i++) {
				Num_Sort(temp[i], 0);
			}
		}
		else {
			cout << "�������� ������ ���������� ����������, �.�. �� �������� ������." << endl;
		}

	}

	//	�����, ���������� �� ���������� ���-�� ������� (� � ���� - � ���-�� ���������)
	void Tree_Level_Append() {
		level_counter++;
		int temp = pow(2, level_counter-1);
		for (int i = 0; i < temp; i++)
			tree.push_back(NULL);
	}
	//	�����, ���������� �� ������������� ����� �� ������
	void Num_Sort(int number, int current_index) {
		
		if (current_index >= tree.size()) {
			Tree_Level_Append();
		}
		
		if (tree[current_index] == NULL) {
			tree[current_index] = number;
		}
		else if (number <= tree[current_index]) {
			Num_Sort(number, current_index * 2 + 1);
		}
		else Num_Sort(number, current_index * 2 + 2);
		
	}
	//	�����, ���������� �� ���� ����������� ����� ������������ ������� ����������
	void Tree_Assign() {
		tree.clear();
		level_counter = 0;
		vector<int> temp;
		int temp_counter = 0, temp_num = 0;

		cout << "������� ���������� �������� �����:\n: ";
		cin >> temp_counter;
		cout << endl;

		for (int i = 0; i < temp_counter; i++) {
			cout << "������� ����� �" << i+1 << ":\n: ";
			cin >> temp_num;
			temp.push_back(temp_num);
			cout << endl;
		}

		Tree_Level_Append();
		tree[0] = temp[0];

		for (int i = 1; i < temp.size(); i++) {
			Num_Sort(temp[i], 0);
		}
	}
	//	�����, ���������� �� ����������� ������ � ������
	string Tree_ToString() {
		string output_string = "";

		int zapolnitel_counter = 0, item_count = 0, current_level_num_count = 0;

		for (int i = 0; i < level_counter; i++) {
			zapolnitel_counter = pow(2, level_counter - i) - 1;
			current_level_num_count = pow(2, i);

			for (int j = 0; j < current_level_num_count; j++) {
				for (int k = 0; k < zapolnitel_counter; k++) {
					output_string += " ";
				}

				output_string += to_string(tree[item_count]);

				for (int k = 0; k < zapolnitel_counter; k++) {
					output_string += " ";
				}
				if (j < current_level_num_count - 1) output_string += " ";
				item_count++;
			}

			output_string += "\n";
		}
		return output_string;
	}
	//	�����, ���������� �� ����� � �������
	void Tree_Print() {
		cout << Tree_ToString();
	}
	//	�����, ���������� �� ����� � ����
	void Tree_SaveToFile() {
		
		ofstream setdata(Out_F);

		setdata << Tree_ToString();

		setdata.close();
	}
};

int main() {
	setlocale(LC_ALL, "Rus");

	ofstream clearOut(Out_F);
	clearOut.close();

	//vector<int> Test_mass = {10,9,11,10};
	//Tree_Sort test(Test_mass);

	Tree_Sort test;

	test.Tree_Print();
	test.Tree_SaveToFile();

	return 0;
}