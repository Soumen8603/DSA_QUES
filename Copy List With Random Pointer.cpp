Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        unordered_map<Node*,Node*>mp;
        Node* curr = head;
        while(curr != nullptr){
            Node* copy = new Node(curr -> val);
            mp[curr] = copy;
            curr = curr -> next;
        }
        curr = head;
        while(curr != nullptr){
            Node* copy = mp[curr];
            copy -> next = mp[curr -> next];
            copy -> random = mp[curr -> random];
            curr = curr -> next;
        }
        return mp[head];
    }
