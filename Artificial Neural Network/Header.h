#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Neuron
{
public:
	float z, a;
	virtual void activate() = 0;
	Neuron() { z = 0; a = 0; }
	Neuron(float x, float y)
	{
		z = x;
		a = y;
	}
};

class SigmoidNeuron : public Neuron
{
public:
	SigmoidNeuron() {}
	SigmoidNeuron(float i) { z = i; }
	void activate() 
	{
		a = 1 / (1 + pow(exp(1.0), -z));
	}
};

class ReluNeuron : public Neuron
{
public:
	ReluNeuron() {}
	ReluNeuron(float i) { z = i; }
	void activate()
	{
		a = fmax(0, z);
	}
};

class LReluNeuron : public Neuron
{
public:
	LReluNeuron() {}
	LReluNeuron(float i) { z = i; }
	void activate()
	{
		a = fmax(0.1 * z, z);
	}
};

class Layer
{
public:
	Neuron* narr;
	Layer() { narr = NULL; }
	Layer(Neuron* a) { narr = a; }
};

class Network
{
public:
	Layer* larr;
	Network() { larr = NULL; }
	Network(Layer* a) { larr = a; }
};