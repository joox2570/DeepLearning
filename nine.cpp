/* By: Hyun Jun Joo
*  Date: July 19, 2018
*  Translation of simple 9 line Python deep learning code
*/
#include <random>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double training_set_inputs[4][3] = { { 0.0, 0.0, 1.0 }, { 1.0, 1.0, 1.0 }, { 1.0, 0.0, 1.0 }, { 0.0, 1.0, 1.0 } };
	double training_set_outputs[4][1] = { { 0.0 }, { 1.0 }, { 1.0 }, { 0.0 } };
	double arr[3][1] = { { 1.0 }, { 0.0 }, { 0.0 } };
	double synaptic_weights[3][1] = { {0.0} };
	double result = 0.0;
	srand(1);
	for (int i = 0; i < 3; i++)
		synaptic_weights[i][0] = 2.0 * (static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) - 1.0;
	for (int i = 0; i < 100000; i++) {
		double dot[4][1] = { { 0.0 } };
		double output[4][1] = { { 0.0 } };
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++)
				dot[i][0] += training_set_inputs[i][j] * synaptic_weights[j][0];
			output[i][0] = 1.0 / (1.0 + exp(-dot[i][0]));
		}
		for (int i = 0; i < 4; i++)
			dot[i][0] = (training_set_outputs[i][0] - output[i][0]) * output[i][0] * (1.0 - output[i][0]);
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 4; i++)
				synaptic_weights[j][0] += training_set_inputs[i][j] * dot[i][0];
		}
	}
	for (int i = 0; i < 3; i++)
		result += arr[i][0] * synaptic_weights[i][0];
	cout << setprecision(9) << (1.0 / (1.0 + exp(-result)));
}