#include<iostream>
#include"VectorQuantizer.h"
using namespace std;

int main()
{
	int ib = 8, bs[3] = { 2, 4, 8 }, is = 256, cs[3] = { 16, 32, 64 };
	float epslon = 1e-3;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << "Block size:" << bs[i] << "*" << bs[i]
				<< '\t' << "Codebook size:" << cs[j] << endl;

			VectorQuantizer VQ(ib, bs[i], is, cs[j]);
			VQ.loadImage("f16.256");
			VQ.imageBlocking(Train);
			VQ.loadImage("couple.256");
			VQ.imageBlocking(Train);
			VQ.loadImage("elaine.256");
			VQ.imageBlocking(Train);
			VQ.kmean(epslon);

			cout << "chem.256" << endl;
			VQ.quantize("chem.256");
			cout << "house.256" << endl;
			VQ.quantize("house.256");
			cout << "moon.256" << endl;
			VQ.quantize("moon.256");
			
			cout << endl; 
		}
	}

	/*VectorQuantizer VQ_1(ib, bs[0], is, cs[0]);

	VQ_1.loadImage("f16.256");
	VQ_1.imageBlocking(Train);
	VQ_1.loadImage("couple.256");
	VQ_1.imageBlocking(Train);
	VQ_1.loadImage("elaine.256");
	VQ_1.imageBlocking(Train);
	VQ_1.kmean(epslon);
	VQ_1.quantize("chem.256");
	VQ_1.quantize("house.256");
	VQ_1.quantize("moon.256");*/

	return 0;
}