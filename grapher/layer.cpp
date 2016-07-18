#include "layer.h"


using namespace std;

Layer::Layer(QString name, int layer_id)
{
    this->name = name;
    this->layer_id = layer_id;
}


void Layer::draw()
{
    foreach(Edge e, edges)
    {
        draw_edge(e,layer_id);
    }

    foreach(Node n, nodes)
    {
        draw_node(n, layer_id);
    }
}

void Layer::clear_all()
{
    edges.clear();
    nodes.clear();
}

void Layer::add_node(Node n)
{
    nodes.push_back(n);
}

void Layer::add_edge(Edge e)
{
    edges.push_back(e);
}
