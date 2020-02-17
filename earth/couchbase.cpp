//
//  couchbase.cpp
//  earth
//
//  Created by Nandan Paramashiva on 2/15/20.
//  Copyright © 2020 Nandan Paramashiva. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include "couchbase.hpp"

class Node {
public:
    // Constructor
    Node(char c): ch(c){}
    
    // Function to add neighbors to this node.
    void addNeighbors(Node* n){
        neighbors.push_back(n);
    };
    
    // Computes the maximum path length from this node.
    int maxLength();
    
private:
    static int maxLengthHelper(Node* root,
                               std::unordered_map<Node*, int>& cache);
    
    char ch;                    // current value
    std::list<Node*> neighbors; // list of neighbors
};

//
// @brief: Helper function to compute the maximum path length from the root node
//         to the most distant remote node under the no-loops assumption.
//
// @params: -root  : Current Node to be considered as source
//          -cache : A map to store the precomputed values
//
// @returns: The maximum path length
//
// @Details: -Run time complexity is O(n), where n is #nodes in graph.
//           -Worst case Space complexity is O(n),
//            when entire graph looks like a linkedlist.
//
int Node::maxLengthHelper(Node* root, std::unordered_map<Node*, int>& cache){
    if(cache.find(root) != cache.end()){
        // We have already visited this node.
        // Get the length from the cache.
        return cache[root];
    }
    
    int localMax = 0;
    // Walk all the neighbors of current root and figure out a max length.
    // Note: For leaf node (i.e node with 0 neighbours), localMax is 0.
    for(auto n : root->neighbors){
        int len = maxLengthHelper(n, cache);
        localMax = std::max(localMax, 1+len);
    }
    
    // cache the maximum length for the current root.
    cache[root] = localMax;
    return localMax;
}

//
// @brief: Computes the maximum path length from the root node.
//
// @params: root - Source node
//
// @returns: The maximum path length
//
int Node::maxLength() {
    Node* root = this;
    std::unordered_map<Node*, int> cache;
    return  Node::maxLengthHelper(root, cache);
}

//
// Entry function for the Couchbase's programming question.
//
void couchbaseEntry(){

    Node* A = new Node('a');
    Node* B = new Node('b');
    Node* C = new Node('c');
    Node* D = new Node('d');
    Node* E = new Node('e');
    Node* F = new Node('f');

    // test case 1
    A->addNeighbors(B);
    A->addNeighbors(C);
    A->addNeighbors(D);
    B->addNeighbors(D);
    C->addNeighbors(D);
    C->addNeighbors(E);
    D->addNeighbors(E);
    std::cout<< "TC1-length:" << A->maxLength() << std::endl;
    
    // test case 2
    std::cout<< "TC2-length:" << B->maxLength() << std::endl;
    
    // test case 3
    D->addNeighbors(F);
    F->addNeighbors(E);
    std::cout<< "TC3-length:" << A->maxLength() << std::endl;

    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;

}
