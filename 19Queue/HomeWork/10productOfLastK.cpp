// Problem Link - https://leetcode.com/problems/product-of-the-last-k-numbers/
/* By Krishna Kumar */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class ProductOfNumbers
{
private:
    vector<int> prefixProduct;

public:
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (num == 0)
        {
            prefixProduct.clear();
            return;
        }
        if (prefixProduct.empty())
        {
            prefixProduct.push_back(num);
        }
        else
        {
            int prod = prefixProduct[prefixProduct.size() - 1] * num;
            prefixProduct.push_back(prod);
        }
    }
    int getProduct(int k)
    {
        if (k > prefixProduct.size())
        {
            return 0;
        }
        int size = prefixProduct.size();
        if (k == size)
            return prefixProduct[size - 1];
        int prod = prefixProduct[size - 1] / prefixProduct[size - k - 1];
        return prod;
    }
};