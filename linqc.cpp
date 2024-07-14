#include <iostream>
#include "stdio.h"
#include "LINQc.h"

class Product {
public:
	Product(int32_t id) {
		ProductID = id;
	}
	int32_t ProductID;
};

int main()
{
	linqc::vec<Product> myVec;

	myVec.push_back(Product(3222));
	myVec.push_back(Product(9842));
	myVec.push_back(Product(3182));
	myVec.push_back(Product(2166));


	size_t c = myVec.Count();
	printf("%zu \n", c);

	c = myVec.Where(COND(Product p, p.ProductID == 2166)).Count();
	printf("%zu \n", c);
}
