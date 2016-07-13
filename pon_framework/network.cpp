#include "network.h"

Network::Network() {
  this->c_fibre = 0.0f;
  this->c_trench = 0.0f;
}

void Network::set_fibre_cost(float cost) {
  this->c_fibre = cost;
}

void Network::set_trench_cost(float cost) {
  this->c_trench = cost;
}
