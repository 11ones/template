#include <bits/stdc++.h>
using namespace std;

//#include <bits/extc++.h>

#include <ext/rope>
using namespace __gnu_cxx;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using TR = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>; // less_equal<int>

int main() {
  rope<int> r;
  crope cr;
  cr.insert(2, "as");
  cr.erase(2, 3); // index, number
  cr.replace(2, 3, "ab");
  cr = cr + cr;
  
  TR tr;
  tr.insert(2);
  tr.find_by_order(1); // 0based index -> iterator
  tr.order_of_key(2); // value -> index
  tr.erase(tr.find_by_order(tr.order_of_key(2)));
}