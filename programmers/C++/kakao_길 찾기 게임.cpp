#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int x, y;
	int idx;
	Node* left;
	Node* right;
};

bool compare(Node a, Node b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y > b.y;
}

void setTree(Node* root, Node *newNode) {
	if (newNode->x < root->x) {
		if (root->left == NULL) {
			root->left = newNode;
			return;
		}
		setTree(root->left, newNode);
	}
	if (newNode->x > root->x) {
		if (root->right == NULL) {
			root->right = newNode;
			return;
		}
		setTree(root->right, newNode);
	}
}

void preorder(Node* tree, vector<int>* list) {
	if (tree == NULL) {
		return;
	}
	list->push_back(tree->idx);
	preorder(tree->left, list);
	preorder(tree->right, list);
}

void postorder(Node* tree, vector<int>* list) {
	if (tree == NULL) {
		return;
	}
	postorder(tree->left, list);
	postorder(tree->right, list);
	list->push_back(tree->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	vector<Node> nodes;
	for (auto i = 0; i < nodeinfo.size(); i++) {
		nodes.push_back({ nodeinfo[i][0], nodeinfo[i][1], i + 1, NULL, NULL});
	}
	sort(nodes.begin(), nodes.end(), compare);
	
	Node binaryTree = nodes[0];
	for (auto i = 1; i < nodes.size(); i++) {
		setTree(&binaryTree, &nodes[i]);
	}

	vector<int> prerderedList;
	vector<int> postorderedList;

	preorder(&binaryTree, &prerderedList);
	postorder(&binaryTree, &postorderedList);

	answer.push_back(prerderedList);
	answer.push_back(postorderedList);

	return answer;
}
