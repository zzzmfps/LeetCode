// 31ms, 30.08%
class MinStack
{
private:
    vector<int> s1;
    vector<int> s2;
    
public:
    MinStack()
    {
    }
    
    void push(int x)
    {
        s1.push_back(x);
        if(s2.empty() || x <= s2.back()) s2.push_back(x);
    }
    
    void pop()
    {
        if(s2.back() == s1.back()) s2.pop_back();
        s1.pop_back();
    }
    
    int top()
    {
        return s1.back();
    }
    
    int getMin()
    {
        return s2.back();
    }
};
