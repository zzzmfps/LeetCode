// 2ms, 39.86%
class MyStack
{
private:
    queue<int> q;
    
public:
    MyStack()
    {   
    }
    
    void push(int x)
    {
        q.push(x);
    }
    
    int pop()
    {
        for(int i = 1; i < q.size(); ++i)
            q.push(q.front()), q.pop();
        int tmp = q.front();
        q.pop();
        return tmp;
    }
    
    int top()
    {
        int tmp = pop();
        q.push(tmp);
        return tmp;
    }
    
    bool empty()
    {
        return q.empty();
    }
};
