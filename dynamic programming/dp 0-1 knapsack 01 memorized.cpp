#include<bits/stdc++.h>
using namespace std;
#define v vector
#define pb push_back

// memorization approach
v<v<int>> dp(101,v<int>(100,-1));

void print(v<v<int>> &dp){
    cout<<"\nPrinting DP Table:\n";
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"End Of Table:\n";
}

int memorized(v<int>&we,v<int>&val,int w,int n){
    if(n==0 || w==0) return 0;
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    else if(we[n-1] <= w){
        dp[n][w] = max(val[n-1]+memorized(we,val,w-we[n-1],n-1),memorized(we,val,w,n-1));
        return dp[n][w];
    }else if(we[n-1] > w){
        dp[n][w] = memorized(we,val,w,n-1);
        return dp[n][w];
    }
    return 0;
}

int main(){
    cout<<"Enter Weight array size :\n";
    int n;cin>>n;
    cout<<"Enter Weight array \n";
    v<int> we;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        we.pb(x);
    }
    cout<<"Enter Value Array \n";
    v<int> val;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        val.pb(x);
    }
    cout<<"Enter Knapsack Maximum Weight holding capacity:\n";
    int w;cin>>w;

//    memset(dp,-1,sizeof(dp));
    cout<<"Maximum Profit : "<<memorized(we,val,w,n);
    //print(dp);
}


