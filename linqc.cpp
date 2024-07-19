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
	linqc::vec<Product> prodVec;

	prodVec.push_back(Product(3222));
	prodVec.push_back(Product(9842));
	prodVec.push_back(Product(3182));
	prodVec.push_back(Product(2166));

	linqc::vec<int32_t> numVec;
	numVec.push_back(1);
	numVec.push_back(2);
	numVec.push_back(3);
	numVec.push_back(4);
	numVec.push_back(5);
	numVec.push_back(6);

	linqc::vec<int32_t> nums{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	size_t count = nums.Where(COND(int n, n % 2 == 0)).Count();
	printf("%zu\n", count); // 5

	printf("----------- \n");
	printf("Test case 1 \n");
	printf("----------- \n");

	size_t c = prodVec.Count(); // 4
	printf("%zu \n", c);

	c = prodVec.Where(COND(Product p, p.ProductID == 2166)).Count(); // 1
	printf("%zu \n", c);

	c = prodVec.Where(COND(Product p, p.ProductID > 3200)).Count(); // 2
	printf("%zu \n", c);

	printf("----------- \n");
	printf("Test case 2 \n");
	printf("----------- \n");


	linqc::vec<int32_t> squares = numVec.Select(LINQ(int32_t x, x * x));
	for (auto n : squares) {
		printf("%d\n", n); // 1, 4, 9, 16, 25, 36
	}

	printf("----------- \n");
	printf("Test case 3 \n");
	printf("----------- \n");

	numVec.clear();

	numVec.push_back(3);
	numVec.push_back(8);
	numVec.push_back(1);
	numVec.push_back(2);

	size_t sum = numVec.Sum();
	printf("%zu \n", sum); // 14

	printf("----------- \n");
	printf("Test case 4 \n");
	printf("----------- \n");

	int32_t max = numVec.Max();
	printf("%d \n", max); // 8

	printf("----------- \n");
	printf("Test case 5 \n");
	printf("----------- \n");

	bool anyFalse = numVec.Any(COND(int32_t x, x == 25));
	bool anyTrue = numVec.Any(COND(int32_t x, x == 8));
	printf("%d \n", anyFalse); // 0
	printf("%d \n", anyTrue); // 1
}
