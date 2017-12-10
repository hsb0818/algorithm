#pragma once

#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef unsigned char BYTE;

/*
 * how to use
 *
 *	BYTE img[32] = {
 *	'R', 'G', 'Y', 'G',
 *	'B', 'B', 'R', 'R',
 *	'C', 'R', 'K', 'C',
 *	'K', 'B', 'G', 'R',
 *	'C', 'B', 'C', 'K',
 *	'G', 'M', 'B', 'G',
 *	'C', 'G', 'G', 'C',
 *	'B', 'B', 'G', 'R'
 *	};
 *	
 *	int main()
 *	{
 *	HuffmanCode hc;
 *	hc.Run(img, 32);
 *	hc.Print();
 *	
 *	getchar();
 *	return 0;
 *	}
*/

class HuffmanCode
{
private:
	struct MinHeapNode
	{
		BYTE data;
		float freq;
		MinHeapNode *left, *right;

		MinHeapNode(BYTE _data = 0, float _freq = 0.f, 
			MinHeapNode* _left = nullptr, MinHeapNode* _right = nullptr)
			: data(_data)
			, freq(_freq)
			, left(_left)
			, right(_right)
		{}
	};

	struct CompMinHeap
	{
		bool operator()(const MinHeapNode* const a, const MinHeapNode* const b)
		{
			return (a->freq > b->freq);
		}
	};

private:
	unordered_map<BYTE, string> m_huffman;
	map<BYTE, float> m_probmap;
	vector<pair<BYTE, float> > m_freq;
	MinHeapNode* m_header_tree;

public:
	const vector<pair<BYTE, float> >& GetFreq() { return m_freq; }
	float GetProb(const BYTE& key) 
	{
		if (m_probmap.find(key) == m_probmap.end())
			return 0.f;

		return m_probmap[key];
	}

	const string& GetHuffCode(const BYTE key)
	{
		if (m_huffman.find(key) == m_huffman.end())
			return '\0';

		return m_huffman[key];
	}

	~HuffmanCode()
	{
		Free();
	}

private:
	void _Free(MinHeapNode* node)
	{
		if (node == nullptr)
			return;

		_Free(node->left);
		_Free(node->right);

		delete node;
	}

	void Encode(MinHeapNode* node, string str = "")
	{
		if (node == nullptr)
			return;

		if (node->data != '*')
			m_huffman.insert(unordered_map<BYTE, string>::value_type(node->data, str));

		Encode(node->left, str + "0");
		Encode(node->right, str + "1");
	}

	const vector<pair<BYTE, float> >& Probability(const BYTE* input, const int& size)
	{
		BYTE key = 0;
		for (int i = 0; i < size; i++)
		{
			key = input[i];
			if (m_probmap.find(key) != m_probmap.end())
				continue;

			int count = 0;
			for (int j = i; j < size; j++)
			{
				if (input[i] == input[j])
					count++;
			}

			m_probmap.insert(map<BYTE, float>::value_type(key, (float)count / (float)size));
		}

		vector<pair<BYTE, float> >(m_probmap.begin(), m_probmap.end()).swap(m_freq);
		sort(m_freq.begin(), m_freq.end(), [](const pair<BYTE, float>& a, const pair<BYTE, float>& b) -> bool
		{
			return a.second < b.second;
		});

		return m_freq;
	}

public:
	void Free()
	{
		if (m_header_tree == nullptr)
			return;

		_Free(m_header_tree->left);
		_Free(m_header_tree->right);

		delete m_header_tree;
	}

	void Clear()
	{
		Free();

		// swap technique for suitable memory;
		unordered_map<BYTE, string>(m_huffman).swap(m_huffman);
		map<BYTE, float>(m_probmap).swap(m_probmap);
		vector<pair<BYTE, float> >(m_freq).swap(m_freq);
	}

	void Run(const BYTE* input, const int& size)
	{
		priority_queue < MinHeapNode*, vector<MinHeapNode*>, CompMinHeap> min_heap;
		const vector<pair<BYTE, float> >& prob = Probability(input, size);
		for (int i = 0; i < prob.size(); i++)
			min_heap.push(new MinHeapNode(prob[i].first, prob[i].second));

		MinHeapNode *left, *right, *top;
		left = right = top = nullptr;

		while (min_heap.size() > 1)
		{
			left = min_heap.top();
			min_heap.pop();
			right = min_heap.top();
			min_heap.pop();

			top = new MinHeapNode('*', left->freq + right->freq);
			top->left = left;
			top->right = right;

			min_heap.push(top);
		}

		m_header_tree = min_heap.top();
		min_heap.pop();

		Encode(m_header_tree);
	}

	void Print()
	{
		unordered_map<BYTE, string>::iterator itr;
		for (itr = m_huffman.begin(); itr != m_huffman.end(); itr++)
			printf("%c : %s\n", itr->first, itr->second.c_str());
	}
};