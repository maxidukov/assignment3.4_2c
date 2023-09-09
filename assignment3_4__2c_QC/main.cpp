#include <iostream>
#include <fstream>
#include <string>

class Address{
   //public:
   std::string city, street;
   int building, app;
   public:
   /*Address(std::string city, std::string street,
            int building, int app){
     this->city = city;
     this->street = street;
     this->building = building;
     this->app = app;
   }*/
   Address() {}
   Address(std::ifstream& fin){
     fin >> city >> street
        >>building >> app;
   }
   /*Address(Address* paddr){
      city = paddr->city;
      street = paddr->street;
      building = paddr->building;
      app = paddr->app;
   }*/
   std::string ret_string(){
     return city + ", " +
            street + ", " +
            std::to_string(building) + ", " +
            std::to_string(app) + "\n";
   }
   std::string get_city(){
     return city;
   }
};

void sort_paddrs(Address*, int);

int main() {
  std::ifstream fin("in.txt");
  int num;
  Address* addrs;
  if(fin.is_open()){
     //std::string input;
    //int num;
    fin >> num;
    addrs = new Address[num];
    for(int i{};i<num&&fin;i++){
      addrs[i] = Address(fin);
    }
  }else{
    std::cout<<"Couldn't open file!\n";
    return 1;
  }
  fin.close();
  sort_paddrs(addrs,num);
  std::ofstream outfile("out.txt");
  outfile << num << "\n";
  for(int i{};i<num;i++){
      outfile << addrs[i].ret_string();
  }
  outfile.close();

  delete[] addrs;

  return 0;
}

void sort_paddrs(Address* paddrs, int size){
   bool sorted = false;
   while(!sorted){
     sorted = true;
     for(int i{};i<size-1;i++){
       if(paddrs[i].get_city()>paddrs[i+1].get_city()){
         Address temp = paddrs[i];
         paddrs[i] = paddrs[i+1];
         paddrs[i+1] = temp;
         sorted = false;
       }
     }
   }
}
