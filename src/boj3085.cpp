#include <iostream>
#include <vector>

using namespace std;

int find_max(char **candy, int n) {
	int max_len = 0;
	int is_max;
	vector<char> v;

	for(int i = 0; i < n; i++) {
		v.push_back(candy[i][0]);
		for(int j = 1; j < n; j++) {
			if(v.back() != (candy[i][j])) {
				is_max = v.size();
				if(is_max > max_len) {
					max_len = is_max;
				}
				v.clear();
				v.push_back(candy[i][j]);
			} else {
				v.push_back(candy[i][j]);
			}
		}
		is_max = v.size();
		if(is_max > max_len) {
			max_len = is_max;
		}
		v.clear();
	}

	for(int j = 0; j < n; j++) {
		v.push_back(candy[0][j]);
		for(int i = 1; i < n; i++) {
			if(v.back() != candy[i][j]) {
				is_max = v.size();
				if(is_max > max_len) {
					max_len = is_max;
				}
				v.clear();
				v.push_back(candy[i][j]);
			} else {
				v.push_back(candy[i][j]);
			}
		}
		is_max = v.size();
		if(is_max > max_len) {
			max_len = is_max;
		}
		v.clear();
	}

	return max_len;
}

void candy_lover(char **candy, int n) {
	int max_len = 0;
	int is_max;
//	row
	char tmp;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-1; j++) {
			tmp = candy[i][j];
			candy[i][j] = candy[i][j+1];
			candy[i][j+1] = tmp;

			is_max = find_max(candy, n);

			if(is_max > max_len) {
				max_len = is_max;
			}

			tmp = candy[i][j];
			candy[i][j] = candy[i][j+1];
			candy[i][j+1] = tmp;
		}
	}

//	column
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < n-1; i++) {
			tmp = candy[i][j];
			candy[i][j] = candy[i+1][j];
			candy[i+1][j] = tmp;

			is_max = find_max(candy, n);
			
			if(is_max > max_len) {
				max_len = is_max;
			}

			tmp = candy[i][j];
			candy[i][j] = candy[i+1][j];
			candy[i+1][j] = tmp;
		}
	}

	printf("%d\n", max_len);

}

int main(void) {
	int n;
	cin >> n;
	if(n < 3 || n > 50) {
		printf("Invalid candy number\n");
		return -1;
	}

	char **candy = new char*[n];
	for(int i = 0; i < n; i++){
		candy[i] = new char[n];
	}
	char tmp;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> tmp;
			candy[i][j] = tmp;
		}
	}

	candy_lover(candy, n);

	delete[] candy;

	return 0;
}
