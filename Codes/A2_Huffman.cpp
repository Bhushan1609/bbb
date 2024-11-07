
#include <bits/stdc++.h>
using namespace std;

// Node class for Huffman Tree
class Node
{
public:
    char ch;
    int freq;
    Node *left, *right;

    // Constructor
    Node(char character, int frequency)
    {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Custom comparator for the min heap
class Compare
{
public:
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

// Function to print Huffman Codes from the root of the Huffman Tree
void printCodes(Node *root, string str)
{
    if (!root)
        return;

    // If this is a leaf node, print the character and its code
    if (!root->left && !root->right)
    {
        cout << root->ch << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Main function to build the Huffman Tree and print codes
void buildHuffmanTree(const string &text)
{
    // Step 1: Calculate frequency of each character and store it in a hash map
    unordered_map<char, int> freq;
    for (auto ch : text)
        freq[ch]++;

    // Step 2: Create a priority queue (min heap) to store live nodes of the Huffman Tree
    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    // Step 3: Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq)
    {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Step 4: Iterate until only one node remains in the heap
    while (minHeap.size() != 1)
    {
        // Extract the two nodes with minimum frequency
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies
        Node *sumNode = new Node('\0', left->freq + right->freq);
        sumNode->left = left;
        sumNode->right = right;

        // Add the new node to the priority queue
        minHeap.push(sumNode);
    }

    // Step 5: The remaining node is the root node of the Huffman Tree
    Node *root = minHeap.top();

    // Print the Huffman Codes by traversing the tree
    cout << "Huffman Codes:\n";
    printCodes(root, "");
}

int main()
{
    string text;
    cout << "Enter the text to encode: ";
    getline(cin, text);

    buildHuffmanTree(text);
    return 0;
}
