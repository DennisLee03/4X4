#include <iostream>
using namespace std;

void Solve(int data[], int which);
bool Checker(int data[], int which);
void Output(int data[]);
void Save_and_Check(int data[]);

bool flag[16];
int k = 0;
int save[8000][16];

int main(void) {

	int data[16];
	for (int i = 0; i < 16; i++) {
		data[i] = 0;
		flag[i] = true;
	}
	Solve(data, 0);

	return 0;
}

void Solve(int data[], int which) {
	for (int i = 0; i < 16; i++) {
		if (flag[i]) {
			flag[i] = false;
			data[which] = i + 1;
			if (which == 3) {
				if (!Checker(data, 3)) {
					flag[i] = true;
					continue;
				}
			}
			else if (which == 7) {
				if (!Checker(data, 7)) {
					flag[i] = true;
					continue;
				}
			}
			else if (which == 11) {
				if (!Checker(data, 11)) {
					flag[i] = true;
					continue;
				}
			}
			else if (which == 12) {
				if (!Checker(data, 12)) {
					flag[i] = true;
					continue;
				}
			}
			else if (which == 13) {
				if (!Checker(data, 13)) {
					flag[i] = true;
					continue;
				}
			}
			else if (which == 14) {
				if (!Checker(data, 14)) {
					flag[i] = true;
					continue;
				}
			}
			else if (which == 15) {
				if (Checker(data, 15)) {
					//´¡savecheck
					Output(data);
				}
				flag[i] = true;
				continue;
			}
			Solve(data, which + 1);
			flag[i] = true;
		}
	}
}

bool Checker(int data[], int which) {
	if (which == 3) {
		if (data[0] + data[1] + data[2] + data[3] == 34) return true;
		else return false;
	}
	else if (which == 7) {
		if (data[4] + data[5] + data[6] + data[7] == 34) return true;
		else return false;
	}
	else if (which == 11) {
		if (data[8] + data[9] + data[10] + data[11] == 34) return true;
		else return false;
	}
	else if (which == 12) {
		if (data[0] + data[4] + data[8] + data[12] == 34 && data[3] + data[6] + data[9] + data[12] == 34) return true;
		else return false;
	}
	else if (which == 13) {
		if (data[1] + data[5] + data[9] + data[13] == 34) return true;
		else return false;
	}
	else if (which == 14) {
		if (data[2] + data[6] + data[10] + data[14] == 34) return true;
		else return false;
	}
	else if (which == 15) {
		if (data[0] + data[5] + data[10] + data[15] == 34 && data[3] + data[7] + data[11] + data[15] == 34 && data[12] + data[13] + data[14] + data[15] == 34) return true;
		else return false;
	}
	else return false;
}

void Output(int data[]) {
	for (int i = 0; i < 16; i++) {
		printf("%3d", data[i]);
		if ((i + 1) % 4 == 0) cout << endl;
	}
	printf("= == = %d = == =\n", k + 1);
	k++;
}
void Save_and_Check(int data[]) {
	for (int i = 0;i < 16;i++)
		save[k][i] = data[i];

}