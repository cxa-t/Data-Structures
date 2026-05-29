#pragma once
#include<vector>

class UnionFindSet
{
public:
	UnionFindSet(size_t size)
		:_ufs(size, -1)
	{ }

	int findroot(int index)
	{
		int parent = index;
		while (_ufs[parent] > 0)
			parent = _ufs[parent];
		return parent;
	}

	bool Union(int index1, int index2)
	{
		int root1 = findroot(index1);
		int root2 = findroot(index2);
		if (root1 == root2) return false;
		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
		return true;
	}

	size_t Count()
	{
		size_t ret = 0;
		for (size_t i = 0; i < _ufs.size(); i++)
			if (_ufs[i] < 0)
				ret++;
		return ret;
	}

private:
	vector<int> _ufs;
};