#include "bits/stdc++.h"
using namespace std;

template<typename K,typename V>
struct Node{
    K key;
    V value;
    Node* next;
    Node(K key, V value): key(key), value(value), next(nullptr){}
};

template<typename K,typename V>
struct HashMap{
    const int size;
    Node<K,V>** arr;
    //HashMap() = default;
    HashMap(const int size = 10) : size(size){
        arr = new Node<K,V>*[size];
        for(int i = 0; i < size; ++i) arr[i] = nullptr;
    }
    int getSlot(K key);
    void insert(Node<K,V>* data);
    V get(K key);
    void remove(K key);
    void print();
    V operator[](K key){
        return get(key);
    }
};

template<typename K, typename V>
int HashMap<K,V>::getSlot(K key){
    //cout << "Slot "<< key%size << endl;
    return key%size;
}

template<typename K,typename V>
void HashMap<K,V>::insert(Node<K,V>* data){
    K key = data->key;
    int slot = getSlot(key);
    Node<K,V>* ptr = arr[slot];
    //arr[slot] = new Node()
    if(!ptr){
        cout << "INSERT\n";
        arr[slot] = new Node<K,V>(data->key,data->value);
        return;
    }
    while(ptr){
        if(ptr->key == key) {ptr->value = data->value; return;}
        if(!ptr->next){
            ptr->next = new Node<K,V>(data->key,data->value);
            return;
        }
        ptr = ptr->next;
    }
}

template<typename K,typename V>
V HashMap<K,V>::get(K key){
    int slot = getSlot(key);
    Node<K,V>* ptr = arr[slot];
    while(ptr){
        if(ptr->key == key){
            return ptr->value;
        }
        ptr = ptr->next;
    }
    cout << "Not found\n";
    return *(new V());
}

template<typename K, typename V>
void HashMap<K,V>::print(){
    cout << "HashMap : \n";
    for(int i = 0;i < size; ++i){
        Node<K,V>* ptr = arr[i];
        cout << "| "<<i<<" | ";
        while(ptr){
            cout << ptr->key << " - " << ptr->value << " --> ";
            ptr = ptr->next;
        } cout << endl;
    }
}


int main(){
    Node<int,string>* n1 = new Node<int,string>(1,"Nidhi");
    //cout << n1->value << endl;
    HashMap<int,bool>* hm = new HashMap<int,bool>(7);
    hm->insert(new Node<int,bool>(3,true));
    hm->insert(new Node<int,bool>(2,false));
    hm->print();
    cout << hm->get(3) << endl;
    HashMap<int,string>* hm1 = new HashMap<int,string>(8);
    hm1->insert(new Node<int,string>(1,"Nidhi"));
    hm1->insert(new Node<int,string>(2,"Vinay"));
    hm1->insert(new Node<int,string>(3,"Codeforces"));
    hm1->insert(new Node<int,string>(1,"CChef"));
    hm1->insert(new Node<int,string>(9,"Goldman"));
    hm1->insert(new Node<int,string>(1,"Nidhi"));
    cout << (*hm1)[9] << endl;
    hm1->print();
    return 0;
}
/*
Output : 
INSERT
INSERT
HashMap : 
| 0 | 
| 1 | 
| 2 | 2 - 0 --> 
| 3 | 3 - 1 --> 
| 4 | 
| 5 | 
| 6 | 
1
INSERT
INSERT
INSERT
Goldman
HashMap : 
| 0 | 
| 1 | 1 - Nidhi --> 9 - Goldman --> 
| 2 | 2 - Vinay --> 
| 3 | 3 - Codeforces --> 
| 4 | 
| 5 | 
| 6 | 
| 7 |
*/

