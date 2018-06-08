#include <iostream>
#include <vector>

class unionfind
{
public:
  unionfind(int n):N(n),id(std::vector<int>(n)),size(std::vector<int>(n))
  {
    for(auto i=0;i<n;i++)
    {
        id[i] = i;
        size[i] = 1;
    }
  }

  auto find_root(int node)
  {
  /*
   -Finds and returns the root of 'node'
   -Uses path compression algorithm on the subnodes
  */
    int root = node;
    while(root != id[root])
        root = id[root];
    while(node != root)
    {
       auto temp_node = id[node];
        id[node] = root;
        node = temp_node;
    }

    return root;
  }

  auto make_union(int node1,int node2)
  {
     /*
      Connect two nodes by making the smaller node point to larger one
     */ 
    auto root1 = find_root(node1);
    auto root2 = find_root(node2);
    if(root1==root2)
        return;
    if(size[root2]>size[root1])
    {
        id[root1] = root2;
        size[root2]+=size[root1];
    }else{
        id[root2] = root1;
        size[root1]+=size[root2];
        }
    N--;
 } 
  
  auto connected(int node1,int node2)
  {  
      /*
        Checks if the two given nodes are connected or not
      */
        return find_root(node1)==find_root(node2);
  }
  
  auto print_id()
  {
      for(auto i = id.begin();i!=id.end();i++)
        std::cout << *i << " " ;
        std::cout << "\n";
  }

private:

 int N;
 std::vector<int>id;
 std::vector<int>size;
}; 

 
int main(int argc, char const *argv[])
{   
    //TEST RUN

    unionfind uf(10);
    uf.make_union(2,1);
    //uf.print_id();
    uf.make_union(4,3);
    uf.make_union(8,4);
    uf.make_union(9,3);
    //uf.print_id();
    uf.make_union(5,6);
    uf.make_union(5,2);
    uf.print_id();
    
    
    return 0;
}