/*

||=== Build file: "no target" in "no project" (compiler: unknown) ===|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp||In function 'int memorized(std::vector<int>&, std::vector<int>&, int, int)':|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|error: no match for 'operator!=' (operand types are 'std::vector<std::vector<int> >' and 'int')|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|948|note: candidate: template<class _BiIter> bool std::__cxx11::operator!=(const std::__cxx11::sub_match<_BiIter>&, const std::__cxx11::sub_match<_BiIter>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|948|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__cxx11::sub_match<_BiIter>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1026|note: candidate: template<class _Bi_iter, class _Ch_traits, class _Ch_alloc> bool std::__cxx11::operator!=(std::__cxx11::__sub_match_string<_Bi_iter, _Ch_traits, _Ch_alloc>&, const std::__cxx11::sub_match<_BiIter>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1026|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'std::__cxx11::__sub_match_string<_Bi_iter, _Ch_traits, _Ch_alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1106|note: candidate: template<class _Bi_iter, class _Ch_traits, class _Ch_alloc> bool std::__cxx11::operator!=(const std::__cxx11::sub_match<_BiIter>&, std::__cxx11::__sub_match_string<_Bi_iter, _Ch_traits, _Ch_alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1106|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__cxx11::sub_match<_BiIter>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1183|note: candidate: template<class _Bi_iter> bool std::__cxx11::operator!=(const typename std::iterator_traits<_Iter>::value_type*, const std::__cxx11::sub_match<_BiIter>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1183|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   mismatched types 'const std::__cxx11::sub_match<_BiIter>' and 'int'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1257|note: candidate: template<class _Bi_iter> bool std::__cxx11::operator!=(const std::__cxx11::sub_match<_BiIter>&, const typename std::iterator_traits<_Iter>::value_type*)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1257|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__cxx11::sub_match<_BiIter>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1334|note: candidate: template<class _Bi_iter> bool std::__cxx11::operator!=(const typename std::iterator_traits<_Iter>::value_type&, const std::__cxx11::sub_match<_BiIter>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1334|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   mismatched types 'const std::__cxx11::sub_match<_BiIter>' and 'int'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1414|note: candidate: template<class _Bi_iter> bool std::__cxx11::operator!=(const std::__cxx11::sub_match<_BiIter>&, const typename std::iterator_traits<_Iter>::value_type&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1414|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__cxx11::sub_match<_BiIter>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1938|note: candidate: template<class _Bi_iter, class _Alloc> bool std::__cxx11::operator!=(const std::__cxx11::match_results<_BiIter, _Alloc>&, const std::__cxx11::match_results<_BiIter, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\regex.h|1938|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__cxx11::match_results<_BiIter, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unordered_set.h|1357|note: candidate: template<class _Value, class _Hash, class _Pred, class _Alloc> bool std::operator!=(const std::unordered_multiset<_Value, _Hash, _Pred, _Alloc>&, const std::unordered_multiset<_Value, _Hash, _Pred, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unordered_set.h|1357|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::unordered_multiset<_Value, _Hash, _Pred, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unordered_set.h|1345|note: candidate: template<class _Value, class _Hash, class _Pred, class _Alloc> bool std::operator!=(const std::unordered_set<_Value, _Hash, _Pred, _Alloc>&, const std::unordered_set<_Value, _Hash, _Pred, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unordered_set.h|1345|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::unordered_set<_Value, _Hash, _Pred, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unordered_map.h|1474|note: candidate: template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc> bool std::operator!=(const std::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>&, const std::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unordered_map.h|1474|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unordered_map.h|1462|note: candidate: template<class _Key, class _Tp, class _Hash, class _Pred, class _Alloc> bool std::operator!=(const std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>&, const std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unordered_map.h|1462|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\scoped_allocator|462|note: candidate: template<class _OutA1, class _OutA2, class ... _InA> bool std::operator!=(const std::scoped_allocator_adaptor<_OutA1, _InA ...>&, const std::scoped_allocator_adaptor<_InnerHead, _InnerTail ...>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\scoped_allocator|462|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::scoped_allocator_adaptor<_OutA1, _InA ...>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\thread|215|note: candidate: bool std::operator!=(std::thread::id, std::thread::id)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\thread|215|note:   no known conversion for argument 1 from 'std::vector<std::vector<int> >' to 'std::thread::id'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\forward_list.h|1368|note: candidate: template<class _Tp, class _Alloc> bool std::operator!=(const std::forward_list<_Tp, _Alloc>&, const std::forward_list<_Tp, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\forward_list.h|1368|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::forward_list<_Tp, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\forward_list.h|266|note: candidate: template<class _Tp> bool std::operator!=(const std::_Fwd_list_iterator<_Tp>&, const std::_Fwd_list_const_iterator<_Tp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\forward_list.h|266|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_Fwd_list_iterator<_Tp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\valarray|1180|note: candidate: template<class _Tp> std::_Expr<std::_BinClos<std::__not_equal_to, std::_Constant, std::_ValArray, _Tp, _Tp>, typename std::__fun<std::__not_equal_to, _Tp>::result_type> std::operator!=(const _Tp&, const std::valarray<_Tp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\valarray|1180|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   mismatched types 'const std::valarray<_Tp>' and 'int'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\valarray|1180|note: candidate: template<class _Tp> std::_Expr<std::_BinClos<std::__not_equal_to, std::_ValArray, std::_Constant, _Tp, _Tp>, typename std::__fun<std::__not_equal_to, _Tp>::result_type> std::operator!=(const std::valarray<_Tp>&, const _Tp&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\valarray|1180|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::valarray<_Tp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\valarray|1180|note: candidate: template<class _Tp> std::_Expr<std::_BinClos<std::__not_equal_to, std::_ValArray, std::_ValArray, _Tp, _Tp>, typename std::__fun<std::__not_equal_to, _Tp>::result_type> std::operator!=(const std::valarray<_Tp>&, const std::valarray<_Tp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\valarray|1180|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::valarray<_Tp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note: candidate: template<class _Dom> std::_Expr<std::_BinClos<std::__not_equal_to, std::_ValArray, std::_Expr, typename _Dom::value_type, _Dom>, typename std::__fun<std::__not_equal_to, typename _Dom1::value_type>::result_type> std::operator!=(const std::valarray<typename _Dom::value_type>&, const std::_Expr<_Dom1, typename _Dom1::value_type>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   mismatched types 'const std::_Expr<_Dom1, typename _Dom1::value_type>' and 'int'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note: candidate: template<class _Dom> std::_Expr<std::_BinClos<std::__not_equal_to, std::_Expr, std::_ValArray, _Dom, typename _Dom::value_type>, typename std::__fun<std::__not_equal_to, typename _Dom1::value_type>::result_type> std::operator!=(const std::_Expr<_Dom1, typename _Dom1::value_type>&, const std::valarray<typename _Dom::value_type>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_Expr<_Dom1, typename _Dom1::value_type>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note: candidate: template<class _Dom> std::_Expr<std::_BinClos<std::__not_equal_to, std::_Constant, std::_Expr, typename _Dom::value_type, _Dom>, typename std::__fun<std::__not_equal_to, typename _Dom1::value_type>::result_type> std::operator!=(const typename _Dom::value_type&, const std::_Expr<_Dom1, typename _Dom1::value_type>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   mismatched types 'const std::_Expr<_Dom1, typename _Dom1::value_type>' and 'int'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note: candidate: template<class _Dom> std::_Expr<std::_BinClos<std::__not_equal_to, std::_Expr, std::_Constant, _Dom, typename _Dom::value_type>, typename std::__fun<std::__not_equal_to, typename _Dom1::value_type>::result_type> std::operator!=(const std::_Expr<_Dom1, typename _Dom1::value_type>&, const typename _Dom::value_type&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_Expr<_Dom1, typename _Dom1::value_type>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note: candidate: template<class _Dom1, class _Dom2> std::_Expr<std::_BinClos<std::__not_equal_to, std::_Expr, std::_Expr, _Dom1, _Dom2>, typename std::__fun<std::__not_equal_to, typename _Dom1::value_type>::result_type> std::operator!=(const std::_Expr<_Dom1, typename _Dom1::value_type>&, const std::_Expr<_Dom2, typename _Dom2::value_type>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\valarray_after.h|415|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_Expr<_Dom1, typename _Dom1::value_type>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_stack.h|270|note: candidate: template<class _Tp, class _Seq> bool std::operator!=(const std::stack<_Tp, _Seq>&, const std::stack<_Tp, _Seq>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_stack.h|270|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::stack<_Tp, _Seq>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_multiset.h|844|note: candidate: template<class _Key, class _Compare, class _Alloc> bool std::operator!=(const std::multiset<_Key, _Compare, _Alloc>&, const std::multiset<_Key, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_multiset.h|844|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::multiset<_Key, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_set.h|861|note: candidate: template<class _Key, class _Compare, class _Alloc> bool std::operator!=(const std::set<_Key, _Compare, _Alloc>&, const std::set<_Key, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_set.h|861|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::set<_Key, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_queue.h|295|note: candidate: template<class _Tp, class _Seq> bool std::operator!=(const std::queue<_Tp, _Seq>&, const std::queue<_Tp, _Seq>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_queue.h|295|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::queue<_Tp, _Seq>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr.h|363|note: candidate: template<class _Tp> bool std::operator!=(std::nullptr_t, const std::shared_ptr<_Tp1>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr.h|363|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   cannot convert 'dp[n][w]' (type 'std::vector<std::vector<int> >') to type 'std::nullptr_t'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr.h|358|note: candidate: template<class _Tp> bool std::operator!=(const std::shared_ptr<_Tp1>&, std::nullptr_t)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr.h|358|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::shared_ptr<_Tp1>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr.h|352|note: candidate: template<class _Tp1, class _Tp2> bool std::operator!=(const std::shared_ptr<_Tp1>&, const std::shared_ptr<_Tp2>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr.h|352|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::shared_ptr<_Tp1>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr_base.h|1210|note: candidate: template<class _Tp, __gnu_cxx::_Lock_policy _Lp> bool std::operator!=(std::nullptr_t, const std::__shared_ptr<_Tp, _Lp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr_base.h|1210|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   cannot convert 'dp[n][w]' (type 'std::vector<std::vector<int> >') to type 'std::nullptr_t'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr_base.h|1205|note: candidate: template<class _Tp, __gnu_cxx::_Lock_policy _Lp> bool std::operator!=(const std::__shared_ptr<_Tp, _Lp>&, std::nullptr_t)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr_base.h|1205|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__shared_ptr<_Tp, _Lp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr_base.h|1199|note: candidate: template<class _Tp1, class _Tp2, __gnu_cxx::_Lock_policy _Lp> bool std::operator!=(const std::__shared_ptr<_Tp1, _Lp>&, const std::__shared_ptr<_Tp2, _Lp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\shared_ptr_base.h|1199|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__shared_ptr<_Tp1, _Lp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_multimap.h|995|note: candidate: template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator!=(const std::multimap<_Key, _Tp, _Compare, _Alloc>&, const std::multimap<_Key, _Tp, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_multimap.h|995|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::multimap<_Key, _Tp, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_map.h|1094|note: candidate: template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator!=(const std::map<_Key, _Tp, _Compare, _Alloc>&, const std::map<_Key, _Tp, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_map.h|1094|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::map<_Key, _Tp, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_tree.h|1303|note: candidate: template<class _Key, class _Val, class _KeyOfValue, class _Compare, class _Alloc> bool std::operator!=(const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&, const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_tree.h|1303|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_tree.h|331|note: candidate: template<class _Val> bool std::operator!=(const std::_Rb_tree_iterator<_Tp>&, const std::_Rb_tree_const_iterator<_Val>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_tree.h|331|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_Rb_tree_iterator<_Tp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_list.h|1843|note: candidate: template<class _Tp, class _Alloc> bool std::operator!=(const std::__cxx11::list<_Tp, _Alloc>&, const std::__cxx11::list<_Tp, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_list.h|1843|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__cxx11::list<_Tp, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_list.h|291|note: candidate: template<class _Val> bool std::operator!=(const std::_List_iterator<_Tp>&, const std::_List_const_iterator<_Val>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_list.h|291|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_List_iterator<_Tp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stream_iterator.h|137|note: candidate: template<class _Tp, class _CharT, class _Traits, class _Dist> bool std::operator!=(const std::istream_iterator<_Tp, _CharT, _Traits, _Dist>&, const std::istream_iterator<_Tp, _CharT, _Traits, _Dist>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stream_iterator.h|137|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::istream_iterator<_Tp, _CharT, _Traits, _Dist>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unique_ptr.h|652|note: candidate: template<class _Tp, class _Dp> bool std::operator!=(std::nullptr_t, const std::unique_ptr<_Tp, _Dp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unique_ptr.h|652|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   cannot convert 'dp[n][w]' (type 'std::vector<std::vector<int> >') to type 'std::nullptr_t'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unique_ptr.h|647|note: candidate: template<class _Tp, class _Dp> bool std::operator!=(const std::unique_ptr<_Tp, _Dp>&, std::nullptr_t)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unique_ptr.h|647|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::unique_ptr<_Tp, _Dp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unique_ptr.h|641|note: candidate: template<class _Tp, class _Dp, class _Up, class _Ep> bool std::operator!=(const std::unique_ptr<_Tp, _Dp>&, const std::unique_ptr<_Up, _Ep>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\unique_ptr.h|641|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::unique_ptr<_Tp, _Dp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\functional|2361|note: candidate: template<class _Res, class ... _Args> bool std::operator!=(std::nullptr_t, const std::function<_Res(_ArgTypes ...)>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\functional|2361|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   cannot convert 'dp[n][w]' (type 'std::vector<std::vector<int> >') to type 'std::nullptr_t'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\functional|2355|note: candidate: template<class _Res, class ... _Args> bool std::operator!=(const std::function<_Res(_ArgTypes ...)>&, std::nullptr_t)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\functional|2355|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::function<_Res(_ArgTypes ...)>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\tuple|941|note: candidate: template<class ... _TElements, class ... _UElements> constexpr bool std::operator!=(const std::tuple<_Elements ...>&, const std::tuple<_Elements ...>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\tuple|941|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::tuple<_Elements ...>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\array|237|note: candidate: template<class _Tp, unsigned int _Nm> bool std::operator!=(const std::array<_Tp, _Nm>&, const std::array<_Tp, _Nm>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\array|237|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::array<_Tp, _Nm>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_deque.h|2245|note: candidate: template<class _Tp, class _Alloc> bool std::operator!=(const std::deque<_Tp, _Alloc>&, const std::deque<_Tp, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_deque.h|2245|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::deque<_Tp, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_deque.h|285|note: candidate: template<class _Tp, class _RefL, class _PtrL, class _RefR, class _PtrR> bool std::operator!=(const std::_Deque_iterator<_Tp, _Ref, _Ptr>&, const std::_Deque_iterator<_Tp, _RefR, _PtrR>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_deque.h|285|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_Deque_iterator<_Tp, _Ref, _Ptr>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_deque.h|278|note: candidate: template<class _Tp, class _Ref, class _Ptr> bool std::operator!=(const std::_Deque_iterator<_Tp, _Ref, _Ptr>&, const std::_Deque_iterator<_Tp, _Ref, _Ptr>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_deque.h|278|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::_Deque_iterator<_Tp, _Ref, _Ptr>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|6005|note: candidate: template<class _RealType> bool std::operator!=(const std::piecewise_linear_distribution<_RealType>&, const std::piecewise_linear_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|6005|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::piecewise_linear_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|5735|note: candidate: template<class _RealType> bool std::operator!=(const std::piecewise_constant_distribution<_RealType>&, const std::piecewise_constant_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|5735|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::piecewise_constant_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|5468|note: candidate: template<class _IntType> bool std::operator!=(const std::discrete_distribution<_IntType>&, const std::discrete_distribution<_IntType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|5468|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::discrete_distribution<_IntType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|5208|note: candidate: template<class _RealType> bool std::operator!=(const std::extreme_value_distribution<_RealType>&, const std::extreme_value_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|5208|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::extreme_value_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|5005|note: candidate: template<class _RealType> bool std::operator!=(const std::weibull_distribution<_RealType>&, const std::weibull_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|5005|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::weibull_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|4802|note: candidate: template<class _RealType> bool std::operator!=(const std::exponential_distribution<_RealType>&, const std::exponential_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|4802|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::exponential_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|4624|note: candidate: template<class _IntType> bool std::operator!=(const std::poisson_distribution<_IntType>&, const std::poisson_distribution<_IntType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|4624|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::poisson_distribution<_IntType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|4408|note: candidate: template<class _IntType> bool std::operator!=(const std::negative_binomial_distribution<_IntType>&, const std::negative_binomial_distribution<_IntType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|4408|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::negative_binomial_distribution<_IntType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|4163|note: candidate: template<class _IntType> bool std::operator!=(const std::geometric_distribution<_IntType>&, const std::geometric_distribution<_IntType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|4163|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::geometric_distribution<_IntType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3994|note: candidate: template<class _IntType> bool std::operator!=(const std::binomial_distribution<_IntType>&, const std::binomial_distribution<_IntType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3994|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::binomial_distribution<_IntType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3728|note: candidate: bool std::operator!=(const std::bernoulli_distribution&, const std::bernoulli_distribution&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3728|note:   no known conversion for argument 1 from 'std::vector<std::vector<int> >' to 'const std::bernoulli_distribution&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3552|note: candidate: template<class _RealType> bool std::operator!=(const std::student_t_distribution<_RealType>&, const std::student_t_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3552|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::student_t_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3339|note: candidate: template<class _RealType> bool std::operator!=(const std::fisher_f_distribution<_RealType>&, const std::fisher_f_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3339|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::fisher_f_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3083|note: candidate: template<class _RealType> bool std::operator!=(const std::cauchy_distribution<_RealType>&, const std::cauchy_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|3083|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::cauchy_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2916|note: candidate: template<class _RealType> bool std::operator!=(const std::chi_squared_distribution<_RealType>&, const std::chi_squared_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2916|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::chi_squared_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2706|note: candidate: template<class _RealType> bool std::operator!=(const std::gamma_distribution<_RealType>&, const std::gamma_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2706|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::gamma_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2486|note: candidate: template<class _RealType> bool std::operator!=(const std::lognormal_distribution<_RealType>&, const std::lognormal_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2486|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::lognormal_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2282|note: candidate: template<class _RealType> bool std::operator!=(const std::normal_distribution<_RealType>&, const std::normal_distribution<_RealType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2282|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::normal_distribution<_RealType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2033|note: candidate: template<class _IntType> bool std::operator!=(const std::uniform_real_distribution<_IntType>&, const std::uniform_real_distribution<_IntType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|2033|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::uniform_real_distribution<_IntType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|1824|note: candidate: template<class _IntType> bool std::operator!=(const std::uniform_int_distribution<_IntType>&, const std::uniform_int_distribution<_IntType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|1824|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::uniform_int_distribution<_IntType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|1509|note: candidate: template<class _RandomNumberEngine, unsigned int __k> bool std::operator!=(const std::shuffle_order_engine<_RandomNumberEngine, __k>&, const std::shuffle_order_engine<_RandomNumberEngine, __k>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|1509|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::shuffle_order_engine<_RandomNumberEngine, __k>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|1257|note: candidate: template<class _RandomNumberEngine, unsigned int __w, class _UIntType> bool std::operator!=(const std::independent_bits_engine<_RandomNumberEngine, __w, _UIntType>&, const std::independent_bits_engine<_RandomNumberEngine, __w, _UIntType>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|1257|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::independent_bits_engine<_RandomNumberEngine, __w, _UIntType>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|1061|note: candidate: template<class _RandomNumberEngine, unsigned int __p, unsigned int __r> bool std::operator!=(const std::discard_block_engine<_RandomNumberEngine, __p, __r>&, const std::discard_block_engine<_RandomNumberEngine, __p, __r>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|1061|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::discard_block_engine<_RandomNumberEngine, __p, __r>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|839|note: candidate: template<class _UIntType, unsigned int __w, unsigned int __s, unsigned int __r> bool std::operator!=(const std::subtract_with_carry_engine<_UIntType, __w, __s, __r>&, const std::subtract_with_carry_engine<_UIntType, __w, __s, __r>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|839|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::subtract_with_carry_engine<_UIntType, __w, __s, __r>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|643|note: candidate: template<class _UIntType, unsigned int __w, unsigned int __n, unsigned int __m, unsigned int __r, _UIntType __a, unsigned int __u, _UIntType __d, unsigned int __s, _UIntType __b, unsigned int __t, _UIntType __c, unsigned int __l, _UIntType __f> bool std::operator!=(const std::mersenne_twister_engine<_UIntType, __w, __n, __m, __r, __a, __u, __d, __s, __b, __t, __c, __l, __f>&, const std::mersenne_twister_engine<_UIntType, __w, __n, __m, __r, __a, __u, __d, __s, __b, __t, __c, __l, __f>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|643|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::mersenne_twister_engine<_UIntType, __w, __n, __m, __r, __a, __u, __d, __s, __b, __t, __c, __l, __f>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|411|note: candidate: template<class _UIntType, _UIntType __a, _UIntType __c, _UIntType __m> bool std::operator!=(const std::linear_congruential_engine<_UIntType, __a, __c, __m>&, const std::linear_congruential_engine<_UIntType, __a, __c, __m>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\random.h|411|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::linear_congruential_engine<_UIntType, __a, __c, __m>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|1535|note: candidate: template<class _Tp, class _Alloc> bool std::operator!=(const std::vector<_Tp, _Alloc>&, const std::vector<_Tp, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|1535|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   mismatched types 'const std::vector<_Tp, _Alloc>' and 'int'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\complex|486|note: candidate: template<class _Tp> constexpr bool std::operator!=(const _Tp&, const std::complex<_Tp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\complex|486|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   mismatched types 'const std::complex<_Tp>' and 'int'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\complex|481|note: candidate: template<class _Tp> constexpr bool std::operator!=(const std::complex<_Tp>&, const _Tp&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\complex|481|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::complex<_Tp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\complex|476|note: candidate: template<class _Tp> constexpr bool std::operator!=(const std::complex<_Tp>&, const std::complex<_Tp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\complex|476|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::complex<_Tp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\streambuf_iterator.h|210|note: candidate: template<class _CharT, class _Traits> bool std::operator!=(const std::istreambuf_iterator<_CharT, _Traits>&, const std::istreambuf_iterator<_CharT, _Traits>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\streambuf_iterator.h|210|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::istreambuf_iterator<_CharT, _Traits>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|323|note: candidate: bool std::operator!=(const std::error_condition&, const std::error_condition&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|323|note:   no known conversion for argument 1 from 'std::vector<std::vector<int> >' to 'const std::error_condition&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|319|note: candidate: bool std::operator!=(const std::error_condition&, const std::error_code&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|319|note:   no known conversion for argument 1 from 'std::vector<std::vector<int> >' to 'const std::error_condition&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|315|note: candidate: bool std::operator!=(const std::error_code&, const std::error_condition&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|315|note:   no known conversion for argument 1 from 'std::vector<std::vector<int> >' to 'const std::error_code&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|311|note: candidate: bool std::operator!=(const std::error_code&, const std::error_code&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\system_error|311|note:   no known conversion for argument 1 from 'std::vector<std::vector<int> >' to 'const std::error_code&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4969|note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator!=(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4969|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4957|note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator!=(const _CharT*, const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4957|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   mismatched types 'const _CharT*' and 'std::vector<std::vector<int> >'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4945|note: candidate: template<class _CharT, class _Traits, class _Alloc> bool std::operator!=(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\basic_string.h|4945|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\allocator.h|146|note: candidate: template<class _Tp> bool std::operator!=(const std::allocator<_CharT>&, const std::allocator<_CharT>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\allocator.h|146|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::allocator<_CharT>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\allocator.h|140|note: candidate: template<class _T1, class _T2> bool std::operator!=(const std::allocator<_CharT>&, const std::allocator<_T2>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\allocator.h|140|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::allocator<_CharT>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|1083|note: candidate: template<class _Iterator> bool std::operator!=(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iterator>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|1083|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::move_iterator<_Iterator>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|1077|note: candidate: template<class _IteratorL, class _IteratorR> bool std::operator!=(const std::move_iterator<_Iterator>&, const std::move_iterator<_IteratorR>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|1077|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::move_iterator<_Iterator>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|354|note: candidate: template<class _IteratorL, class _IteratorR> bool std::operator!=(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|354|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::reverse_iterator<_Iterator>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|304|note: candidate: template<class _Iterator> bool std::operator!=(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|304|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::reverse_iterator<_Iterator>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_pair.h|227|note: candidate: template<class _T1, class _T2> constexpr bool std::operator!=(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_pair.h|227|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::pair<_T1, _T2>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\postypes.h|221|note: candidate: template<class _StateT> bool std::operator!=(const std::fpos<_StateT>&, const std::fpos<_StateT>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\postypes.h|221|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const std::fpos<_StateT>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\ext\new_allocator.h|144|note: candidate: template<class _Tp> bool __gnu_cxx::operator!=(const __gnu_cxx::new_allocator<_Tp>&, const __gnu_cxx::new_allocator<_Tp>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\ext\new_allocator.h|144|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const __gnu_cxx::new_allocator<_Tp>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|841|note: candidate: template<class _Iterator, class _Container> bool __gnu_cxx::operator!=(const __gnu_cxx::__normal_iterator<_Iterator, _Container>&, const __gnu_cxx::__normal_iterator<_Iterator, _Container>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|841|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const __gnu_cxx::__normal_iterator<_Iterator, _Container>'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|834|note: candidate: template<class _IteratorL, class _IteratorR, class _Container> bool __gnu_cxx::operator!=(const __gnu_cxx::__normal_iterator<_IteratorL, _Container>&, const __gnu_cxx::__normal_iterator<_IteratorR, _Container>&)|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_iterator.h|834|note:   template argument deduction/substitution failed:|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|12|note:   'std::vector<std::vector<int> >' is not derived from 'const __gnu_cxx::__normal_iterator<_IteratorL, _Container>'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|13|error: cannot convert 'std::vector<std::vector<int> >' to 'int' in return|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|16|error: too many arguments to function 'int memorized(std::vector<int>&, std::vector<int>&, int, int)'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|10|note: declared here|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|16|error: too many arguments to function 'int memorized(std::vector<int>&, std::vector<int>&, int, int)'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|10|note: declared here|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|16|error: no match for 'operator=' (operand types are 'std::vector<std::vector<int> >' and 'const int')|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\vector.tcc|167|note: candidate: std::vector<_Tp, _Alloc>& std::vector<_Tp, _Alloc>::operator=(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\vector.tcc|167|note:   no known conversion for argument 1 from 'const int' to 'const std::vector<std::vector<int> >&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|448|note: candidate: std::vector<_Tp, _Alloc>& std::vector<_Tp, _Alloc>::operator=(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|448|note:   no known conversion for argument 1 from 'const int' to 'std::vector<std::vector<int> >&&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|470|note: candidate: std::vector<_Tp, _Alloc>& std::vector<_Tp, _Alloc>::operator=(std::initializer_list<_Tp>) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|470|note:   no known conversion for argument 1 from 'const int' to 'std::initializer_list<std::vector<int> >'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|17|error: cannot convert 'std::vector<std::vector<int> >' to 'int' in return|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|19|error: too many arguments to function 'int memorized(std::vector<int>&, std::vector<int>&, int, int)'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|10|note: declared here|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|19|error: no match for 'operator=' (operand types are 'std::vector<std::vector<int> >' and 'int')|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\vector.tcc|167|note: candidate: std::vector<_Tp, _Alloc>& std::vector<_Tp, _Alloc>::operator=(const std::vector<_Tp, _Alloc>&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\vector.tcc|167|note:   no known conversion for argument 1 from 'int' to 'const std::vector<std::vector<int> >&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|448|note: candidate: std::vector<_Tp, _Alloc>& std::vector<_Tp, _Alloc>::operator=(std::vector<_Tp, _Alloc>&&) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|448|note:   no known conversion for argument 1 from 'int' to 'std::vector<std::vector<int> >&&'|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|470|note: candidate: std::vector<_Tp, _Alloc>& std::vector<_Tp, _Alloc>::operator=(std::initializer_list<_Tp>) [with _Tp = std::vector<int>; _Alloc = std::allocator<std::vector<int> >]|
C:\Program Files (x86)\CodeBlocks\MinGW\lib\gcc\mingw32\5.1.0\include\c++\bits\stl_vector.h|470|note:   no known conversion for argument 1 from 'int' to 'std::initializer_list<std::vector<int> >'|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|20|error: cannot convert 'std::vector<std::vector<int> >' to 'int' in return|
||=== Build failed: 9 error(s), 0 warning(s) (0 minute(s), 20 second(s)) ===|

||=== Build file: "no target" in "no project" (compiler: unknown) ===|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp||In function 'int main()':|
E:\codechef and codeforces also leetcode\love babbar 450 questions\dynamic programming\dp 0-1 knapsack 01 memorized.cpp|43|error: cannot convert 'std::vector<std::vector<int> >' to 'void*' for argument '1' to 'void* memset(void*, int, size_t)'|
||=== Build failed: 1 error(s), 0 warning(s) (0 minute(s), 2 second(s)) ===|

*/
