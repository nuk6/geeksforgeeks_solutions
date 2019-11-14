#include "iheaders.h"
template<typename K>
int getHash(K k,const int size){
    return (k%size);
}

template<typename K,typename V>
struct Node{
    K key;
    V value;
    Node* next;
    Node(K key, V value): key(key), value(value), next(nullptr){}
};

template<typename K, typename V, int size>
struct HashMap{
    Node<K,V>* arr[size];
    HashMap(){
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = nullptr;
        }
    }
    void insert(Node<K,V>* data);
    V get(K key);
    void erase(K key);
};

template<typename K, typename V, int size>
void HashMap<K,V,size>::insert(Node<K,V>* data){
    int hash = getHash(data->key,size);
    if(!arr[hash]){
        arr[hash] = new Node<K,V>(data->key,data->value);
    } else{
       // cout << data->value << endl;
        Node<K,V>* ptr = arr[hash];
        while(ptr->next){
            cout << ptr->value << endl;
            ptr = ptr->next;
        }
        ptr->next = new Node<K,V>(data->key, data->value);
        //arr[hash] = new Node<K,V>(data->key, data->value);
    }
    
}

int main(){
    HashMap<int,string,4>* myMap = new HashMap<int,string,4>();
    myMap->insert(new Node<int,string>(1,"Nidhi"));
    myMap->insert(new Node<int,string>(1,"Vinay"));
    if(myMap->arr[1]) cout << myMap->arr[1]->value << endl;
    if(myMap->arr[1]->next) cout << myMap->arr[1]->next->value << endl;
    //cout << getHash<string>("NIdhi") << endl;
    return 0;
}
