#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "edge.h"
#include "node.h"
#include "renderer.h"
#include <QString>

using namespace std;

class Layer
{
public:
    Layer(QString name, int layer_id);
    void draw();
    void clear_all();
    void add_node(Node n);
    void add_edge(Edge e);

private:
    vector<Edge> edges;
    vector<Node> nodes;
    int layer_id;
    QString name;
};

#endif // LAYER_H
