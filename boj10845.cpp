#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
	string command;
	int commandNum;
	
	queue<int> q;

	cin >> commandNum;

	// I want to use 'switch-case' but switch statement don't support string value!
	// It's new information to me hahaha! I know one more think^__^
	for(int i = 0; i < commandNum; i++){
		cin >> command;
		if(!strcmp(command.c_str(), "push")){
			int push_value;
			cin >> push_value;
			q.push(push_value);

		} else if(!strcmp(command.c_str(), "pop")){
			if(q.empty()) cout<<-1<<endl;
			else{
				cout<<q.front()<<endl;	
				q.pop();
			} 
			
		} else if(!strcmp(command.c_str(), "size")){
			cout<<q.size()<<endl;

		} else if(!strcmp(command.c_str(), "empty")){
			cout<<q.empty()<<endl;

		} else if(!strcmp(command.c_str(), "front")){
			if(q.empty()) cout<<-1<<endl;
			else cout<<q.front()<<endl;

		} else if(!strcmp(command.c_str(), "back")){
			if(q.empty()) cout<<-1<<endl;
			else cout<<q.back()<<endl;

		} else{
			cout<<"Invalid Command: "<<command<<endl;
		}
		
	}

}


