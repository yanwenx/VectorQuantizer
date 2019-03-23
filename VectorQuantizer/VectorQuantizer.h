#ifndef VECTORQUANTIZER_H
#define VECTORQUANTIZER_H

#include<fstream>
#include<vector>
#include<string>
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;

typedef struct BlockVector {
	vector<float> block;
	int index_k;		// which cluster the vector is in

	// constructor
	BlockVector(vector<float> b, int k) : block(b), index_k(k) {}
}*BV;

enum Aim {
	Train,
	Quantize
};

class VectorQuantizer
{
private:
	ifstream inFile;
	ofstream outFile;
	// blockSize and imageSize are represented by the side length
	int intensityBit, blockSize, imageSize, codebookSize;
	vector<vector<unsigned char>> imageMatrix;
	vector<vector<float>> imageBlocks, codebook;
	vector<BV> trainingBlocks, quantizeBlocks;
	vector<float> dist2cent;		// distance from each vector to the centroids
	// vector<float> quantizeDist;

	void kmeanInitial();
	float vectorDist(const vector<float>&, const vector<float>&);
	vector<float> clusterMean(int);
public:
	VectorQuantizer(int, int, int, int);
	~VectorQuantizer() {}
	void loadImage(string);
	void printImageMatrix();
	void imageBlocking(Aim);	/* Aim determines whether we want to train or quantize
								for training, the new image blocks will be push back
								to the trainingBlocks */
	void kmean(float);			// kmean training, should specify the termination epslon
	void quantize(string);
};


#endif	// VECTORQUANTIZER_H