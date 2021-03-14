#include <iostream>
#include <string>
#include <map>


using namespace std;


struct node
{
	map<char, node> next;
	bool isEnd = false;
} start;


int main()
{
	string word;
	uint16_t word_count, c_pos;
	node* cur_node = &start;
	uint32_t counter = 0;

	cin >> word_count;
	
	for (uint16_t w = 0; w < word_count; w++) {
		cin >> word;

		cur_node = &start.next[word[0]];
		c_pos = 1;

		for (uint16_t i=1; i < word.size(); i++)
		{
			if (cur_node->next.size() > 1) {
				c_pos = i + 1;
			}
			
			cur_node = &cur_node->next[word[i]];
		}

		if (cur_node->isEnd) {
			counter += c_pos;
		}
		else {
			cur_node->isEnd = true;
			counter += word.size();
		}
	}

	cout << counter;
}