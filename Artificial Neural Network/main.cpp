#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "Header.h"
using namespace std;

int main() {
	int nolayer, *neurons, *tofn, * x, i = 0, j = 0;
	float w = 0.1, b = 0.1;

	ifstream infile;
	infile.open("input1.txt");

	infile >> nolayer;
	x = (int*)malloc(nolayer * sizeof(int));
	tofn = (int*)malloc(nolayer * sizeof(int));
	neurons = (int*)malloc(nolayer * sizeof(int));

	for (i = 0; i < nolayer; i++)
	{
		infile >> neurons[i];
	}

	Layer* layers;
	layers = (Layer*)malloc(nolayer * sizeof(Layer));

	for (i = 0; i < nolayer; i++)
	{
		infile >> tofn[i];
		try{
			if (tofn[i] < 0 || tofn[i] > 2)
			{
				throw "Unidentified activation function!";
			}
		}
		catch (const char* msg) {
			cerr << msg << endl;
			return 0;
		}
		
	}

	i = 0;
	while (!infile.eof())
	{
		try {
			if (i > (neurons[0]-1) ) throw "Input shape does not match!";
		}
		catch (const char* msg) {
			cerr << msg << endl;
			return 0;
		}
		infile >> x[i];
		i++;
	}

	for (i = 0; i < nolayer; i++) 
	{
		if (i == 0) 
		{
			SigmoidNeuron* sig;
			sig = new SigmoidNeuron[neurons[0]];
			LReluNeuron* lrelu;
			lrelu = new LReluNeuron[neurons[0]];
			ReluNeuron* relu;
			relu = new ReluNeuron[neurons[0]];
			switch (tofn[i]) 
			{
			case 0:
				for (j = 0; j < neurons[i]; j++)
				{
					sig[j].z = x[j];
					sig[j].a = x[j];
				}
				layers[0].narr = sig;
				break;
			case 1:
				for (j = 0; j < neurons[i]; j++)
				{
					lrelu[j].z = x[j];
					lrelu[j].a = x[j];
				}
				layers[0].narr = lrelu;
				break;
			case 2:
				for (j = 0; j < neurons[i]; j++)
				{
					relu[j].z = x[j];
					relu[j].a = x[j];
				}
				layers[0].narr = relu;
				break;
			}
		}
		else {
			switch (tofn[i])
			{
			case 0:
				SigmoidNeuron * sig;
				sig = new SigmoidNeuron[neurons[i]];
				for (j = 0; j < neurons[i]; j++)
				{
					sig[j].z = 0;
					for (int k = 0; k < neurons[i - 1]; k++)
					{
						sig[j].z += w * layers[i - 1].narr[k].z;
					}
					sig[j].z += b;
				}
				layers[i].narr = sig;
				break;
			case 1:
				LReluNeuron * lrelu;
				lrelu = new LReluNeuron[neurons[i]];
				for (j = 0; j < neurons[i]; j++)
				{
					lrelu[j].z = 0;
					for (int k = 0; k < neurons[i - 1]; k++)
					{
						lrelu[j].z += w * layers[i - 1].narr[k].z;
					}
					lrelu[j].z += b;
				}
				layers[i].narr = lrelu;
				break;
			case 2:
				ReluNeuron * relu;
				relu = new ReluNeuron[neurons[i]];
				for (j = 0; j < neurons[i]; j++)
				{
					relu[j].z = 0;
					for (int k = 0; k < neurons[i - 1]; k++)
					{
						relu[j].z += w * layers[i - 1].narr[k].z;
					}
					relu[j].z += b;
				}
				layers[i].narr = relu;
				break;
			}
		}
	}

	for (i = 1; i < nolayer; i++)
	{
		for (j = 0; j < neurons[i]; j++)
		{
			layers[i].narr[j].activate();
		}
	}

	for (i = 0; i < nolayer; i++)
	{
		cout << "Layer" << i << ":" << endl;
		for (j = 0; j < neurons[i]; j++)
		{
			cout << layers[i].narr[j].a << endl;
		}
	}

	Network nt(layers);	

	return 0;
}