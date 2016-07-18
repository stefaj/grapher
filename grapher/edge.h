#ifndef EDGE_H
#define EDGE_H

#include "node.h"
#include "rgb.h"

struct Edge{
    Node source;
    Node target;
};

inline Edge create_edge(Node n1, Node n2)
{
    Edge e; e.source = n1; e.target = n2;
    return e;
}


#endif // EDGE_H
