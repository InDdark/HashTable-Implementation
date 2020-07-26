#include<iostream>
#include<string>
#include<stack>
#include<list>


using namespace std;
/**
void heapify(int arr[],int n,int i){
     int largest = i;
     int l = 2*i+1;
     int r = 2*i+2;

     if(l<n && arr[l]>arr[largest])
         largest = l;

     if(r<n && arr[r]>arr[largest])
         largest = r;  

    if(largest!=i){
    	swap(arr[i],arr[largest]);
    	heapify(arr,n,largest);
    }

} 

void heapSort(int arr[],int n){
      for(int i=n/2-1;i>=0;i--)
      	 heapify(arr,n,i);

       for(int i=n-1;i>0;i--){
       	  swap(arr[0],arr[i]);
       	  heapify(arr,i,0);
       }


}

void printArray(int arr[],int n){
   for(int i=0;i<n;i++)
   	  cout<<arr[i]<<" ";

}
*/
class HashTable{
  private:
  	static const int HashGroups = 20;
    list<pair<int,string>> HashTable[HashGroups]; 
  public:
  	bool IsEmpty() const;
  	int HashFunction(int key);
  	void InsertItem(int key,string value);
  	void Remove(int key);
  	void SearchItem(int key);
  	void PrintTable(); 
};

bool HashTable::IsEmpty() const{
	 int sum{};
	 for(int i{};i<HashGroups;i++){
	 	sum += HashTable[i].size();
	 }
	 if(!sum)
	 	return true;
	 return false;
}
int HashTable::HashFunction(int key){
	return key%HashGroups;
}

void HashTable::InsertItem(int key,string value){
    int Hashed_Key = HashFunction(key);
    auto& cell = HashTable[Hashed_Key];
    auto itr = begin(cell);
    bool KeyExists = false;
    for(;itr!=end(cell);itr++){
        if(itr->first==key){
        	itr->second = value;
        	KeyExists = true;
        	cout<<"[WARNING]: key exists: value changed\n";
        }

      }
    if(!KeyExists){
      cell.emplace_back(key,value);
    }
}

void HashTable::Remove(int key){
    int Hashed_Key = HashFunction(key);
    auto& cell = HashTable[Hashed_Key];
    auto itr = begin(cell);
    bool KeyExists = false;
    for(;itr!=end(cell);itr++){
        if(itr->first==key){
        	itr = cell.erase(itr);
        	KeyExists = true;
        	cout<<"[WARNING]: key exists: value changed\n";
        }

      }
      if(!KeyExists) cout<<"Key not Found\n";
}


void HashTable::PrintTable(){
    for(int i{};i<HashGroups;i++){
       if(HashTable[i].size()==0) continue;

       auto itr = HashTable[i].begin();
       for(;itr!=HashTable[i].end();itr++)
       	cout<<"[Key]: "<<itr->first<<" value: "<<itr->second<<"\n";
    }

}


int main(int argc,char* argv[]){
  HashTable tab;
  tab.InsertItem(12,"Ravi");
  tab.InsertItem(2,"Rav");
  tab.PrintTable();
}
