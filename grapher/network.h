#ifndef NETWORK_H
#define NETWORK_H

class Network {
  public:
    Network();
    void set_fibre_cost(float cost);
    void set_trench_cost(float cost);
  private:
    float c_trench;
    float c_fibre;
};

#endif // NETWORK_H
