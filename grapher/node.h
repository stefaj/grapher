#ifndef NODE_H
#define NODE_H

#include "rgb.h"
#include "QVector2D"

enum NodeType{Generic, CentralOffice, Splitter, ONU};

struct Node{
    QVector2D pos;

    NodeType type;
};

inline Node create_node(float x, float y, NodeType type)
{
    Node n = Node();
    n.pos = QVector2D(x,y);
    n.type = type;
    return n;
}

inline Node create_node(float x, float y)
{
    Node n = Node();
    n.pos = QVector2D(x,y);
    n.type = Generic;
    return n;
}

#endif // NODE_H
