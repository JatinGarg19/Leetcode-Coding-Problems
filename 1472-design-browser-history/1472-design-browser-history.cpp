// represents each node of the doubly linked list.
class Node {
public:
    string url;
    Node* prev;
    Node* next;
    
    Node(string u) {
        url = u;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
public:
    Node* head;
    Node* curr;
    
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        curr = head;
    }
    
    void visit(string url) {   // Tc - O(1) - just creating new nodes and updating ptrs. 
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    
    string back(int steps) {  // Tc - O(steps)
        // keep moving back till steps != 0.
        while(steps > 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {  // Tc - O(steps)
        // keep moving forward till steps != 0.
        while(steps > 0 && curr->next != nullptr) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }  // Sc - O(n) where n is the number of url's visited so far.
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */