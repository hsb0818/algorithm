#pragma once

#define NONE 0

class HashTable
{
private:
	int* table;
	const int table_size;
	const int hash2_prime;
	int size;

private:
	int hash1(int key)
	{
		return key % table_size;
	}

	int hash2(int key)
	{
		return hash2_prime - (key % hash2_prime);
	}

public:
	HashTable(const int _table_size, const int _hash2_prime)
		: table_size(_table_size), hash2_prime(_hash2_prime)
		, size(0)
	{
		table = new int[table_size];
		memset(table, 0, table_size * sizeof(int));
	}

	~HashTable()
	{
		delete[] table;
	}

	bool IsFull()
	{
		return size == table_size;
	}

	int hash(int key)
	{
		int h1 = hash1(key);
		int h2 = hash2(key);
	
		int h = h1;
		for (int i = 1; table[h] != NONE; i++)
		{
			h = hash1(h1 + h2 * i);
		}

		return h;
	}

	bool Insert(int n)
	{
		if (IsFull())
			return false;

		table[hash(n)] = n;
		size++;

		return true;
	}

	void Display()
	{
		for (int i = 0; i < table_size; i++)
		{
			if (table[i] != NONE)
				printf("%d --> %d\n", i, table[i]);
			else
				printf("%d\n", i);
		}
	}

public:

};