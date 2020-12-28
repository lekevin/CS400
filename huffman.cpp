#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

// Struct for Huffman Tree Node
struct Node
{
    char ch;
    int freq;
    Node* left, * right;
};


// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* left, Node* right)
    {
        // highest priority item has lowest frequency
        return left->freq > right->freq;
    }
};

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == NULL)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

unordered_map<char, string> printAndReturnEncode(Node* root) {

    // Traverse the Huffman Tree and store Huffman Codes in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are :\n" << '\n';
    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    return huffmanCode;

}


// Builds Huffman Tree and decode given input text
Node* buildHuffmanTree(unordered_map<char, int>& freq)
{

    // Create a priority queue to store live nodes of Huffman tree;
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it to the priority queue.
    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, NULL, NULL));
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1)
    {
        // Remove the two nodes of highest priority (lowest frequency) from the queue
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top();   pq.pop();

        // Create a new internal node with these two nodes as children and with frequency equal
        // to the sum of the two nodes' frequencies. Add the new node to the priority queue.
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to root of Huffman Tree
    Node* root = pq.top();
    return root;
}


string readFileReturnText(string inputFileName) {
    ifstream ifs(inputFileName);
    string text;
    getline(ifs, text, (char)ifs.eof());

    ifs.close();

    return text;
}

unordered_map<char, int> readFileAndGenerateFreq(string inputFileName) {

    string text = readFileReturnText(inputFileName);

    //Count frequency of appearance of each character and store it in a map
    unordered_map<char, int> freq;

    int i = 0;
    while (text[i] != '\0') {
        freq[text[i++]] += 1;
    }

    //print Count of frequency of each character
    cout << "Char and Freq:\n" << '\n';
    for (auto pair : freq) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return freq;
}

void encodeAndSave(unordered_map<char, string>& huffmanCode, string inputFileName) {

    string text = readFileReturnText(inputFileName);

    // print encoded string
    string encodedStr = "";
    for (char ch : text) {
        encodedStr += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n" << encodedStr << '\n';

    //Save Encoded String
    string outputFileName = "pride.huff";
    ofstream out(outputFileName);
    out << encodedStr;
    out.close();


}

int main() {

    unordered_map<char, int> freq = readFileAndGenerateFreq("HF.txt");

    Node* root = buildHuffmanTree(freq);

    unordered_map<char, string> huffmanCode = printAndReturnEncode(root);

    encodeAndSave(huffmanCode, "HF.txt");


    return 0;
}